#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  // Возвращает результат умножения указанного Decimal на -1.
  *result = (s21_decimal){{0, 0, 0, 0}};
  if (get_sign(value))
    (*result).bits[3] = clearBit(((*result).bits[3]), 31);
  else
    (*result).bits[3] = setBit(((*result).bits[3]), 31);
  for (int i = 0; i < (4 * 32) - 1; i++) {
    int bit = getBit(value.bits[i / 32], i % 32);
    if (bit) (*result).bits[i / 32] = setBit((*result).bits[i / 32], i % 32);
  }

  return 0;
}