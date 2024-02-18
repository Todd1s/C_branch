#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  nulify_dec(dst);
  if (src & ((unsigned)1 << 31)) {
    dst->bits[3] |= ((unsigned)1 << 31);
    dst->bits[0] |= ~src + 1;
  } else {
    dst->bits[0] = src;
  }
  return 0;
}