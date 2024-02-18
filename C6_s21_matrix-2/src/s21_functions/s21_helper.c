#include "../s21_matrix.h"

int s21_fill_matrix(matrix_t *A) {
  double k = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = k * 1.1;

      k++;
    }
  }

  return 0;
}

int s21_get_minor(matrix_t *A, matrix_t *result, int row_number,
                  int column_number) {
  int x = 0;
  for (int i = 0; i < A->rows; i++) {
    int y = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j != column_number && i != row_number) {
        result->matrix[x][y] = A->matrix[i][j];
        y++;
      }
    }
    (i != row_number ? x++ : x);
  }
  return 0;
}

int s21_copy_matrix(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j];
    }
  }
  return 0;
}

int s21_custom_fill_matrix(matrix_t *A, double values[]) {
  int k = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = values[k];

      k++;
    }
  }

  return 0;
}

double s21_round(double num) {
  double tmp1 = num * pow(10.0, 6);
  tmp1 = round(tmp1);
  return tmp1 / pow(10.0, 6);
}