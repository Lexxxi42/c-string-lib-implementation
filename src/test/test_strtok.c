#include "tests.h"

// Тест 1: Базовый
START_TEST(strtok_test_basic_1) {
  char str1[] = "hello;test|example";
  char str2[] = "hello;test|example";
  char delim[] = ";|";

  char *token1 = strtok(str1, delim);
  char *token2 = my_strtok(str2, delim);
  ck_assert_str_eq(token1, token2);

  token1 = strtok(NULL, delim);
  token2 = my_strtok(NULL, delim);
  ck_assert_str_eq(token1, token2);

  token1 = strtok(NULL, delim);
  token2 = my_strtok(NULL, delim);
  ck_assert_str_eq(token1, token2);
}
END_TEST

START_TEST(strtok_test_basic_2) {
  char str3[] = "hello world test example";
  char str4[] = "hello world test example";

  ck_assert_str_eq(strtok(str3, " "), my_strtok(str4, " "));
}
END_TEST

START_TEST(strtok_test_basic_3) {
  char str5[] = "hello world;test|example";
  char str6[] = "hello world;test|example";

  ck_assert_str_eq(strtok(str5, "|"), my_strtok(str6, "|"));
}
END_TEST

// Тест 2: граничный случай (NULL/пустая строка)
START_TEST(strtok_test_empty_string_1) {
  char str1[] = "";
  char str2[] = "";

  ck_assert_ptr_eq(strtok(str1, ","), my_strtok(str2, ","));
}
END_TEST

START_TEST(strtok_test_empty_string_2) {
  char str3[] = ",,,";
  char str4[] = ",,,";
  ck_assert_ptr_eq(strtok(str3, ","), my_strtok(str4, ","));
}
END_TEST

START_TEST(strtok_test_empty_string_3) {
  char str5[] = "hello world";
  char str6[] = "hello world";
  ck_assert_str_eq(strtok(str5, ""), my_strtok(str6, ""));
}
END_TEST

// Тест 3:случай ошибки/не найден
START_TEST(strtok_test_fail_1) {
  char str1[] = "hello world";
  char str2[] = "hello world";

  ck_assert_str_eq(strtok(str1, ","), my_strtok(str2, ","));
}
END_TEST

START_TEST(strtok_test_fail_2) {
  char str1[] = "hello world";
  char str2[] = "hello world";

  ck_assert_str_eq(strtok(str1, "|"), my_strtok(str2, "|"));
}
END_TEST

START_TEST(strtok_test_fail_3) {
  char str1[] = "hello world";
  char str2[] = "hello world";

  ck_assert_ptr_eq(strtok(str1, " helowrd"), my_strtok(str2, " helowrd"));

  // printf("fail_2:\nstrtok: \"%s\", my_strtok: \"%s\"\n", str1, str2);
}
END_TEST

Suite *my_test_strtok(void) {
  Suite *s = suite_create("STRTOK");
  TCase *tc = tcase_create("strtok");

  tcase_add_test(tc, strtok_test_basic_1);
  tcase_add_test(tc, strtok_test_basic_2);
  tcase_add_test(tc, strtok_test_basic_3);

  tcase_add_test(tc, strtok_test_empty_string_1);
  tcase_add_test(tc, strtok_test_empty_string_2);
  tcase_add_test(tc, strtok_test_empty_string_3);

  tcase_add_test(tc, strtok_test_fail_1);
  tcase_add_test(tc, strtok_test_fail_2);
  tcase_add_test(tc, strtok_test_fail_3);

  suite_add_tcase(s, tc);
  return s;
}
