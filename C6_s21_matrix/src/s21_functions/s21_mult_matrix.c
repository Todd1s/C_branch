#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL || A->matrix == NULL ||
      B->matrix == NULL || A->columns <= 0 || A->rows <= 0 || B->columns <= 0 ||
      B->rows <= 0) {
    return error;
  } else if (A->columns != B->rows) {
    return calculation_error;
  }

  int res = ok;

  s21_create_matrix(A->rows, B->columns, result);

  if (res == ok) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int n = 0; n < B->rows; n++) {
          result->matrix[i][j] += A->matrix[i][n] * B->matrix[n][j];
          s21_round(result->matrix[i][j]);
        }
      }
    }
  }
  return res;
}