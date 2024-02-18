#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL ||
      A->columns <= 0 || A->rows <= 0 || B->columns <= 0 || B->rows <= 0) {
    return FAILURE;
  } else if ((A->columns != B->columns) || (A->rows != B->rows)) {
    return FAILURE;
  }

  int res = SUCCESS;

  if (res == SUCCESS) {
    for (int i = 0; i < A->rows && res != FAILURE; i++) {
      for (int j = 0; j < A->columns && res != FAILURE; j++) {
        res = (s21_round(A->matrix[i][j]) != s21_round(B->matrix[i][j])
                   ? FAILURE
                   : SUCCESS);
      }
    }
  }
  return res;
}