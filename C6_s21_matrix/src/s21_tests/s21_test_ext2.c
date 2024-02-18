#include <check.h>

#include "./s21_matrix.h"

void s21_fill2_matrix(matrix_t *A, double num) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; num++, j++) A->matrix[i][j] = num;
  }
}

START_TEST(s21_create_matrix_1) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(1, 2, &A);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(2, 1, &A);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(50, 100, &A);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_6) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_create_matrix_7) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(1, 0, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_create_matrix_8) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(0, 1, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_create_matrix_9) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(-1, -1, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_create_matrix_10) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(1, -1, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_create_matrix_11) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(-1, 1, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_remove_matrix_1) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(1, 10, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_remove_matrix_3) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_remove_matrix_4) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(2, 4, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_remove_matrix_5) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(4, 1, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_remove_matrix_6) {
  matrix_t A;
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double **)malloc(A.rows * sizeof(double *));
  for (int i = 0; i < A.rows; i++) {
    A.matrix[i] = (double *)malloc(A.columns * sizeof(double));
  }
  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_7) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;

  s21_remove_matrix(&A);

  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_8) {
  matrix_t *A = NULL;
  s21_remove_matrix(A);
  ck_assert_ptr_eq(A, NULL);
}
END_TEST

START_TEST(s21_remove_matrix_9) {
  matrix_t A;
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double **)malloc(A.rows * sizeof(double *));
  for (int i = 0; i < A.rows; i++) {
    A.matrix[i] = (double *)malloc(A.columns * sizeof(double));
  }

  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);

  for (int i = 0; i < A.rows; i++) {
    ck_assert_ptr_eq(A.matrix[i], NULL);
  }
}
END_TEST

