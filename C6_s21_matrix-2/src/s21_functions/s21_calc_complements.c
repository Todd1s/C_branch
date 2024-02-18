#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL || A->matrix == NULL || A->columns <= 0 ||
      A->rows <= 0) {
    return error;
  } else if (A->columns != A->rows) {
    return calculation_error;
  }
  int res = ok;
  int rows = A->rows;
  int columns = rows;
  s21_create_matrix(rows, columns, result);
  matrix_t minor = {0};
  if (A->rows == 1) {
    result->matrix[0][0] = 1;
  } else {
    s21_create_matrix(rows - 1, columns - 1, &minor);
    for (int i = 0; i < A->rows && res == ok; i++) {
      for (int j = 0; j < A->columns && res == ok; j++) {
        double sub_det = 0.0;
        s21_get_minor(A, &minor, i, j);
        if (s21_determinant(&minor, &sub_det) == 0) {
          result->matrix[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * sub_det;
          s21_round(result->matrix[i][j]);
        } else {
          s21_remove_matrix(&minor);
          res = calculation_error;
        }
      }
    }

    s21_remove_matrix(&minor);
  }

  return res;
}