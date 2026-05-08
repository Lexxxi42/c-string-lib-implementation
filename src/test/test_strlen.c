#include "tests.h"

//// STRLEN
START_TEST(strlen_4) {
  char str[] = "\0";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

START_TEST(strlen_1) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

START_TEST(strlen_6) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

START_TEST(strlen_9) {
  char str[] = "\n\n\n\n\n\n\n\n\nstrlen\n\n\n\n\n";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

START_TEST(strlen_10) {
  char str[] = "\0\0\0\0A\n";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

START_TEST(strlen_12) {
  char str[] = "\t\t";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

START_TEST(strlen_13) {
  char str[] = "\0test";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

START_TEST(strlen_14) {
  char str[] = "wtf \0 wtf";
  ck_assert_int_eq(strlen(str), my_strlen(str));
}
END_TEST

Suite *my_test_strlen(void) {
  Suite *s = suite_create("STRLEN");
  TCase *tc = tcase_create("strlen");

  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_4);
  tcase_add_test(tc, strlen_6);
  tcase_add_test(tc, strlen_9);
  tcase_add_test(tc, strlen_10);
  tcase_add_test(tc, strlen_12);
  tcase_add_test(tc, strlen_13);
  tcase_add_test(tc, strlen_14);

  suite_add_tcase(s, tc);
  return s;
}