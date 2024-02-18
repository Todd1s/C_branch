#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ok 0
#define error 1  // Ошибка, некорректная матрица
#define calculation_error \
  2  // Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
     // нельзя провести вычисления и т.д.)

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// helpers.c
int s21_fill_matrix(matrix_t *A);
int s21_get_minor(matrix_t *A, matrix_t *result, int row_number,
                  int column_number);
int s21_copy_matrix(matrix_t *A, matrix_t *result);
int s21_custom_fill_matrix(matrix_t *A, double values[]);
double s21_round(double num);
#endif /* S21_MATRIX_H */