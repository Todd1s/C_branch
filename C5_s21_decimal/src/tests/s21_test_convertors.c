#include <check.h>

#include "../s21_decimal.h"

START_TEST(s21_from_decimal_to_int_pos) {
  int n = rand();
  int dest = 0;
  s21_decimal var = {0};
  int ret1 = s21_from_int_to_decimal(n, &var);
  int ret2 = s21_from_decimal_to_int(var, &dest);
  ck_assert_int_eq(ret1, 0);
  ck_assert_int_eq(ret2, 0);
  ck_assert_int_eq(n, dest);
}
END_TEST

START_TEST(s21_from_decimal_to_int_neg) {
  int n = -rand();
  int dest = 0;
  s21_decimal var = {0};
  int ret1 = s21_from_int_to_decimal(n, &var);
  int ret2 = s21_from_decimal_to_int(var, &dest);
  ck_assert_int_eq(ret1, 0);
  ck_assert_int_eq(ret2, 0);
  ck_assert_int_eq(n, dest);
}
END_TEST

START_TEST(s21_from_decimal_to_int_decr) {
  int dest = 0;
  s21_decimal var = {{0, 1, 0, 0b10000000011111110000000000000000}};
  int ret2 = s21_from_decimal_to_int(var, &dest);
  ck_assert_int_eq(ret2, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_1) {
  float src = 123.5;
  s21_decimal dest = {0};
  int ret = s21_from_float_to_decimal(src, &dest);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_2) {
  float src = 123.45;
  s21_decimal dest = {0};
  int ret = s21_from_float_to_decimal(src, &dest);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_3) {
  double src = -123.45;
  s21_decimal dest = {0};
  int ret = s21_from_float_to_decimal(src, &dest);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(dest.bits[1], 0);
  ck_assert_uint_eq(dest.bits[2], 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_1) {
  uint32 exp = 2 << 16;
  s21_decimal src = {{12345, 0, 0, exp}};
  float dest = 0;
  int ret = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(ret, 0);
  ck_assert_float_eq(dest, 123.45);
}
END_TEST

START_TEST(from_int_to_decimal_1) {
  int a = 7;
  s21_decimal b = {{0, 0, 0, MINUS}};
  int result = s21_from_int_to_decimal(a, &b);
  ck_assert_int_eq(result, 0);
}
END_TEST

int main(void) {
  Suite *suite = suite_create("Convertor");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_from_decimal_to_int_pos);
  tcase_add_test(tc_core, s21_from_decimal_to_int_neg);
  tcase_add_test(tc_core, s21_from_decimal_to_int_decr);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_1);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_2);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_3);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_1);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_1);
  tcase_add_test(tc_core, from_int_to_decimal_1);

  suite_add_tcase(suite, tc_core);

  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
