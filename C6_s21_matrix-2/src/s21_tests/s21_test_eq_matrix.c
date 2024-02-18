#include <check.h>

#include "../s21_matrix.h"

START_TEST(s21_running_test) {
  matrix_t A = {NULL, 3, 3};
  s21_create_matrix(A.rows, A.columns, &A);
  s21_fill_matrix(&A);
  matrix_t B = {NULL, 3, 3};
  s21_create_matrix(B.rows, B.columns, &B);
  s21_fill_matrix(&B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_negative_number_test) {
  matrix_t A = {NULL, 3, 3};
  s21_create_matrix(A.rows, A.columns, &A);
  s21_fill_matrix(&A);
  matrix_t B = {NULL, 3, -1};
  // s21_create_matrix(B.rows, B.columns, &B);
  // s21_fill_matrix(&B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  // s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_not_comprare_test) {
  matrix_t A = {NULL, 3, 3};
  s21_create_matrix(A.rows, A.columns, &A);
  s21_fill_matrix(&A);
  matrix_t B = {NULL, 3, 4};
  s21_create_matrix(B.rows, B.columns, &B);
  s21_fill_matrix(&B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// к вопросу про нулы
START_TEST(s21_not_NULL_test) {
  matrix_t A = {NULL, 3, 3};
  s21_create_matrix(A.rows, A.columns, &A);
  s21_fill_matrix(&A);
  matrix_t B = {NULL, 3, 3};
  // s21_create_matrix(B.rows, B.columns, &B);
  // s21_fill_matrix(&B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  // s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_different_test) {
  matrix_t A = {NULL, 3, 3};
  s21_create_matrix(A.rows, A.columns, &A);
  double values[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  s21_custom_fill_matrix(&A, values);
  matrix_t B = {NULL, 3, 3};
  s21_create_matrix(B.rows, B.columns, &B);
  double values1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_custom_fill_matrix(&B, values1);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// START_TEST(s21_6_signs_correct_test) {
//   matrix_t A = {NULL, 3, 3};
//   s21_create_matrix(A.rows, A.columns, &A);
//   double values[9] = {1, 2.12345677, 3, 4, 5, 6, 7, 8, 9};
//   s21_custom_fill_matrix(&A, values);
//   matrix_t B = {NULL, 3, 3};
//   s21_create_matrix(B.rows, B.columns, &B);
//   double values1[9] = {1, 2.12345618, 3, 4, 5, 6, 7, 8, 9};
//   s21_custom_fill_matrix(&B, values1);
//   int res = s21_eq_matrix(&A, &B);
//   ck_assert_int_eq(res, SUCCESS);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
// }
// END_TEST

START_TEST(s21_6_signs_wrong_test) {
  matrix_t A = {NULL, 3, 3};
  s21_create_matrix(A.rows, A.columns, &A);
  double values[9] = {1, 2.12345677, 3, 4, 5, 6, 7, 8, 9};
  s21_custom_fill_matrix(&A, values);
  matrix_t B = {NULL, 3, 3};
  s21_create_matrix(B.rows, B.columns, &B);
  double values1[9] = {1, 2.12345788, 3, 4, 5, 6, 7, 8, 9};
  s21_custom_fill_matrix(&B, values1);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_big_matrix_test) {
  matrix_t A = {NULL, 10, 10};
  s21_create_matrix(A.rows, A.columns, &A);
  s21_fill_matrix(&A);
  matrix_t B = {NULL, 10, 10};
  s21_create_matrix(B.rows, B.columns, &B);
  s21_fill_matrix(&B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

int main(void) {
  Suite *suite = suite_create("\033[42mEq\033[0m");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_running_test);
  tcase_add_test(tc_core, s21_negative_number_test);
  tcase_add_test(tc_core, s21_not_comprare_test);
  tcase_add_test(tc_core, s21_not_NULL_test);
  tcase_add_test(tc_core, s21_different_test);
  // tcase_add_test(tc_core, s21_6_signs_correct_test);
  tcase_add_test(tc_core, s21_6_signs_wrong_test);
  tcase_add_test(tc_core, s21_big_matrix_test);

  suite_add_tcase(suite, tc_core);

  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
