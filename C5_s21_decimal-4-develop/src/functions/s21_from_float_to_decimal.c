#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int esc = 1;
  *dst = (s21_decimal){0};

  if (!isinf(src) && !isnan(src) && (src != 0)) {
    s21_float_bits converter = {0};
    converter.floa_t = src;

    int sign = converter.uin_t >> 31;

    int exp_float = ((converter.uin_t & 0x7F800000) >> 23) - 127;

    double temp = (double)fabs(src);

    int exp = 0;
    while ((int)temp / 1000000 == 0 && exp < 28) {
      temp *= 10;
      exp++;
    }
    temp = round(temp);
    temp = (float)temp;

    while (fmod(temp, 10) == 0 && exp > 0) {
      temp /= 10;
      exp--;
    }

    s21_float_bits mantissa = {0};
    mantissa.floa_t = temp;
    exp_float = ((mantissa.uin_t & ~0x80000000) >> 23) - 127;

    dst->bits[exp_float / 32] |= 1 << exp_float % 32;

    for (int i = exp_float - 1, j = 22; j >= 0; i--, j--)
      if ((mantissa.uin_t & (1 << j)) != 0) dst->bits[i / 32] |= 1 << i % 32;

    dst->bits[3] = (sign << 31) | (exp << 16);

    esc = 0;
  }
  return esc;
}
