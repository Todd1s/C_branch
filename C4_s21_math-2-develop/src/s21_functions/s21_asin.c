#include "../s21_math.h"

long double s21_asin(double x) {
  if (x < -1.0 || x > 1.0) {
    //        printf("[-1, 1].\n");
    //    return -1.0;  // ошибка
    return S21_NAN;
  }

  double approx = x;
  double prev_approx = 0.0;

  while (s21_fabs(approx - prev_approx) > S21_EPS) {
    prev_approx = approx;
    approx = approx - (s21_sin(approx) - x) / s21_cos(approx);
  }

  return approx;
}
