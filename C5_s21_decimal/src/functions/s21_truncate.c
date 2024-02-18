#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  // Возвращает целые цифры указанного Decimal числа; любые дробные цифры
  // отбрасываются, включая конечные нули.
  *result = (s21_decimal){{0, 0, 0, 0}};
  int exp = get_exp(value);
  if (get_sign(value)) (*result).bits[3] = setBit((*result).bits[3], 31);
  for (int i = 0; i < 3 * 32; i++) {
    int bit = getBit(value.bits[i / 32], i % 32);
    if (bit) (*result).bits[i / 32] = setBit((*result).bits[i / 32], i % 32);
  }
  for (int i = 0; i < exp; i++) {
    div_by_10(*result, result, 0);
  }
  return 0;
}
