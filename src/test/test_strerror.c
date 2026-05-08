#include "tests.h"

// Тест 1: Базовый
START_TEST(strerror_test_basic_1) {
  ck_assert_str_eq(strerror(10), my_strerror(10));
}
END_TEST

START_TEST(strerror_test_basic_2) {
  ck_assert_str_eq(strerror(25), my_strerror(25));
}
END_TEST

START_TEST(strerror_test_basic_3) {
  ck_assert_str_eq(strerror(50), my_strerror(50));
}
END_TEST

// Тест 2: граничный случай (NULL/пустая строка)
START_TEST(strerror_test_empty_string_1) {
  ck_assert_str_eq(strerror(0), my_strerror(0));
}
END_TEST

START_TEST(strerror_test_empty_string_2) {
  ck_assert_str_eq(strerror(133), my_strerror(133));
}
END_TEST

START_TEST(strerror_test_empty_string_3) {
  ck_assert_str_eq(strerror(106), my_strerror(106));
}
END_TEST

// Тест 3:случай ошибки/не найден
START_TEST(strerror_test_fail_1) {
  ck_assert_str_eq(strerror(-1), my_strerror(-1));
}
END_TEST

START_TEST(strerror_test_fail_2) {
  ck_assert_str_eq(strerror(150), my_strerror(150));
}
END_TEST

START_TEST(strerror_test_fail_3) {
  ck_assert_str_eq(strerror(999), my_strerror(999));
}
END_TEST

Suite *my_test_strerror(void) {
  Suite *s = suite_create("STRERROR");
  TCase *tc = tcase_create("strerror");

  tcase_add_test(tc, strerror_test_basic_1);
  tcase_add_test(tc, strerror_test_basic_2);
  tcase_add_test(tc, strerror_test_basic_3);

  tcase_add_test(tc, strerror_test_empty_string_1);
  tcase_add_test(tc, strerror_test_empty_string_2);
  tcase_add_test(tc, strerror_test_empty_string_3);

  tcase_add_test(tc, strerror_test_fail_1);
  tcase_add_test(tc, strerror_test_fail_2);
  tcase_add_test(tc, strerror_test_fail_3);

  suite_add_tcase(s, tc);
  return s;
}