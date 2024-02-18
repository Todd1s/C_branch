#include <check.h>
#include <math.h>
#include <stdio.h>

#include "../s21_math.h"
#include "stdlib.h"

START_TEST(s21_abs_test1) { ck_assert_int_eq(s21_abs(1), abs(1)); }
END_TEST

START_TEST(s21_abs_test2) { ck_assert_int_eq(s21_abs(-1), abs(-1)); }
END_TEST

START_TEST(s21_abs_test3) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(s21_abs_test4) {
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
}
END_TEST

START_TEST(s21_abs_test5) {
  ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN));
}
END_TEST

START_TEST(s21_abs_test6) {
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
}
END_TEST

Suite *abs_suite() {
  Suite *suite;
  TCase *tc_core;
  suite = suite_create("s21_abs");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_abs_test1);
  tcase_add_test(tc_core, s21_abs_test2);
  tcase_add_test(tc_core, s21_abs_test3);
  tcase_add_test(tc_core, s21_abs_test4);
  tcase_add_test(tc_core, s21_abs_test5);
  tcase_add_test(tc_core, s21_abs_test6);
  suite_add_tcase(suite, tc_core);
  return suite;
}

int run_abs_test() {
  Suite *s = abs_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

START_TEST(s21_acos_test1) {
  ck_assert_ldouble_eq_tol(s21_acos(1.0), acos(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.23234), acos(0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.0002), acos(0.0002), 1e-6);
}
END_TEST

START_TEST(s21_acos_test2) {
  ck_assert_ldouble_eq_tol(s21_acos(-1.0), acos(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.23234), acos(-0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.0002), acos(-0.0002), 1e-6);
}
END_TEST

START_TEST(s21_acos_test3) {
  ck_assert_ldouble_eq_tol(s21_acos(0.0), acos(0.0), 1e-6);
}
END_TEST

Suite *acos_suite() {
  Suite *suite;
  TCase *tc_core;
  suite = suite_create("s21_acos");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_acos_test1);
  tcase_add_test(tc_core, s21_acos_test2);
  tcase_add_test(tc_core, s21_acos_test3);
  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_acos_test() {
  Suite *s = acos_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

// Start s21_asin_tests

START_TEST(s21_asin_test1) {
  ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.23234), asin(0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.0002), asin(0.0002), 1e-6);
}
END_TEST

START_TEST(s21_asin_test2) {
  ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.23234), asin(-0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.0002), asin(-0.0002), 1e-6);
}
END_TEST

START_TEST(s21_asin_test3) {
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), 1e-6);
  ck_assert_ldouble_nan(s21_asin(S21_NEG_INF));
  ck_assert_ldouble_nan(s21_asin(S21_POS_INF));
}
END_TEST

Suite *asin_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_asin");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_asin_test1);
  tcase_add_test(tc_core, s21_asin_test2);
  tcase_add_test(tc_core, s21_asin_test3);
  suite_add_tcase(suite, tc_core);

  return suite;
}

// End s21_asin_tests

