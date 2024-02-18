#include <check.h>

#include "../s21_matrix.h"

START_TEST(s21_running_test) {
  matrix_t A = {NULL, 3, 3};
  s21_create_matrix(A.rows, A.columns, &A);
  double values[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  int res = s21_custom_fill_matrix(&A, values);
  ck_assert_int_eq(res, ok);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_running_test_2) {
  matrix_t B = {NULL, 3, 3};
  s21_create_matrix(B.rows, B.columns, &B);
  int res = s21_fill_matrix(&B);
  ck_assert_int_eq(res, ok);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_running_test_3) {
  matrix_t A = {NULL, 3, 3};
  s21_create_matrix(A.rows, A.columns, &A);
  double values[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  s21_custom_fill_matrix(&A, values);

  matrix_t A_minor = {NULL, 2, 2};
  s21_create_matrix(A_minor.rows, A_minor.columns, &A_minor);
  int res = s21_get_minor(&A, &A_minor, 0, 0);
  ck_assert_int_eq(res, ok);
  s21_remove_matrix(&A);
  s21_remove_matrix(&A_minor);
}
END_TEST

START_TEST(s21_running_test_4) {
  matrix_t B = {NULL, 3, 3};
  s21_create_matrix(B.rows, B.columns, &B);
  s21_fill_matrix(&B);
  matrix_t B_copy = {NULL, 3, 3};
  s21_create_matrix(B_copy.rows, B_copy.columns, &B_copy);
  int res = s21_copy_matrix(&B, &B_copy);
  ck_assert_int_eq(res, ok);
  s21_remove_matrix(&B);
  s21_remove_matrix(&B_copy);
}
END_TEST

int main(void) {
  Suite *suite = suite_create("\033[42mHelper\033[0m");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_running_test);
  tcase_add_test(tc_core, s21_running_test_2);
  tcase_add_test(tc_core, s21_running_test_3);
  tcase_add_test(tc_core, s21_running_test_4);

  suite_add_tcase(suite, tc_core);

  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
