#include "../s21_math.h"

long long s21_factorial(int x) {
  if (x == 1) return x;
  return x * s21_factorial(x - 1);
}
