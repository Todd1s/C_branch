
#include "../s21_math.h"

long double s21_log(double x) {
  if (x == S21_POS_INF) {
    return S21_POS_INF;
  }

  if (x == S21_NEG_INF) {
    return S21_NAN;
  }

  if (x != x) {
    return S21_NAN;
  }

  if (x < 0) {
    //        return -1/0;
    return S21_NAN;
  }
  if (x == 0) {
    return S21_NEG_INF;
  }
  long double res = 0;
  double integralPart = 0.0, currentX = x, previousIntegralPart = 0;
  long double approximateExponent = 2.718281828459045;

  // Приближенно находим целую часть логарифма.
  while (currentX >= approximateExponent) {
    currentX /= approximateExponent;
    integralPart++;
  }
  integralPart += (currentX / approximateExponent);

  currentX = x;

  int status = 1;
  // Перебираем приближения для дробной части логарифма.
  for (int iteration = 0; iteration < 20 && status; iteration++) {
    double leftValue, rightValue;
    previousIntegralPart = integralPart;
    leftValue = (currentX / (s21_exp(integralPart - 1.0)));
    rightValue = ((integralPart - 1.0) * approximateExponent);
    integralPart = ((leftValue + rightValue) / approximateExponent);
    if (integralPart == previousIntegralPart) {
      status = 0;
    }
  }  // Повторяем, пока не достигнута точность или не сделано максимальное
     // количество итераций.

  res = integralPart;

  return res;
}
