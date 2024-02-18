
#include "../s21_math.h"

long double s21_ceil(double x) {
  if (isPOS_INF(x) || isNEG_INF(x) || x == 0 || x != x) {
    return x;
  }
  long double resultat = (long long int)x;
  if (s21_fabs(x) > 0. && x != resultat)
    if (x > 0.) {
      resultat += 1;
    }
  return resultat;
}
