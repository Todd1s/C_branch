#include <check.h>

#include "../s21_matrix.h"

START_TEST(s21_running_test) {
  matrix_t A = {NULL, 3, 3};
  s21_create_matrix(A.rows, A.columns, &A);
  double values[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  s21_custom_fill_matrix(&A, values);
  double num = 0.0;
  int res = s21_determinant(&A, &num);
  ck_assert_int_eq(res, ok);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_running_test_2) {
  matrix_t A = {NULL, 3, 3};
  s21_create_matrix(A.rows, A.columns, &A);
  double values[9] = {1, 2, 3, 4, 6, 6, 7, 8, 9};
  s21_custom_fill_matrix(&A, values);
  double num = 6;
  int res = s21_determinant(&A, &num);
  ck_assert_int_eq(res, ok);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_negative_number_test) {
  matrix_t A = {NULL, 3, -3};
  s21_create_matrix(A.rows, A.columns, &A);
  double values[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  s21_custom_fill_matrix(&A, values);
  double num = 6;
  int res = s21_determinant(&A, &num);
  ck_assert_int_eq(res, error);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_not_NULL_test) {
  matrix_t A = {NULL, 3, 3};
  // s21_create_matrix(A.rows, A.columns, &A);
  // double values[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  // s21_custom_fill_matrix(&A, values);
  double num = 6;
  int res = s21_determinant(&A, &num);
  ck_assert_int_eq(res, error);
  // s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_square_test) {
  matrix_t A = {NULL, 3, 4};
  s21_create_matrix(A.rows, A.columns, &A);
  double values[12] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 10, 11, 12};
  s21_custom_fill_matrix(&A, values);
  double num = 6;
  int res = s21_determinant(&A, &num);
  ck_assert_int_eq(res, calculation_error);
  s21_remove_matrix(&A);
}
END_TEST

int main(void) {
  Suite *suite = suite_create("\033[42mDeterminant\033[0m");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_running_test);
  tcase_add_test(tc_core, s21_running_test_2);
  tcase_add_test(tc_core, s21_negative_number_test);
  tcase_add_test(tc_core, s21_not_NULL_test);
  tcase_add_test(tc_core, s21_square_test);
  // tcase_add_test(tc_core, s21_6_signs_correct_test);
  // tcase_add_test(tc_core, s21_6_signs_wrong_test);
  // tcase_add_test(tc_core, s21_big_matrix_test);

  suite_add_tcase(suite, tc_core);

  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
