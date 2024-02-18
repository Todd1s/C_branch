#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  // Округляет Decimal до ближайшего целого числа.
  *result = (s21_decimal){{0, 0, 0, 0}};
  int exp = get_exp(value);
  if (get_sign(value)) (*result).bits[3] = setBit((*result).bits[3], 31);
  for (int i = 0; i < 3 * 32; i++) {
    int bit = getBit(value.bits[i / 32], i % 32);
    if (bit) (*result).bits[i / 32] = setBit((*result).bits[i / 32], i % 32);
  }
  int remainder = 0;
  for (int i = 0; i < exp; i++) {
    remainder = div_by_10(*result, result, 0);
  }
  if (remainder == 5 && getBit(result->bits[0], 0)) {
    s21_decimal one = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};  // 1
    if (get_sign(value))
      s21_sub(*result, one, result);
    else
      s21_add(*result, one, result);
  }
  if (remainder > 5) {
    s21_decimal one = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};  // 1
    if (get_sign(value))
      s21_sub(*result, one, result);
    else
      s21_add(*result, one, result);
  }
  return 0;
}