int run_asin_test() {
  Suite *s = asin_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

// Start s21_log_tests

START_TEST(s21_log_test1) {
  ck_assert_ldouble_eq_tol(s21_log(S21_EXP), log(S21_EXP), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(10), log(10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(3), log(3), 1e-6);

  for (double i = 0.1; i < 100.0; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_log(i), log(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_log_test2) {
  ck_assert_double_nan(s21_log(-1));
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_eq_tol(s21_log(0.00001), log(0.00001), 0.00001);
  ck_assert_double_nan(s21_log(NAN));
  ck_assert_double_nan(s21_log(S21_NAN));
  ck_assert_double_nan(s21_log(-S21_NAN));
  ck_assert_ldouble_infinite(s21_log(S21_POS_INF));
  ck_assert_ldouble_nan(s21_log(S21_NEG_INF));
}
END_TEST

Suite *log_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_log");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_log_test1);
  tcase_add_test(tc_core, s21_log_test2);
  suite_add_tcase(suite, tc_core);

  return suite;
}

// End s21_log_tests

int run_log_test() {
  Suite *s = log_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

// Start s21_sin_tests

START_TEST(s21_sin_test1) {
  for (double i = -5 * S21_PI; i <= 5 * S21_PI; i += 0.05) {
    ck_assert_ldouble_eq_tol(s21_sin(i), sin(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_sin_test2) {
  ck_assert_ldouble_eq_tol(s21_sin(100), sin(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-3003), sin(-3003), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.0005), sin(0.0005), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.98439849385), sin(0.98439849385), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI), sin(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_PI), sin(-S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI / 2), sin(S21_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_PI / 2), sin(-S21_PI / 2), 1e-6);
}
END_TEST

Suite *sin_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_sin");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_sin_test1);
  tcase_add_test(tc_core, s21_sin_test2);
  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_sin_test() {
  Suite *s = sin_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

//    End s21_sin_tests
// Start s21_ceil_tests

START_TEST(s21_ceil_test1) {
  ck_assert_ldouble_eq_tol(s21_ceil(-5.7), ceil(-5.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.1), ceil(-0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(12.4), ceil(12.4), 1e-6);

  for (double i = -1.01; i <= 1.01; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_ceil(i), ceil(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_ceil_test2) {
  ck_assert_double_infinite(s21_ceil(S21_POS_INF));
  ck_assert_double_infinite(s21_ceil(S21_NEG_INF));
  ck_assert_double_nan(s21_ceil(S21_NAN));
}
END_TEST

Suite *ceil_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_ceil");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_ceil_test1);
  tcase_add_test(tc_core, s21_ceil_test2);
  suite_add_tcase(suite, tc_core);

  return suite;
}

// End s21_ceil_tests
int run_ceil_test() {
  Suite *s = ceil_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

// // Start s21_exp_tests

START_TEST(s21_exp_test1) {
  ck_assert_ldouble_eq_tol(s21_exp(-5), exp(-5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(5), exp(5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.1), exp(0.1), 1e-6);
}
END_TEST

START_TEST(s21_exp_test2) {
  for (double i = -20.0; i <= 20.00; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_exp(i), exp(i), 1e-6);
  }
  ck_assert_float_infinite(s21_exp(243757437));
  ck_assert_ldouble_eq_tol(s21_exp(-24.4353425), exp(-24.4353425), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.0), exp(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-24.4353425), exp(-24.4353425), 1e-6);
}
END_TEST

START_TEST(s21_exp_test3) {
  ck_assert_float_infinite(s21_exp(S21_POS_INF));
  ck_assert_ldouble_eq(s21_exp(S21_NEG_INF), 0.0);
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_nan(s21_exp(-S21_NAN));
}
END_TEST

Suite *exp_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_exp");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_exp_test1);
  tcase_add_test(tc_core, s21_exp_test2);
  tcase_add_test(tc_core, s21_exp_test3);
  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_exp_test() {
  Suite *s = exp_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}
// End s21_exp_tests

// Start s21_atan_tests

START_TEST(s21_atan_test1) {
  ck_assert_ldouble_eq_tol(s21_atan(1.0), atan(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.1), atan(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1000.0), atan(1000.0), 1e-6);
}
END_TEST

START_TEST(s21_atan_test2) {
  ck_assert_ldouble_eq_tol(s21_atan(-1.0), atan(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1000.0), atan(-1000.0), 1e-6);
}
END_TEST

START_TEST(s21_atan_test3) {
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), 1e-6);
}
END_TEST

Suite *atan_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_atan");

  tc_core = tcase_create("Core");
  //  tcase_set_timeout(tc_core, 10);
  tcase_add_test(tc_core, s21_atan_test1);
  tcase_add_test(tc_core, s21_atan_test2);
  tcase_add_test(tc_core, s21_atan_test3);
  suite_add_tcase(suite, tc_core);

  return suite;
}

// End s21_atan_tests

int run_atan_test() {
  Suite *s = atan_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

// Start s21_cos_tests

START_TEST(s21_cos_test1) {
  for (double i = -5 * S21_PI; i <= 5 * S21_PI; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_cos(i), cos(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_cos_test2) {
  ck_assert_ldouble_eq_tol(s21_cos(100), cos(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-3003), cos(-3003), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.0005), cos(0.0005), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.98439849385), cos(0.98439849385), 1e-6);
}
END_TEST

START_TEST(s21_cos_test3) {
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI), cos(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_PI), cos(-S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI / 2), cos(S21_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_PI / 2), cos(-S21_PI / 2), 1e-6);
}
END_TEST

Suite *cos_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_cos");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_cos_test1);
  tcase_add_test(tc_core, s21_cos_test2);
  tcase_add_test(tc_core, s21_cos_test3);
  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_cos_test() {
  Suite *s = cos_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

// End s21_cos_tests

// Start s21_fabs_tests

START_TEST(s21_fabs_test1) {
  ck_assert_ldouble_eq(s21_fabs(-5.503), fabs(-5.503));
  ck_assert_ldouble_eq(s21_fabs(5.0), fabs(5.0));
  ck_assert_ldouble_eq(s21_fabs(0.0), fabs(0.0));
}
END_TEST

START_TEST(s21_fabs_test2) {
  ck_assert_ldouble_eq(s21_fabs(-10.45934), fabs(-10.45934));
  ck_assert_ldouble_eq(s21_fabs(10.1), fabs(10.1));
  ck_assert_ldouble_eq(s21_fabs(0.0), fabs(0.0));
}
END_TEST

Suite *fabs_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("\033[42ms21_fabs\033[0m");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_fabs_test1);
  tcase_add_test(tc_core, s21_fabs_test2);
  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_fabs_test() {
  Suite *s = fabs_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

// End s21_fabs_tests

// Start s21_floor_tests

START_TEST(s21_floor_test1) {
  ck_assert_ldouble_eq_tol(s21_floor(-5.7), floor(-5.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(5.1), floor(5.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(12.4), floor(12.4), 1e-6);
  for (double i = -2.01; i <= 1.01; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_floor(i), floor(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_floor_test2) {
  ck_assert_double_infinite(s21_floor(S21_POS_INF));
  ck_assert_double_infinite(s21_floor(S21_NEG_INF));
  ck_assert_double_nan(s21_floor(S21_NAN));
}
END_TEST

Suite *floor_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("\033[42ms21_floor\033[0m");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_floor_test1);
  tcase_add_test(tc_core, s21_floor_test2);
  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_floor_test() {
  Suite *s = floor_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

// End s21_floor_tests

// Start s21_fmod_tests

START_TEST(s21_fmod_test1) {
  ck_assert_ldouble_eq_tol(s21_fmod(-8, 3), fmod(-8, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-10, 2), fmod(-10, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(164.2, 0.3), fmod(164.2, 0.3), 1e-6);
}
END_TEST

START_TEST(s21_fmod_test2) {
  ck_assert_double_nan(s21_fmod(0, 0));
  ck_assert_double_nan(s21_fmod(3, 0));
  ck_assert_ldouble_eq_tol(s21_fmod(100, -5), fmod(100, -5), 1e-6);
  ck_assert_double_nan(s21_fmod(S21_POS_INF, -5));
  ck_assert_double_nan(s21_fmod(4, S21_NAN));
}
END_TEST

Suite *fmod_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("\033[42ms21_fmod\033[0m");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_fmod_test1);
  tcase_add_test(tc_core, s21_fmod_test2);
  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_fmod_test() {
  Suite *s = fmod_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}
// End s21_fmod_tests

// Start s21_sqrt_tests

START_TEST(s21_sqrt_test1) {
  ck_assert_ldouble_eq_tol(s21_sqrt(256), sqrt(256), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(25), sqrt(25), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
}
END_TEST

START_TEST(s21_sqrt_test2) {
  ck_assert_double_nan(s21_sqrt(-1));
  ck_assert_ldouble_eq_tol(s21_sqrt(1e10), sqrt(1e10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.01), sqrt(0.01), 1e-6);
}
END_TEST

Suite *sqrt_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("\033[42ms21_sqrt\033[0m");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_sqrt_test1);
  tcase_add_test(tc_core, s21_sqrt_test2);
  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_sqrt_test() {
  Suite *s = sqrt_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

// End s21_sqrt_tests

// Start s21_tan_tests

START_TEST(s21_tan_test1) {
  ck_assert_ldouble_eq_tol(s21_tan(1000), tan(1000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-3003), tan(-3003), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0.0005), tan(0.0005), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0.98439849385), tan(0.98439849385), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI), tan(S21_PI), 1e-6);
}
END_TEST

Suite *tan_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_tan");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_tan_test1);
  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_tan_test() {
  Suite *s = tan_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

// End s21_tan_tests

// Start s21_pow_tests

START_TEST(s21_pow_test1) {
  ck_assert_ldouble_eq_tol(s21_pow(8, 3), pow(8, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-8, 3), pow(-8, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(8, -3), pow(8, -3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, -3), pow(1, -3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 5), pow(0, 5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(8.234, -3), pow(8.234, -3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(25, 0.5), pow(25, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(5, 1.4), pow(5, 1.4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(5, -1.4), pow(5, -1.4), 1e-6);
  ck_assert_double_nan(s21_pow(-4, 1.4));
  for (double i = 0.0; i < 10.0; i += 0.1) {
    for (double j = 0.0; j < 10.0; j += 0.1) {
      ck_assert_ldouble_eq_tol(s21_pow(i, j), pow(i, j), 1e-4);
    }
  }
}
END_TEST

START_TEST(s21_pow_test2) {
  ck_assert_ldouble_eq_tol(s21_pow(2989839, 0.0004), pow(2989839, 0.0004),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2989839, 0), pow(2989839, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2989839, -2), pow(2989839, -2), 1e-6);
}
END_TEST

START_TEST(s21_pow_test3) {
  double base = 0.0083928293832;
  ck_assert_ldouble_eq_tol(s21_pow(base, 0.0004), pow(base, 0.0004), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base, 293), pow(base, 293), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base, 0), pow(base, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base, 66), pow(base, 66), 1e-6);
}
END_TEST

START_TEST(s21_pow_test4) {
  ck_assert_double_nan(s21_pow(0.00, NAN));
  ck_assert_double_nan(s21_pow(S21_POS_INF, NAN));
  ck_assert_double_nan(s21_pow(S21_NEG_INF, NAN));
  ck_assert_double_nan(s21_pow(NAN, NAN));
  ck_assert_double_nan(s21_pow(NAN, -NAN));
  ck_assert_double_nan(s21_pow(-NAN, -NAN));
  ck_assert_double_nan(s21_pow(0.00, -NAN));
  ck_assert_double_nan(s21_pow(0.00, -NAN));
  ck_assert_double_nan(s21_pow(-1.00, 1.50));
  ck_assert_double_nan(s21_pow(-NAN, -NAN));
}
END_TEST

START_TEST(s21_pow_test5) {
  ck_assert_ldouble_infinite(s21_pow(0.00, -5.00));
  ck_assert_ldouble_infinite(s21_pow(0.00, S21_NEG_INF));
  ck_assert_ldouble_infinite(s21_pow(0.10, S21_NEG_INF));
  ck_assert_ldouble_infinite(s21_pow(-0.10, S21_NEG_INF));
  ck_assert_ldouble_infinite(s21_pow(5.00, S21_POS_INF));
  ck_assert_ldouble_infinite(s21_pow(-5.00, S21_POS_INF));
  ck_assert_ldouble_infinite(s21_pow(S21_POS_INF, 5.00));
  ck_assert_ldouble_infinite(s21_pow(S21_POS_INF, S21_POS_INF));
  ck_assert_ldouble_infinite(s21_pow(S21_NEG_INF, S21_POS_INF));
}
END_TEST

START_TEST(s21_pow_test6) {
  ck_assert_double_eq(s21_pow(-1.00, S21_POS_INF), 1.0);
  ck_assert_double_eq(s21_pow(-1.00, S21_NEG_INF), 1.0);
  ck_assert_double_eq(s21_pow(NAN, 0), 1);  //
  ck_assert_double_eq(s21_pow(1.00, S21_POS_INF), 1.0);
  ck_assert_double_eq(s21_pow(1.00, 0.00), 1.0);
  ck_assert_double_eq(s21_pow(1.00, -5.00), 1.0);
  ck_assert_double_eq(s21_pow(1.00, 5.00), 1.0);
  ck_assert_double_eq(s21_pow(1.00, 1.50), 1.0);
  ck_assert_double_eq(s21_pow(-1.00, 2.00), 1.0);
  ck_assert_double_eq(s21_pow(S21_NAN, 0.00), 1.0);
  ck_assert_double_eq(s21_pow(S21_POS_INF, 0.00), 1.0);
  ck_assert_double_eq(s21_pow(5.00, 0.00), 1.0);
  ck_assert_double_eq(s21_pow(S21_NEG_INF, 0.00), 1.0);
}
END_TEST

Suite *pow_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("\033[42ms21_pow\033[0m");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_pow_test1);
  tcase_add_test(tc_core, s21_pow_test2);
  tcase_add_test(tc_core, s21_pow_test3);
  tcase_add_test(tc_core, s21_pow_test4);
  tcase_add_test(tc_core, s21_pow_test5);
  tcase_add_test(tc_core, s21_pow_test6);
  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_pow_test() {
  Suite *s = pow_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

// End s21_pow_tests

int main() {
  run_cos_test();    // +
  run_atan_test();   // +
  run_ceil_test();   // +
  run_sin_test();    // +
  run_log_test();    // +
  run_asin_test();   // +
  run_abs_test();    // +
  run_exp_test();    // +
  run_acos_test();   // +
  run_fabs_test();   // +
  run_floor_test();  // +
  run_fmod_test();   // +
  run_sqrt_test();   // +
  run_tan_test();    // +
  run_pow_test();    // +
}
