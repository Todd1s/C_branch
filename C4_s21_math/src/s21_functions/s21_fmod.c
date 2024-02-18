
#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  if ((x == 0 && y == 0) || (y == 0) || (y == S21_NAN) ||
      (x == S21_POS_INF || x == S21_NEG_INF)) {
    return S21_NAN;
  }
  long long mod = 0;
  mod = x / y;
  long double res = (long double)x - mod * (long double)y;
  return res;
}
