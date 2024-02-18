#include "../s21_math.h"

long double s21_sqrt(double x) {
  if (x == 0) {
    return 0;
  } else if (x < 0) {
    return S21_NAN;
  }
  long double a = 0;
  long double b = (x < 1) ? 1 : x;
  long double mid = 0;
  while (s21_fabs(b - a) > S21_EPS) {
    mid = a + (b - a) / 2;
    if ((mid * mid) > x) {
      b = mid;
    } else {
      a = mid;
    }
  }
  return mid;
}
