#include "../s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal value_1_big, value_2_big;

  decimal_to_big_decimal(value_1, &value_1_big);
  decimal_to_big_decimal(value_2, &value_2_big);

  normalize_big(&value_1_big, &value_2_big);

  int res = 0;
  if (is_zero(value_1) && is_zero(value_2)) {
    res = 0;
  } else if (get_sign(value_1) < get_sign(value_2)) {
    res = 1;
  } else if (get_sign(value_1) > get_sign(value_2)) {
    res = 0;
  } else if (s21_is_equal(value_1, value_2)) {
    res = 0;
  } else {
    for (int i = 191; i >= 0; i--) {
      if (getBit(value_1_big.bits[i / 32], i % 32) >
          getBit(value_2_big.bits[i / 32], i % 32)) {
        res = 1;
        break;
      } else if (getBit(value_1_big.bits[i / 32], i % 32) <
                 getBit(value_2_big.bits[i / 32], i % 32)) {
        res = 0;
        break;
      }
    }
    if (get_sign(value_1) && get_sign(value_2)) res = res ? 0 : 1;
  }
  return res;
}