#include <check.h>

#include "../s21_matrix.h"

START_TEST(s21_running_test) {
  matrix_t A = {NULL, 4, 4};
  int ret = s21_create_matrix(A.rows, A.columns, &A);
  ck_assert_int_eq(ret, ok);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_zero_test) {
  matrix_t A = {NULL, 4, 0};
  int ret = s21_create_matrix(A.rows, A.columns, &A);
  ck_assert_int_eq(ret, error);
}
END_TEST

// START_TEST(s21_not_NULL_test) {
//   matrix_t A = {NULL, 4, 4};
//   s21_create_matrix(A.rows, A.columns, &A);
//   s21_fill_matrix(&A);
//   int ret = s21_create_matrix(5, 5, &A);
//   ck_assert_int_eq(ret, error);
// }
// END_TEST

START_TEST(s21_negative_number_test) {
  matrix_t A = {NULL, 4, -5};
  int ret = s21_create_matrix(A.rows, A.columns, &A);
  ck_assert_int_eq(ret, error);
}
END_TEST

START_TEST(s21_big_matrix_test) {
  matrix_t A = {NULL, 10, 11};
  int ret = s21_create_matrix(A.rows, A.columns, &A);
  ck_assert_int_eq(ret, ok);
  s21_remove_matrix(&A);
}
END_TEST

// START_TEST(s21_memory_crash_test) {
//   matrix_t A = {NULL, 2147483647, 2147483647};
//   int ret = s21_create_matrix(A.rows, A.columns, &A);
//   ck_assert_int_eq(ret, calculation_error);
//   s21_remove_matrix(&A);
// }
// END_TEST

int main(void) {
  Suite *suite = suite_create("\033[42mCreate\033[0m");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_running_test);
  tcase_add_test(tc_core, s21_zero_test);
  // tcase_add_test(tc_core, s21_not_NULL_test);
  tcase_add_test(tc_core, s21_negative_number_test);
  tcase_add_test(tc_core, s21_big_matrix_test);
  // tcase_add_test(tc_core, s21_memory_crash_test);

  suite_add_tcase(suite, tc_core);

  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
