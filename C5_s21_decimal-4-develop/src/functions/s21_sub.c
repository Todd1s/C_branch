#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  *result = (s21_decimal){{0, 0, 0, 0}};
  equal_exponents(&value_1, &value_2);
  if (get_sign(value_1) == get_sign(value_2)) {
    if (get_sign(value_1)) {
      if ((s21_is_less_or_equal(value_1, value_2))) {
        basic_sub(value_1, value_2, result, &res);
      } else {
        basic_sub(value_2, value_1, result, &res);
        (*result).bits[3] = toggleBit((*result).bits[3], 31);
      }
    } else {
      if ((s21_is_greater_or_equal(value_1, value_2))) {
        basic_sub(value_1, value_2, result, &res);
      } else {
        basic_sub(value_2, value_1, result, &res);
        (*result).bits[3] = toggleBit((*result).bits[3], 31);
      }
    }
  } else {
    if (get_sign(value_1) > get_sign(value_2)) {
      value_1.bits[3] = setBit(value_2.bits[3], 31);
    } else {
      value_2.bits[3] = setBit(value_1.bits[3], 31);
    }
    basic_add(value_1, value_2, result, &res);
  }
  return res;
}
