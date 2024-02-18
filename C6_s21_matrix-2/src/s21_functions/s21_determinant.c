#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || A->matrix == NULL || A->columns <= 0 || A->rows <= 0) {
    return error;
  } else if (A->columns != A->rows) {
    return calculation_error;
  }

  int res = ok;

  int rows = A->rows;
  int columns = rows;
  double det = 0.0;
  matrix_t minor = {0};
  switch (rows) {
    case 1:
      *result = A->matrix[0][0];
      break;
    case 2:
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
      break;
    default:

      s21_create_matrix(rows - 1, columns - 1, &minor);
      for (int i = 0; i < columns; i++) {
        double sub_det = 0.0;
        s21_get_minor(A, &minor, 0, i);
        if (s21_determinant(&minor, &sub_det) == 0) {
          det += (i % 2 == 0 ? 1 : -1) * sub_det * A->matrix[0][i];
        } else {
          s21_remove_matrix(&minor);
          res = calculation_error;
        }
      }
      s21_round(det);
      // printf("%.0lf ", det);
      // printf("\n");
      s21_remove_matrix(&minor);
      *result = det;
  }
  return res;
}
