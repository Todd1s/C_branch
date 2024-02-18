
#include "../s21_math.h"

long double s21_cos(double x) {
  int xsign = 1;
  if (x < 0) {
    x *= -1;
  }
  while (x >= 2 * PI) x -= 2 * PI;
  if (x > PI / 2 && x < 3 * PI / 2) {
    if (x >= PI) {
      long double temp = x - PI;
      x = PI - temp;
    }
  }
  if (x < PI || x >= 3 * PI / 2) {
    if (x >= 3 * PI / 2) {
      long double temp2 = 2 * PI - x;
      x = temp2;
    }
  }
  int measurementerror = 19;  // Change for better accuracy ( no mozet slomatbsy
                              // pri perepolnenii tak chto accuratno)
  int countererror = 0;
  int sign = -1;
  long double cos = 1;
  while (countererror < measurementerror) {
    countererror += 2;
    cos += sign * s21_pow(x, countererror) /
           s21_factorial(countererror);  // Tut dolzen bitb tvoi pow
    sign *= -1;
  }
  return xsign * cos;  // suda b ceil huinutb do 10 stepeni hotya b
}
