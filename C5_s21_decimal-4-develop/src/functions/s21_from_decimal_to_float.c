#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = src.bits[2];
  *dst *= pow(10, count_digits(src.bits[2]));
  *dst += src.bits[1];
  *dst *= pow(10, count_digits(src.bits[1]));
  *dst += src.bits[0];
  *dst /= pow(10, get_exp(src));
  if (get_sign(src)) *dst *= -1;
  return 0;
}