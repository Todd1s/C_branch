#include "../s21_math.h"

long double s21_floor(double x) {
  //  if (x == S21_NAN) {
  //    return S21_NAN;
  //  }
  if (x != x) {
    return S21_NAN;
  } else if (x == S21_NEG_INF) {
    return S21_NEG_INF;
  } else if (x == S21_POS_INF) {
    return S21_POS_INF;
  }
  long long tmp = x;
  long double tmp2 = tmp;
  if (x < 0 && x != tmp2) {
    tmp2 -= 1;
  }
  return tmp2;
}
