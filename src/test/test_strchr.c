#include "tests.h"

// Тест 1: Базовый
START_TEST(strchr_test_basic_1) {
  const char *str = "Hello, World!";
  ck_assert_ptr_eq(strchr(str, 'H'), my_strchr(str, 'H'));
}
END_TEST

START_TEST(strchr_test_basic_2) {
  const char *str = "Hello, World!";
  ck_assert_ptr_eq(strchr(str, ' '), my_strchr(str, ' '));
}
END_TEST

START_TEST(strchr_test_basic_3) {
  const char *str = "Hello, World!";

  ck_assert_ptr_eq(strchr(str, '\0'), my_strchr(str, '\0'));
}
END_TEST

// Тест 2: граничный случай (NULL/пустая строка)
START_TEST(strchr_test_empty_string_1) {
  const char *str = "";

  ck_assert_ptr_eq(strchr(str, 'a'), my_strchr(str, 'a'));
}
END_TEST

START_TEST(strchr_test_empty_string_2) {
  const char *str = "";

  ck_assert_ptr_eq(strchr(str, '\0'), my_strchr(str, '\0'));
}
END_TEST

START_TEST(strchr_test_empty_string_3) {
  const char *str = "";
  ck_assert_ptr_eq(strchr(str, ' '), my_strchr(str, ' '));
}
END_TEST

// Тест 3:случай ошибки/не найден
START_TEST(strchr_test_fail_1) {
  const char *str = "Hello, World!";

  ck_assert_ptr_eq(strchr(str, 'z'), my_strchr(str, 'z'));
}
END_TEST

START_TEST(strchr_test_fail_2) {
  const char *str = "Hello, World!";

  ck_assert_ptr_eq(strchr(str, 'a'), my_strchr(str, 'a'));
}
END_TEST

START_TEST(strchr_test_fail_3) {
  const char *str = "Hello, World!";

  ck_assert_ptr_eq(strchr(str, 'h'), my_strchr(str, 'h'));
}
END_TEST

START_TEST(strchr_test_special_1) {
  char str[] = "Hello©World";
  int ch = 0xA9;

  ck_assert_ptr_eq(strchr(str, ch), my_strchr(str, ch));

  // printf("strrchr_8:\nstrrchr: \"%s\", my_strrchr: \"%s\"\n", strrchr(str,
  // ch), my_strrchr(str, ch));
}

Suite *my_test_strchr(void) {
  Suite *s = suite_create("STRCHR");
  TCase *tc = tcase_create("strchr");

  tcase_add_test(tc, strchr_test_basic_1);
  tcase_add_test(tc, strchr_test_basic_2);
  tcase_add_test(tc, strchr_test_basic_3);

  tcase_add_test(tc, strchr_test_empty_string_1);
  tcase_add_test(tc, strchr_test_empty_string_2);
  tcase_add_test(tc, strchr_test_empty_string_3);

  tcase_add_test(tc, strchr_test_fail_1);
  tcase_add_test(tc, strchr_test_fail_2);
  tcase_add_test(tc, strchr_test_fail_3);

  tcase_add_test(tc, strchr_test_special_1);

  suite_add_tcase(s, tc);
  return s;
}