START_TEST(s21_eq_matrix_1) {
  int res = 0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 1);
  s21_create_matrix(3, 3, &B);
  s21_fill2_matrix(&B, 1);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  int res = 0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 1);
  s21_create_matrix(3, 3, &B);
  s21_fill2_matrix(&B, 3);
  res = s21_eq_matrix(&B, &A);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  int res = 0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 2, &A);
  s21_fill2_matrix(&A, -1);
  s21_create_matrix(3, 2, &B);
  s21_fill2_matrix(&B, 1);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  int res = 0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 50);
  s21_create_matrix(3, 3, &B);
  s21_fill2_matrix(&B, -50);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  int res = 0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 4);
  s21_create_matrix(2, 3, &B);
  s21_fill2_matrix(&B, 2);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  int res = 0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 10, &A);
  s21_fill2_matrix(&A, 1);
  s21_create_matrix(10, 10, &B);
  s21_fill2_matrix(&B, 1);
  res = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_eq_matrix_7) {
  matrix_t A;
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double **)malloc(A.rows * sizeof(double *));
  for (int i = 0; i < A.rows; i++) {
    A.matrix[i] = (double *)malloc(A.columns * sizeof(double));
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i * A.columns + j;
    }
  }

  matrix_t B;
  B.rows = 3;
  B.columns = 3;
  B.matrix = (double **)malloc(B.rows * sizeof(double *));
  for (int i = 0; i < B.rows; i++) {
    B.matrix[i] = (double *)malloc(B.columns * sizeof(double));
    memcpy(B.matrix[i], A.matrix[i], B.columns * sizeof(double));
  }

  int result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_8) {
  matrix_t A;
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double **)malloc(A.rows * sizeof(double *));
  for (int i = 0; i < A.rows; i++) {
    A.matrix[i] = (double *)malloc(A.columns * sizeof(double));
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i * A.columns + j;
    }
  }

  matrix_t B;
  B.rows = 3;
  B.columns = 3;
  B.matrix = (double **)malloc(B.rows * sizeof(double *));
  for (int i = 0; i < B.rows; i++) {
    B.matrix[i] = (double *)malloc(B.columns * sizeof(double));
    memcpy(B.matrix[i], A.matrix[i], B.columns * sizeof(double));
  }

  B.matrix[1][1] = 42.0;

  int result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_1) {
  int res = 0;
  matrix_t A, B, C, D;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 1);
  s21_create_matrix(3, 3, &B);
  s21_fill2_matrix(&B, 3);
  s21_sum_matrix(&A, &B, &C);
  s21_create_matrix(3, 3, &D);
  D.matrix[0][0] = 4;
  D.matrix[0][1] = 6;
  D.matrix[0][2] = 8;
  D.matrix[1][0] = 10;
  D.matrix[1][1] = 12;
  D.matrix[1][2] = 14;
  D.matrix[2][0] = 16;
  D.matrix[2][1] = 18;
  D.matrix[2][2] = 20;
  res = s21_eq_matrix(&D, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t A, B, C, D;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 1);
  s21_create_matrix(3, 3, &B);
  s21_fill2_matrix(&B, 3);
  s21_sum_matrix(&A, &B, &C);
  s21_create_matrix(3, 3, &D);
  s21_fill2_matrix(&D, 4);
  int status = s21_eq_matrix(&D, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);

  ck_assert_int_eq(status, FAILURE);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  int res = 0;
  matrix_t A, B, C, D;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, -1);
  s21_create_matrix(3, 3, &B);
  s21_fill2_matrix(&B, 3);
  s21_sum_matrix(&A, &B, &C);
  s21_create_matrix(3, 3, &D);
  D.matrix[0][0] = 2;
  D.matrix[0][1] = 4;
  D.matrix[0][2] = 6;
  D.matrix[1][0] = 8;
  D.matrix[1][1] = 10;
  D.matrix[1][2] = 12;
  D.matrix[2][0] = 14;
  D.matrix[2][1] = 16;
  D.matrix[2][2] = 18;
  res = s21_eq_matrix(&D, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  int res = 0;
  matrix_t A, B, C, D;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 1);
  s21_create_matrix(3, 3, &B);
  s21_fill2_matrix(&B, -3);
  s21_sum_matrix(&A, &B, &C);
  s21_create_matrix(3, 3, &D);
  D.matrix[0][0] = -2;
  D.matrix[0][1] = 0;
  D.matrix[0][2] = 2;
  D.matrix[1][0] = 4;
  D.matrix[1][1] = 6;
  D.matrix[1][2] = 8;
  D.matrix[2][0] = 10;
  D.matrix[2][1] = 12;
  D.matrix[2][2] = 14;
  res = s21_eq_matrix(&D, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
  int res = 0;
  matrix_t A, B, C;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  res = s21_sum_matrix(&A, &B, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(s21_sum_matrix_6) {
  int rows1 = 2, cols1 = 3;
  int rows2 = 2, cols2 = 3;
  matrix_t A = {0}, result = {0}, B = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows2, cols2, &B);
  A.matrix[0][0] = 695.0;
  A.matrix[0][1] = 930.0;
  A.matrix[0][2] = 363.0;
  A.matrix[1][0] = -60.0;
  A.matrix[1][1] = 842.0;
  A.matrix[1][2] = -291.0;
  B.matrix[0][0] = -61.0;
  B.matrix[0][1] = -91.0;
  B.matrix[0][2] = -94.0;
  B.matrix[1][0] = -10.0;
  B.matrix[1][1] = 17.0;
  B.matrix[1][2] = 71.0;
  int status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(A.columns, result.columns);
  ck_assert_int_eq(B.rows, result.rows);
  ck_assert_double_eq_tol(result.matrix[0][0], 634.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], 839.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], 269.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], -70.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 859.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][2], -220.0, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_7) {
  int rows1 = 1, cols1 = 5;
  int rows2 = 1, cols2 = 5;
  matrix_t A = {0}, result = {0}, B = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows2, cols2, &B);
  A.matrix[0][0] = -7.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 0.0;
  A.matrix[0][3] = -1.0;
  A.matrix[0][4] = 1.0;
  B.matrix[0][0] = 52.0;
  B.matrix[0][1] = -68.0;
  B.matrix[0][2] = -42.0;
  B.matrix[0][3] = -14.0;
  B.matrix[0][4] = -17.0;
  int status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(A.columns, result.columns);
  ck_assert_int_eq(B.rows, result.rows);
  ck_assert_double_eq_tol(result.matrix[0][0], 45.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], -63.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], -42.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][3], -15.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][4], -16.0, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_8) {
  int rows1 = 2, cols1 = 5;
  int rows2 = 2, cols2 = 5;
  matrix_t A = {0}, result = {0}, B = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows2, cols2, &B);
  A.matrix[0][0] = -8.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = -9.0;
  A.matrix[0][3] = 10.0;
  A.matrix[0][4] = 5.0;
  A.matrix[1][0] = -1.0;
  A.matrix[1][1] = 7.0;
  A.matrix[1][2] = 7.0;
  A.matrix[1][3] = -8.0;
  A.matrix[1][4] = -7.0;
  B.matrix[0][0] = -2.0;
  B.matrix[0][1] = 63.0;
  B.matrix[0][2] = 43.0;
  B.matrix[0][3] = 61.0;
  B.matrix[0][4] = 91.0;
  B.matrix[1][0] = -85.0;
  B.matrix[1][1] = 78.0;
  B.matrix[1][2] = -94.0;
  B.matrix[1][3] = 95.0;
  B.matrix[1][4] = -57.0;
  int status = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(A.columns, result.columns);
  ck_assert_int_eq(B.rows, result.rows);
  ck_assert_double_eq_tol(result.matrix[0][0], -10.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], 65.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], 34.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][3], 71.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][4], 96.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], -86.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 85.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][2], -87.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][3], 87.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][4], -64.0, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_1) {
  int res = 0;
  matrix_t A, B, C, D;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 1);
  s21_create_matrix(3, 3, &B);
  s21_fill2_matrix(&B, 3);
  s21_sub_matrix(&A, &B, &C);
  s21_create_matrix(3, 3, &D);
  D.matrix[0][0] = -2;
  D.matrix[0][1] = -2;
  D.matrix[0][2] = -2;
  D.matrix[1][0] = -2;
  D.matrix[1][1] = -2;
  D.matrix[1][2] = -2;
  D.matrix[2][0] = -2;
  D.matrix[2][1] = -2;
  D.matrix[2][2] = -2;
  res = s21_eq_matrix(&D, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  matrix_t A, B, C, D;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 1);
  s21_create_matrix(3, 3, &B);
  s21_fill2_matrix(&B, 3);
  s21_sub_matrix(&A, &B, &C);
  s21_create_matrix(3, 3, &D);
  s21_fill2_matrix(&D, 4);
  int status = s21_eq_matrix(&D, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
  ck_assert_int_eq(status, FAILURE);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  int res = 0;
  matrix_t A, B, C, D;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, -1);
  s21_create_matrix(3, 3, &B);
  s21_fill2_matrix(&B, 3);
  s21_sub_matrix(&A, &B, &C);
  s21_create_matrix(3, 3, &D);
  D.matrix[0][0] = -4;
  D.matrix[0][1] = -4;
  D.matrix[0][2] = -4;
  D.matrix[1][0] = -4;
  D.matrix[1][1] = -4;
  D.matrix[1][2] = -4;
  D.matrix[2][0] = -4;
  D.matrix[2][1] = -4;
  D.matrix[2][2] = -4;
  res = s21_eq_matrix(&D, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_sub_matrix_4) {
  int res = 0;
  matrix_t A, B, C, D;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 1);
  s21_create_matrix(3, 3, &B);
  s21_fill2_matrix(&B, -3);
  s21_sub_matrix(&A, &B, &C);
  s21_create_matrix(3, 3, &D);
  D.matrix[0][0] = 4;
  D.matrix[0][1] = 4;
  D.matrix[0][2] = 4;
  D.matrix[1][0] = 4;
  D.matrix[1][1] = 4;
  D.matrix[1][2] = 4;
  D.matrix[2][0] = 4;
  D.matrix[2][1] = 4;
  D.matrix[2][2] = 4;
  res = s21_eq_matrix(&D, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_sub_matrix_5) {
  int res = 0;
  matrix_t A, B, C;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  res = s21_sub_matrix(&A, &B, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(s21_sub_matrix_6) {
  int rows1 = 2, cols1 = 3;
  int rows2 = 2, cols2 = 3;
  matrix_t A = {0}, result = {0}, B = {0};
  s21_create_matrix(rows1, cols1, &A);
  s21_create_matrix(rows2, cols2, &B);
  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 9.0;
  A.matrix[0][2] = -1.0;
  A.matrix[1][0] = -2.0;
  A.matrix[1][1] = -3.0;
  A.matrix[1][2] = -4.0;
  B.matrix[0][0] = -4.0;
  B.matrix[0][1] = -9.0;
  B.matrix[0][2] = 5.0;
  B.matrix[1][0] = -2.0;
  B.matrix[1][1] = -8.0;
  B.matrix[1][2] = 7.0;
  int status = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(A.columns, result.columns);
  ck_assert_int_eq(B.rows, result.rows);
  ck_assert_double_eq_tol(result.matrix[0][0], 4.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][1], 18.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[0][2], -6.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][0], 0.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][1], 5.0, 0.0000001);
  ck_assert_double_eq_tol(result.matrix[1][2], -11.0, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_1) {
  int res = 0;
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 1);
  s21_mult_number(&A, 3, &B);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 3;
  C.matrix[0][1] = 6;
  C.matrix[0][2] = 9;
  C.matrix[1][0] = 12;
  C.matrix[1][1] = 15;
  C.matrix[1][2] = 18;
  C.matrix[2][0] = 21;
  C.matrix[2][1] = 24;
  C.matrix[2][2] = 27;
  res = s21_eq_matrix(&B, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_2) {
  int res = 0;
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 1);
  s21_mult_number(&A, -3, &B);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = -3;
  C.matrix[0][1] = -6;
  C.matrix[0][2] = -9;
  C.matrix[1][0] = -12;
  C.matrix[1][1] = -15;
  C.matrix[1][2] = -18;
  C.matrix[2][0] = -21;
  C.matrix[2][1] = -24;
  C.matrix[2][2] = -27;
  res = s21_eq_matrix(&B, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_3) {
  int res = 0;
  matrix_t A, B, C;
  s21_create_matrix(4, 3, &A);
  s21_fill2_matrix(&A, 1);
  s21_mult_number(&A, -3, &B);
  s21_create_matrix(4, 3, &C);
  C.matrix[0][0] = -3;
  C.matrix[0][1] = -6;
  C.matrix[0][2] = -9;
  C.matrix[1][0] = -12;
  C.matrix[1][1] = -15;
  C.matrix[1][2] = -18;
  C.matrix[2][0] = -21;
  C.matrix[2][1] = -24;
  C.matrix[2][2] = -27;
  C.matrix[3][0] = -30;
  C.matrix[3][1] = -33;
  C.matrix[3][2] = -36;
  res = s21_eq_matrix(&B, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_4) {
  int res = 0;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(0, 0, &A);
  res = s21_mult_number(&A, 2, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_matrix_1) {
  int res = 0;
  matrix_t A = {0}, B = {0}, C = {0}, D = {0};
  s21_create_matrix(4, 4, &A);
  s21_fill2_matrix(&A, 1);
  s21_create_matrix(4, 4, &B);
  s21_fill2_matrix(&B, 1);
  s21_mult_matrix(&A, &B, &C);
  s21_create_matrix(4, 4, &D);
  D.matrix[0][0] = 90;
  D.matrix[0][1] = 100;
  D.matrix[0][2] = 110;
  D.matrix[0][3] = 120;
  D.matrix[1][0] = 202;
  D.matrix[1][1] = 228;
  D.matrix[1][2] = 254;
  D.matrix[1][3] = 280;
  D.matrix[2][0] = 314;
  D.matrix[2][1] = 356;
  D.matrix[2][2] = 398;
  D.matrix[2][3] = 440;
  D.matrix[3][0] = 426;
  D.matrix[3][1] = 484;
  D.matrix[3][2] = 542;
  D.matrix[3][3] = 600;
  res = s21_eq_matrix(&D, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  int res = 0;
  matrix_t A = {0}, B = {0}, C = {0}, D = {0};
  s21_create_matrix(4, 4, &A);
  s21_fill2_matrix(&A, 1);
  s21_create_matrix(4, 4, &B);
  s21_fill2_matrix(&B, -5);
  s21_mult_matrix(&A, &B, &C);
  s21_create_matrix(4, 4, &D);
  D.matrix[0][0] = 30.0;
  D.matrix[0][1] = 40.0;
  D.matrix[0][2] = 50.0;
  D.matrix[0][3] = 60.0;
  D.matrix[1][0] = 46.0;
  D.matrix[1][1] = 72.0;
  D.matrix[1][2] = 98.0;
  D.matrix[1][3] = 124.0;
  D.matrix[2][0] = 62.0;
  D.matrix[2][1] = 104.0;
  D.matrix[2][2] = 146.0;
  D.matrix[2][3] = 188.0;
  D.matrix[3][0] = 78.0;
  D.matrix[3][1] = 136.0;
  D.matrix[3][2] = 194.0;
  D.matrix[3][3] = 252.0;
  res = s21_eq_matrix(&D, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&D);
  s21_remove_matrix(&C);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  int res = 0;
  matrix_t A = {0}, B = {0}, C = {0};
  res = s21_mult_matrix(&A, &B, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  int res = 0;
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(2, 3, &A);
  s21_fill2_matrix(&B, -5);
  s21_create_matrix(2, 2, &B);
  s21_fill2_matrix(&B, 1);
  res = s21_mult_matrix(&A, &B, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(s21_transpose_1) {
  int res = 0;
  matrix_t A = {0};
  res = s21_transpose(&A, &A);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_2) {
  int res = 0;
  matrix_t A = {0}, B = {0}, C = {0};

  s21_create_matrix(3, 4, &A);
  s21_fill2_matrix(&A, 1);
  s21_create_matrix(4, 3, &B);
  s21_fill2_matrix(&B, 1);
  res = s21_transpose(&A, &C);
  res = s21_eq_matrix(&C, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_transpose_3) {
  int res = 0;
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(2, 3, &A);
  s21_fill2_matrix(&A, 1);
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 5;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 6;
  res = s21_transpose(&A, &C);
  res = s21_eq_matrix(&C, &B);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_1) {
  int res = 0;
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 112.0;
  A.matrix[0][1] = 243.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = -8.0;
  A.matrix[1][0] = 47.0;
  A.matrix[1][1] = 51.0;
  A.matrix[1][2] = -66.0;
  A.matrix[1][3] = 99.0;
  A.matrix[2][0] = -74.0;
  A.matrix[2][1] = 85.0;
  A.matrix[2][2] = 97.0;
  A.matrix[2][3] = 63.0;
  A.matrix[3][0] = -13.0;
  A.matrix[3][1] = 79.0;
  A.matrix[3][2] = -99.0;
  A.matrix[3][3] = -121.0;
  s21_calc_complements(&A, &B);
  s21_create_matrix(4, 4, &C);
  C.matrix[0][0] = -2879514.0;
  C.matrix[0][1] = -1236631.0;
  C.matrix[0][2] = -1685096.0;
  C.matrix[0][3] = 880697.0;
  C.matrix[1][0] = 1162090.0;
  C.matrix[1][1] = -714015.0;
  C.matrix[1][2] = 4046255.0;
  C.matrix[1][3] = -3901600.0;
  C.matrix[2][0] = 4362897.0;
  C.matrix[2][1] = -2049432.0;
  C.matrix[2][2] = -532912.0;
  C.matrix[2][3] = -1370781.0;
  C.matrix[3][0] = 3412773.0;
  C.matrix[3][1] = -1569493.0;
  C.matrix[3][2] = 3144517.0;
  C.matrix[3][3] = 1284666.0;
  res = s21_eq_matrix(&C, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  int res = 0;
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;
  s21_calc_complements(&A, &B);
  s21_create_matrix(4, 4, &C);
  C.matrix[0][0] = 0.0;
  C.matrix[0][1] = -30.0;
  C.matrix[0][2] = -108.0;
  C.matrix[0][3] = 106.0;
  C.matrix[1][0] = 138.0;
  C.matrix[1][1] = -726.0;
  C.matrix[1][2] = -1137.0;
  C.matrix[1][3] = 1061.0;
  C.matrix[2][0] = 0.0;
  C.matrix[2][1] = 12.0;
  C.matrix[2][2] = 57.0;
  C.matrix[2][3] = -47.0;
  C.matrix[3][0] = 0.0;
  C.matrix[3][1] = 6.0;
  C.matrix[3][2] = -75.0;
  C.matrix[3][3] = 57.0;
  res = s21_eq_matrix(&C, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  int res = 0;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(4, 3, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  res = s21_calc_complements(&A, &B);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(s21_calc_complements_4) {
  int res = 0;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_calc_complements_5) {
  int res = 0;
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  s21_calc_complements(&A, &B);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 0;
  C.matrix[0][1] = 10;
  C.matrix[0][2] = -20;
  C.matrix[1][0] = 4;
  C.matrix[1][1] = -14;
  C.matrix[1][2] = 8;
  C.matrix[2][0] = -8;
  C.matrix[2][1] = -2;
  C.matrix[2][2] = 4;
  res = s21_eq_matrix(&B, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_determinant_1) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {NULL, 0, 0};
  res = s21_determinant(&A, &determ);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(1, 2, &A);
  res = s21_determinant(&A, &determ);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  s21_fill2_matrix(&A, 1);
  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_4) {
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 4000.87;
  A.matrix[0][1] = 454.0;
  A.matrix[0][2] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 1.897;
  A.matrix[1][2] = 3.0;
  A.matrix[2][0] = 0.000087;
  A.matrix[2][1] = 2.5668;
  A.matrix[2][2] = 1.0;
  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -24105.996724156);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_5) {
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = -677700.0;
  A.matrix[0][1] = 654.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -0.00001;
  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -1301.223);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_6) {
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(8, 8, &A);
  s21_fill2_matrix(&A, 1);
  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_7) {
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_1) {
  int res = 0;
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;
  s21_inverse_matrix(&A, &B);
  s21_create_matrix(4, 4, &C);
  C.matrix[0][0] = 0.0;
  C.matrix[0][1] = 1.0;
  C.matrix[0][2] = 0.0;
  C.matrix[0][3] = 0.0;
  C.matrix[1][0] = -5.0 / 23.0;
  C.matrix[1][1] = -121.0 / 23.0;
  C.matrix[1][2] = 2.0 / 23.0;
  C.matrix[1][3] = 1.0 / 23.0;
  C.matrix[2][0] = -18.0 / 23.0;
  C.matrix[2][1] = -379.0 / 46.0;
  C.matrix[2][2] = 19.0 / 46.0;
  C.matrix[2][3] = -25.0 / 46.0;
  C.matrix[3][0] = 53.0 / 69.0;
  C.matrix[3][1] = 1061.0 / 138.0;
  C.matrix[3][2] = -47.0 / 138.0;
  C.matrix[3][3] = 19.0 / 46.0;
  res = s21_eq_matrix(&C, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  int res;
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;
  res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(B.matrix[0][0] == (1.0 / A.matrix[0][0]), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  int res = 0;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 1);
  res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  int res = 0;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 2, &A);
  s21_fill2_matrix(&A, 1);
  res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_5) {
  int res = 0;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  s21_fill2_matrix(&A, 1);
  s21_remove_matrix(&A);
  res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_inverse_matrix_6) {
  int res = 0;
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 8.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 9.0;
  s21_inverse_matrix(&A, &B);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = -3.0 / 5.0;
  C.matrix[0][1] = 0.0;
  C.matrix[0][2] = 1.0 / 5.0;
  C.matrix[1][0] = -4.0 / 5.0;
  C.matrix[1][1] = 1.0;
  C.matrix[1][2] = -2.0 / 5.0;
  C.matrix[2][0] = 16.0 / 15.0;
  C.matrix[2][1] = -2.0 / 3.0;
  C.matrix[2][2] = 1.0 / 5.0;
  res = s21_eq_matrix(&C, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

int main() {
  Suite *suite = suite_create("\033[42mExt2 Tests\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_create_matrix_1);
  tcase_add_test(tc_core, s21_create_matrix_2);
  tcase_add_test(tc_core, s21_create_matrix_3);
  tcase_add_test(tc_core, s21_create_matrix_4);
  tcase_add_test(tc_core, s21_create_matrix_5);
  tcase_add_test(tc_core, s21_create_matrix_6);
  tcase_add_test(tc_core, s21_create_matrix_7);
  tcase_add_test(tc_core, s21_create_matrix_8);
  tcase_add_test(tc_core, s21_create_matrix_9);
  tcase_add_test(tc_core, s21_create_matrix_10);
  tcase_add_test(tc_core, s21_create_matrix_11);
  tcase_add_test(tc_core, s21_remove_matrix_1);
  tcase_add_test(tc_core, s21_remove_matrix_2);
  tcase_add_test(tc_core, s21_remove_matrix_3);
  tcase_add_test(tc_core, s21_remove_matrix_4);
  tcase_add_test(tc_core, s21_remove_matrix_5);
  tcase_add_test(tc_core, s21_remove_matrix_6);
  tcase_add_test(tc_core, s21_remove_matrix_7);
  tcase_add_test(tc_core, s21_remove_matrix_8);
  tcase_add_test(tc_core, s21_remove_matrix_9);
  tcase_add_test(tc_core, s21_eq_matrix_1);
  tcase_add_test(tc_core, s21_eq_matrix_2);
  tcase_add_test(tc_core, s21_eq_matrix_3);
  tcase_add_test(tc_core, s21_eq_matrix_4);
  tcase_add_test(tc_core, s21_eq_matrix_5);
  tcase_add_test(tc_core, s21_eq_matrix_6);
  tcase_add_test(tc_core, s21_eq_matrix_7);
  tcase_add_test(tc_core, s21_eq_matrix_8);
  tcase_add_test(tc_core, s21_sum_matrix_1);
  tcase_add_test(tc_core, s21_sum_matrix_2);
  tcase_add_test(tc_core, s21_sum_matrix_3);
  tcase_add_test(tc_core, s21_sum_matrix_4);
  tcase_add_test(tc_core, s21_sum_matrix_5);
  tcase_add_test(tc_core, s21_sum_matrix_6);
  tcase_add_test(tc_core, s21_sum_matrix_7);
  tcase_add_test(tc_core, s21_sum_matrix_8);
  tcase_add_test(tc_core, s21_sub_matrix_1);
  tcase_add_test(tc_core, s21_sub_matrix_2);
  tcase_add_test(tc_core, s21_sub_matrix_3);
  tcase_add_test(tc_core, s21_sub_matrix_4);
  tcase_add_test(tc_core, s21_sub_matrix_5);
  tcase_add_test(tc_core, s21_sub_matrix_6);
  tcase_add_test(tc_core, s21_mult_number_1);
  tcase_add_test(tc_core, s21_mult_number_2);
  tcase_add_test(tc_core, s21_mult_number_3);
  tcase_add_test(tc_core, s21_mult_number_4);
  tcase_add_test(tc_core, s21_mult_matrix_1);
  tcase_add_test(tc_core, s21_mult_matrix_2);
  tcase_add_test(tc_core, s21_transpose_2);
  tcase_add_test(tc_core, s21_inverse_matrix_1);
  tcase_add_test(tc_core, s21_inverse_matrix_2);
  tcase_add_test(tc_core, s21_inverse_matrix_6);
  tcase_add_test(tc_core, s21_mult_matrix_3);
  tcase_add_test(tc_core, s21_mult_matrix_4);
  tcase_add_test(tc_core, s21_transpose_1);
  tcase_add_test(tc_core, s21_transpose_3);
  tcase_add_test(tc_core, s21_calc_complements_1);
  tcase_add_test(tc_core, s21_calc_complements_2);
  tcase_add_test(tc_core, s21_calc_complements_3);
  tcase_add_test(tc_core, s21_calc_complements_4);
  tcase_add_test(tc_core, s21_calc_complements_5);
  tcase_add_test(tc_core, s21_determinant_1);
  tcase_add_test(tc_core, s21_determinant_2);
  tcase_add_test(tc_core, s21_determinant_3);
  tcase_add_test(tc_core, s21_determinant_4);
  tcase_add_test(tc_core, s21_determinant_5);
  tcase_add_test(tc_core, s21_determinant_6);
  tcase_add_test(tc_core, s21_determinant_7);
  tcase_add_test(tc_core, s21_inverse_matrix_3);
  tcase_add_test(tc_core, s21_inverse_matrix_4);
  tcase_add_test(tc_core, s21_inverse_matrix_5);

  suite_add_tcase(suite, tc_core);

  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}