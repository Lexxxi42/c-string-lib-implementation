#include "tests.h"

START_TEST(test_to_upper) {
  char str[] = "hello WORLD 123!";
  char *result = my_to_upper(str);
  char *expected = "HELLO WORLD 123!";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_to_upper_2) {
  char str[] = "Test String 123! @#$";
  char *result = my_to_upper(str);
  char *expected = "TEST STRING 123! @#$";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_to_upper_3) {
  char str[] = "aBcDeFgHiJkLmNoPqRsTuVwXyZ";
  char *result = my_to_upper(str);
  char *expected = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_to_lower) {
  char str[] = "HELLO world 123!";
  char *result = my_to_lower(str);
  char *expected = "hello world 123!";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_to_lower_2) {
  char str[] = "TEST STRING 123! @#$";
  char *result = my_to_lower(str);
  char *expected = "test string 123! @#$";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_to_lower_3) {
  char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *result = my_to_lower(str);
  char *expected = "abcdefghijklmnopqrstuvwxyz";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_insert) {
  char src[] = "Hello world!";
  char str[] = "beautiful ";
  char *result = my_insert(src, str, 6);
  char *expected = "Hello beautiful world!";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_insert_2) {
  char src[] = "Hello";
  char str[] = "!";
  char *result = my_insert(src, str, 5);
  char *expected = "Hello!";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_insert_3) {
  char src[] = "Start";
  char str[] = "MiddleEnd";
  char *result = my_insert(src, str, 0);
  char *expected = "MiddleEndStart";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_trim) {
  char str[] = "   Hello world!   ";
  char *result = my_trim(str, " !");
  char *expected = "Hello world";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_trim_2) {
  char str[] = "*Hello World!!!***";
  char *result = my_trim(str, "*!");
  char *expected = "Hello World";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_trim_3) {
  char str[] = "abcHello Worldcba";
  char *result = my_trim(str, "abc");
  char *expected = "Hello World";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_to_upper_empty) {
  char str[] = "";
  char *result = my_to_upper(str);
  char *expected = "";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_to_lower_empty) {
  char str[] = "";
  char *result = my_to_lower(str);
  char *expected = "";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_insert_empty) {
  char src[] = "";
  char str[] = "test";
  char *result = my_insert(src, str, 0);
  char *expected = "test";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_trim_empty) {
  char str[] = "";
  char *result = my_trim(str, "");
  char *expected = "";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_trim_empty_2) {
  char str[] = "Hello world!";
  char *result = my_trim(str, "");
  char *expected = "Hello world!";

  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

Suite *my_test_special_functions(void) {
  Suite *s = suite_create("SPECIAL_FUNCTIONS");
  TCase *tc = tcase_create("special_functions");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_to_upper);
  tcase_add_test(tc, test_to_upper_2);
  tcase_add_test(tc, test_to_upper_3);
  tcase_add_test(tc, test_to_lower);
  tcase_add_test(tc, test_to_lower_2);
  tcase_add_test(tc, test_to_lower_3);
  tcase_add_test(tc, test_insert);
  tcase_add_test(tc, test_insert_2);
  tcase_add_test(tc, test_insert_3);
  tcase_add_test(tc, test_trim);
  tcase_add_test(tc, test_trim_2);
  tcase_add_test(tc, test_trim_3);
  tcase_add_test(tc, test_to_upper_empty);
  tcase_add_test(tc, test_to_lower_empty);
  tcase_add_test(tc, test_insert_empty);
  tcase_add_test(tc, test_trim_empty);
  tcase_add_test(tc, test_trim_empty_2);

  return s;
}