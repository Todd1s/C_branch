#include "../s21_math.h"

long double s21_sin(double x) {
  int xsign = 1;
  if (x < 0) {
    x *= -1;
    xsign = -1;
  }
  while (x >= 2 * PI) x -= 2 * PI;
  if (x <= PI) {
    xsign *= 1;
  } else {
    xsign *= -1;
  }
  while (x >= PI) x -= PI;
  int measurementerror = 17;  // Change for better accuracy ( no mozet slomatbsy
                              // pri perepolnenii tak chto accuratno)
  int countererror = 1;
  int sign = -1;
  long double sin = x;
  while (countererror < measurementerror) {
    countererror += 2;
    sin += sign * s21_pow(x, countererror) /
           s21_factorial(countererror);  // Tut dolzen bitb tvoi pow
    sign *= -1;
  }
  return xsign * sin;
}
