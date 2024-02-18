#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  if (value_1.bits[0] == value_2.bits[0] &&
      value_1.bits[1] == value_2.bits[1] &&
      value_1.bits[2] == value_2.bits[2] &&
      get_sign(value_1) == get_sign(value_2) &&
      get_exp(value_1) == get_exp(value_2)) {
    res = 1;
  }
  return res;
}