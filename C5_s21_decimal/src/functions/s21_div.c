#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  if (is_zero(value_2)) {
    res = 3;
  } else {
    *result = (s21_decimal){{0, 0, 0, 0}};
    if (!is_zero(value_1)) {
      while (s21_is_less(
          (s21_decimal){{value_1.bits[0], value_1.bits[1], value_1.bits[2], 0}},
          (s21_decimal){
              {value_2.bits[0], value_2.bits[1], value_2.bits[2], 0}})) {
        increase_exponent(&value_1);
      }
      int cur_sgn = getBit(get_sign(value_1) + get_sign(value_2), 0);
      int cur_exp = remainder_div(value_1, value_2, result);
      result->bits[3] |= ((unsigned)cur_sgn << 31 | cur_exp << 16);
      if (cur_exp < 0) {
        res = 1 + cur_sgn;
      }
    }
  }
  return res;
}