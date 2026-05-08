#include "tests.h"

// Тест 1: Базовый
START_TEST(strncmp_test_basic_1) {
  ck_assert_int_eq(strncmp("hello", "hello", 5),
                   my_strncmp("hello", "hello", 5));
}
END_TEST

START_TEST(strncmp_test_basic_2) {
  ck_assert_int_eq(strncmp("hello", "hella", 4),
                   my_strncmp("hello", "hella", 4));
}
END_TEST

START_TEST(strncmp_test_basic_3) {
  ck_assert_int_eq(strncmp("hello", "world", 5),
                   my_strncmp("hello", "world", 5));
}
END_TEST

// Тест 2: граничный случай (NULL/пустая строка)
START_TEST(strncmp_test_empty_string_1) {
  ck_assert_int_eq(strncmp("", "", 5), my_strncmp("", "", 5));
}
END_TEST

START_TEST(strncmp_test_empty_string_2) {
  ck_assert_int_eq(strncmp("", "hello", 3), my_strncmp("", "hello", 3));
}
END_TEST

START_TEST(strncmp_test_empty_string_3) {
  ck_assert_int_eq(strncmp("hello", "", 3), my_strncmp("hello", "", 3));
}
END_TEST

// Тест 3:случай ошибки/не найден
START_TEST(strncmp_test_fail_1) {
  ck_assert_int_eq(strncmp("abc", "xyz", 3), my_strncmp("abc", "xyz", 3));
}
END_TEST

START_TEST(strncmp_test_fail_2) {
  ck_assert_int_eq(strncmp("123", "124", 3), my_strncmp("123", "124", 3));
}
END_TEST

START_TEST(strncmp_test_fail_3) {
  ck_assert_int_eq(strncmp("abcd", "abce", 4), my_strncmp("abcd", "abce", 4));
}
END_TEST

Suite *my_test_strncmp(void) {
  Suite *s = suite_create("STRNCMP");
  TCase *tc = tcase_create("strncmp");

  tcase_add_test(tc, strncmp_test_basic_1);
  tcase_add_test(tc, strncmp_test_basic_2);
  tcase_add_test(tc, strncmp_test_basic_3);

  tcase_add_test(tc, strncmp_test_empty_string_1);
  tcase_add_test(tc, strncmp_test_empty_string_2);
  tcase_add_test(tc, strncmp_test_empty_string_3);

  tcase_add_test(tc, strncmp_test_fail_1);
  tcase_add_test(tc, strncmp_test_fail_2);
  tcase_add_test(tc, strncmp_test_fail_3);

  suite_add_tcase(s, tc);
  return s;
}