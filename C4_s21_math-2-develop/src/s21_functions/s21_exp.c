#include "../s21_math.h"

long double s21_exp(double x) {
  //  if (x >= 1000) return 1.0 / 0.0;
  if (x == S21_POS_INF) return S21_POS_INF;
  if (x == S21_NEG_INF || (x <= -14.5)) return 0;
  if (x >= 1000) return S21_POS_INF;
  long double fact = 1;
  long double exp = 1;
  for (int i = 1; i < 400; i++) {
    fact *= x / i;
    exp += fact;
  }
  return exp;
}
