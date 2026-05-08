#include "tests.h"

// Тест 1: Базовый
START_TEST(strncat_test_basic_1) {
  char dest1[20] = "hello";
  char dest2[20] = "hello";
  const char src1[] = " world";

  ck_assert_str_eq(strncat(dest1, src1, 3), my_strncat(dest2, src1, 3));
}
END_TEST

START_TEST(strncat_test_basic_2) {
  char dest3[20] = "test";
  char dest4[20] = "test";
  const char src2[] = "!";
  ck_assert_str_eq(strncat(dest3, src2, 1), my_strncat(dest4, src2, 1));
}
END_TEST

START_TEST(strncat_test_basic_3) {
  char dest5[20] = "start";
  char dest6[20] = "start";
  const char src3[] = "end";
  ck_assert_str_eq(strncat(dest5, src3, 3), my_strncat(dest6, src3, 3));
}
END_TEST

// Тест 2: граничный случай (NULL/пустая строка)
START_TEST(strncat_test_empty_string_1) {
  char dest1[20] = "";
  char dest2[20] = "";
  const char src1[] = "world!";
  ck_assert_str_eq(strncat(dest1, src1, 2), my_strncat(dest2, src1, 2));
}
END_TEST

START_TEST(strncat_test_empty_string_2) {
  char dest3[20] = "hello";
  char dest4[20] = "hello";
  const char src2[] = "";
  ck_assert_str_eq(strncat(dest3, src2, 5), my_strncat(dest4, src2, 5));
}
END_TEST

START_TEST(strncat_test_empty_string_3) {
  char dest5[20] = "";
  char dest6[20] = "";
  const char src3[] = "";
  ck_assert_str_eq(strncat(dest5, src3, 3), my_strncat(dest6, src3, 3));
}
END_TEST

// Тест 3:случай ошибки/не найден
START_TEST(strncat_test_fail_1) {
  char dest1[20] = "hello";
  char dest2[20] = "hello";
  const char src1[] = " world";
  ck_assert_str_eq(strncat(dest1, src1, 0), my_strncat(dest2, src1, 0));
}
END_TEST

START_TEST(strncat_test_fail_2) {
  char dest3[20] = "hello";
  char dest4[20] = "hello";
  const char src2[] = " world";
  ck_assert_str_eq(strncat(dest3, src2, 0), my_strncat(dest4, src2, 0));
}
END_TEST

START_TEST(strncat_test_fail_3) {
  char dest5[9] = "hello";
  char dest6[9] = "hello";
  const char src3[] = "123";
  ck_assert_str_eq(strncat(dest5, src3, 3), my_strncat(dest6, src3, 4));
}
END_TEST

Suite *my_test_strncat(void) {
  Suite *s = suite_create("STRNCAT");
  TCase *tc = tcase_create("strncat");

  tcase_add_test(tc, strncat_test_basic_1);
  tcase_add_test(tc, strncat_test_basic_2);
  tcase_add_test(tc, strncat_test_basic_3);

  tcase_add_test(tc, strncat_test_empty_string_1);
  tcase_add_test(tc, strncat_test_empty_string_2);
  tcase_add_test(tc, strncat_test_empty_string_3);

  tcase_add_test(tc, strncat_test_fail_1);
  tcase_add_test(tc, strncat_test_fail_2);
  tcase_add_test(tc, strncat_test_fail_3);

  suite_add_tcase(s, tc);
  return s;
}