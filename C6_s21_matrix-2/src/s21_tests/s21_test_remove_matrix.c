#include <check.h>

#include "../s21_matrix.h"

START_TEST(s21_running_test) {
  matrix_t new_matrix = {NULL, 4, 4};
  s21_remove_matrix(&new_matrix);
  ck_assert_ptr_eq(new_matrix.matrix, NULL);
  ck_assert_int_eq(new_matrix.rows, 0);
  ck_assert_int_eq(new_matrix.columns, 0);
}
END_TEST

int main(void) {
  Suite *suite = suite_create("\033[42mRemove\033[0m");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_running_test);

  suite_add_tcase(suite, tc_core);

  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
