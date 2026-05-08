#include "tests.h"

// Тест 1: Базовый
START_TEST(strstr_test_basic_1) {
  const char *haystack = "Hello, World, test str!";
  const char *needle1 = "World";
  ck_assert_ptr_eq(strstr(haystack, needle1), my_strstr(haystack, needle1));
}
END_TEST

START_TEST(strstr_test_basic_2) {
  const char *haystack = "Hello, World, test str!";
  const char *needle2 = "Hello";
  ck_assert_ptr_eq(strstr(haystack, needle2), my_strstr(haystack, needle2));
}
END_TEST

START_TEST(strstr_test_basic_3) {
  const char *haystack = "Hello, World, test str!";
  const char *needle3 = "!";
  ck_assert_ptr_eq(strstr(haystack, needle3), my_strstr(haystack, needle3));
}
END_TEST

// Тест 2: граничный случай (NULL/пустая строка)
START_TEST(strstr_test_empty_string_1) {
  const char *haystack = "Hello, World!";
  const char *needle = "\0";
  ck_assert_ptr_eq(strstr(haystack, needle), my_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_test_empty_string_2) {
  const char *haystack2 = "";
  const char *needle2 = "test";
  ck_assert_ptr_eq(strstr(haystack2, needle2), my_strstr(haystack2, needle2));
}
END_TEST

START_TEST(strstr_test_empty_string_3) {
  const char *haystack3 = "";
  const char *needle3 = "";
  ck_assert_ptr_eq(strstr(haystack3, needle3), my_strstr(haystack3, needle3));
}
END_TEST

// Тест 3:случай ошибки/не найден
START_TEST(strstr_test_fail_1) {
  const char *haystack = "Hello, World, test str!";
  const char *needle = "ok";
  ck_assert_ptr_eq(strstr(haystack, needle), my_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_test_fail_2) {
  // Needle длиннее haystack
  const char *haystack2 = "abc";
  const char *needle2 = "abcd";
  ck_assert_ptr_eq(strstr(haystack2, needle2), my_strstr(haystack2, needle2));
}
END_TEST

START_TEST(strstr_test_fail_3) {
  // Частичное совпадение, но не полное
  const char *haystack3 = "Hello, World!";
  const char *needle3 = "World!x";
  ck_assert_ptr_eq(strstr(haystack3, needle3), my_strstr(haystack3, needle3));
}
END_TEST

Suite *my_test_strstr(void) {
  Suite *s = suite_create("STRSTR");
  TCase *tc = tcase_create("strstr");

  tcase_add_test(tc, strstr_test_basic_1);
  tcase_add_test(tc, strstr_test_basic_2);
  tcase_add_test(tc, strstr_test_basic_3);

  tcase_add_test(tc, strstr_test_empty_string_1);
  tcase_add_test(tc, strstr_test_empty_string_2);
  tcase_add_test(tc, strstr_test_empty_string_3);

  tcase_add_test(tc, strstr_test_fail_1);
  tcase_add_test(tc, strstr_test_fail_2);
  tcase_add_test(tc, strstr_test_fail_3);

  suite_add_tcase(s, tc);
  return s;
}
