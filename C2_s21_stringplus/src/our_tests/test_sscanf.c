#include "s21_test.h"

START_TEST(sscanf_tests) {
  char *format = "%d";
  int d = 0;
  int a = 0;
  ck_assert_int_eq(sscanf("123", format, &a), s21_sscanf("123", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests2) {
  char *format = "%d %d";
  int d = 0;
  int e = 0;
  int a = 0;
  int b = 0;
  ck_assert_int_eq(sscanf("12 3", format, &a, &b),
                   s21_sscanf("12 3", format, &d, &e));
  ck_assert_int_eq(a, d);
  ck_assert_int_eq(b, e);
}
END_TEST

START_TEST(sscanf_tests3) {
  char *format = "%d %c";
  int d = 0;
  char e = 0;
  int a = 0;
  char b = 0;
  ck_assert_int_eq(sscanf("12 3", format, &a, &b),
                   s21_sscanf("12 3", format, &d, &e));
  ck_assert_int_eq(a, d);
  ck_assert_int_eq(b, e);
}
END_TEST

// work
START_TEST(sscanf_tests4) {
  char *format = "%o";
  int d = 0;
  int a = 0;
  ck_assert_int_eq(sscanf("07356261", format, &a),
                   s21_sscanf("07356261", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests7) {
  char *format = "%x";
  int d = 0;
  int a = 0;
  ck_assert_int_eq(sscanf("0x735682AB", format, &a),
                   s21_sscanf("0x735682AB", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

// work
START_TEST(sscanf_tests10) {
  char *format = "%Lf";
  long double d = 0;
  long double a = 0;
  ck_assert_int_eq(sscanf("-7.234", format, &a),
                   s21_sscanf("-7.234", format, &d));
  ck_assert_double_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests11) {
  char *format = "%ld";
  long int d = 0;
  long int a = 0;
  ck_assert_int_eq(sscanf("735682", format, &a),
                   s21_sscanf("735682", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests12) {
  char *format = "%*d %d";
  int d = 0;
  int a = 0;
  ck_assert_int_eq(sscanf("73568 -2", format, &a),
                   s21_sscanf("73568 -2", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests13) {
  char *format = "%d %n";
  int d = 0;
  int e = 0;
  int a = 0;
  int b = 0;
  ck_assert_int_eq(sscanf("73 568", format, &a, &b),
                   s21_sscanf("73 568", format, &d, &e));
  ck_assert_int_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests15) {
  char *format = "%2i";
  int d = 0;
  int a = 0;
  ck_assert_int_eq(sscanf("735682AB", format, &a),
                   s21_sscanf("735682AB", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests16) {
  char *format = "%s";
  char d[50] = {'\0'};
  char a[50] = {'\0'};
  ck_assert_int_eq(sscanf("i love codding", format, &a),
                   s21_sscanf("i love codding", format, &d));
  ck_assert_str_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests17) {
  char *format = "%s %d";
  char d[50] = {'\0'};
  int e = 0;
  char a[50] = {'\0'};
  int b = 0;
  ck_assert_int_eq(sscanf("love", format, &a, &b),
                   s21_sscanf("love", format, &d, &e));
  ck_assert_str_eq(a, d);
  ck_assert_int_eq(b, e);
}
END_TEST

START_TEST(sscanf_tests18) {
  char *format = "%s";
  char d[50] = {'\0'};
  int e = 0;
  char a[50] = {'\0'};
  int b = 0;
  ck_assert_int_eq(sscanf("i love codding -5", format, &a, &b),
                   s21_sscanf("i love codding -5", format, &d, &e));
  ck_assert_str_eq(a, d);
  ck_assert_int_eq(b, e);
}
END_TEST

START_TEST(sscanf_tests21) {
  char *format = "%g";
  float d = 0;
  float a = 0;
  ck_assert_int_eq(sscanf("735682.123456789", format, &a),
                   s21_sscanf("735682.123456789", format, &d));
  ck_assert_float_eq(a, d);
}
END_TEST

START_TEST(sscanf_tests23) {
  char *format = "%u";
  int d = 0;
  int a = 0;
  ck_assert_int_eq(sscanf("735682", format, &a),
                   s21_sscanf("735682", format, &d));
  ck_assert_int_eq(a, d);
}
END_TEST

Suite *test_sscanf(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_tests);
  tcase_add_test(tc, sscanf_tests2);
  tcase_add_test(tc, sscanf_tests3);
  tcase_add_test(tc, sscanf_tests4);

  tcase_add_test(tc, sscanf_tests7);
  // tcase_add_test(tc, sscanf_tests8);
  // tcase_add_test(tc, sscanf_tests9);
  tcase_add_test(tc, sscanf_tests10);

  tcase_add_test(tc, sscanf_tests11);
  tcase_add_test(tc, sscanf_tests12);
  tcase_add_test(tc, sscanf_tests13);

  tcase_add_test(tc, sscanf_tests15);

  tcase_add_test(tc, sscanf_tests16);
  tcase_add_test(tc, sscanf_tests17);
  tcase_add_test(tc, sscanf_tests18);
  // tcase_add_test(tc, sscanf_tests19);

  tcase_add_test(tc, sscanf_tests21);

  tcase_add_test(tc, sscanf_tests23);

  suite_add_tcase(s, tc);

  return s;
}

// int main(void) {
//   Suite *s21_string = example_suite_create();
//   SRunner *s21_string_runner = srunner_create(s21_string);
//   int failed = 0;
//   srunner_run_all(s21_string_runner, CK_NORMAL);
//   failed = srunner_ntests_failed(s21_string_runner);
//   srunner_free(s21_string_runner);
//   return failed == 0 ? 0 : 1;
// }
