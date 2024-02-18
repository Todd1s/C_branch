#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;

  int bits = overflow_check(value_1, value_2);

  int a = get_exp(value_1);
  int b = get_exp(value_2);
  int cur_exp = (a + b);

  int cur_sgn = (getBit(get_sign(value_1) + get_sign(value_2), 0));

  if (bits < 96) {
    basic_mul(value_1, value_2, result);
  } else {
    cur_exp -= long_mul(value_1, value_2, result);
  }
  (*result).bits[3] = (cur_exp << 16 | (unsigned)cur_sgn << 31);
  while (get_exp(*result) > 28) {
    decrease_exponent(result);
    if (is_zero(*result) && get_exp(*result) != 28) {
      res = 1 + cur_sgn;
    }
  }
  return res;
}