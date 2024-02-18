#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A == NULL || result == NULL || A->matrix == NULL || A->columns <= 0 ||
      A->rows <= 0) {
    return error;
  }
  int res = ok;

  s21_create_matrix(A->rows, A->columns, result);

  if (res == ok) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
        s21_round(result->matrix[i][j]);
      }
    }
  }
  return res;
}