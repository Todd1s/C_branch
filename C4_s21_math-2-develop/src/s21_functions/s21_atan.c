
#include "../s21_math.h"

long double s21_atan(double x) {
  double temp = (double)s21_sqrt(1 + x * x);
  return s21_asin(x / temp);
}
