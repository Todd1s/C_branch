#include "../s21_math.h"

int s21_abs(int var) {
  if (var < 0) {
    var *= -1;
  }
  return var;
}
