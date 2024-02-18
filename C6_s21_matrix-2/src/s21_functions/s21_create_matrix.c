#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || rows <= 0 || columns <= 0) {
    return error;
  }
  int res = ok;
  int tmp = rows;
  int tmp1 = columns;
  result->rows = tmp;
  result->columns = tmp1;
  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL) {
    res = error;
  } else {
    for (int i = 0; i < rows && res != error; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        s21_remove_matrix(result), res = error;
      }
    }
  }
  return res;
}