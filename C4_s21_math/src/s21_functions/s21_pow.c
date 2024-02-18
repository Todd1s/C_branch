#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  if (((isNAN(base) && exp != 0) || isNAN(exp)) ||
      (base < 0 && s21_floor(exp) != exp)) {
    return S21_NAN;
  } else if (base == -1 || base == 1 || (base == 0 && exp == 0) ||
             (isNAN(base) && exp == 0) || (exp == 0)) {
    return 1.0;
  } else if (base == 0 && exp < 0) {
    return S21_POS_INF;
  } else if (base < 0 && isNEG_INF(exp)) {
    return S21_POS_INF;
  } else if (base == 0) {
    return 0;
  }

  long double res = 0;
  if (base < 0) {
    base = -base;
    res = s21_exp(exp * s21_log(base));
    if (s21_fmod(exp, 2) != 0) {
      res = -res;
    }
  } else {
    res = s21_exp(exp * s21_log(base));
  }
  return res;
}
