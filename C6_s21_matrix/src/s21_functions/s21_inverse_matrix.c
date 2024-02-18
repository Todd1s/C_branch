#include "../s21_matrix.h"
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL || A->matrix == NULL || A->columns <= 0 ||
      A->rows <= 0) {
    return error;
  } else if (A->columns != A->rows) {
    return calculation_error;
  }

  int res = ok;

  if (res != calculation_error) {
    double det = 0.0;
    s21_determinant(A, &det);
    if (det == 0) {
      res = calculation_error;
    } else {
      s21_create_matrix(A->rows, A->columns, result);
      matrix_t tmp = {0};
      s21_transpose(A, &tmp);
      matrix_t tmp1 = {0};
      s21_calc_complements(&tmp, &tmp1);
      s21_remove_matrix(&tmp);
      matrix_t tmp2 = {0};
      s21_mult_number(&tmp1, (1 / det), &tmp2);
      s21_remove_matrix(&tmp1);
      s21_copy_matrix(&tmp2, result);
      s21_remove_matrix(&tmp2);
    }
  }

  return res;
}