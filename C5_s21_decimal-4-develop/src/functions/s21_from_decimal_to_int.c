#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int ret = 0;
  while (get_exp(src)) {
    decrease_exponent(&src);
  }
  if (src.bits[0] & ((unsigned)1 << 31) || src.bits[1] ||
      src.bits[1] & ((unsigned)1 << 31) || src.bits[2] ||
      src.bits[2] & ((unsigned)1 << 31)) {
    ret = 1;
  } else {
    *dst = src.bits[0];
    if (get_sign(src)) {
      *dst *= -1;
    }
  }
  return ret;
}