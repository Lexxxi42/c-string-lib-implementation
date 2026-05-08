#include "tests.h"

START_TEST(strncpy_1) {
  char dest1[20] = {0};
  char dest2[20] = {0};
  char src[] = "Hello World";
  ck_assert_str_eq(strncpy(dest1, src, 11), my_strncpy(dest2, src, 11));
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_2) {
  char dest1[20] = "Initial Value";
  char dest2[20] = "Initial Value";
  char src[] = "Hello";
  ck_assert_str_eq(strncpy(dest1, src, 3), my_strncpy(dest2, src, 3));
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_3) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "\0";
  my_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), my_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_4) {
  char dest1[20] = "AAAAAAAAAA";
  char dest2[20] = "AAAAAAAAAA";
  char src[] = "Hi";
  ck_assert_str_eq(strncpy(dest1, src, 5), my_strncpy(dest2, src, 5));
  ck_assert_int_eq(memcmp(dest1, dest2, 5), 0);
}
END_TEST

START_TEST(strncpy_5) {
  char dest1[5] = {0};
  char dest2[5] = {0};
  char src[] = "Very Long String";
  ck_assert_mem_eq(strncpy(dest1, src, 5), my_strncpy(dest2, src, 5), 5);
}
END_TEST

START_TEST(strncpy_6) {
  char dest1[20] = "Hello";
  char dest2[20] = "Hello";
  char src[] = "";
  ck_assert_str_eq(strncpy(dest1, src, 5), my_strncpy(dest2, src, 5));
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_7) {
  char dest1[20] = "Initial Text";
  char dest2[20] = "Initial Text";
  char src[] = "Hello\0World";
  ck_assert_str_eq(strncpy(dest1, src, 11), my_strncpy(dest2, src, 11));
  ck_assert_int_eq(memcmp(dest1, dest2, 11), 0);
}
END_TEST

START_TEST(strncpy_8) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "";
  my_size_t n = 0;
  ck_assert_pstr_eq(strncpy(s1, s3, n), my_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_9) {
  char str1[20] = "Hello World";
  char str2[20] = "Hello World";
  ck_assert_pstr_eq(strncpy(str1, str1 + 3, 5), my_strncpy(str2, str2 + 3, 5));
}
END_TEST

START_TEST(strncpy_14) {
  char s1[70] = "";
  char s2[70] = "";
  char s3[] =
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
  my_size_t n = strlen(s3);
  ck_assert_pstr_eq(strncpy(s1, s3, n), my_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_10) {
  char dest1[6] = {0};
  char dest2[6] = {0};
  char src[] = "Hello";
  ck_assert_str_eq(strncpy(dest1, src, 5), my_strncpy(dest2, src, 5));
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_11) {
  char dest1[100] = {0};
  char dest2[100] = {0};
  char src[] = "Test";
  ck_assert_str_eq(strncpy(dest1, src, 50), my_strncpy(dest2, src, 50));
  ck_assert_int_eq(memcmp(dest1, dest2, 50), 0);
}
END_TEST

START_TEST(strncpy_12) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "\0";
  my_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), my_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_13) {
  char dest1[10];
  char dest2[10];
  char src[] = "Hello";
  strncpy(dest1, src, 3);
  my_strncpy(dest2, src, 3);
  ck_assert_int_eq(memcmp(dest1, dest2, 3), 0);
}
END_TEST

Suite *my_test_strncpy(void) {
  Suite *s = suite_create("STRNCPY");
  TCase *tc = tcase_create("strncpy");

  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, strncpy_6);
  tcase_add_test(tc, strncpy_7);
  tcase_add_test(tc, strncpy_8);
  tcase_add_test(tc, strncpy_9);
  tcase_add_test(tc, strncpy_10);
  tcase_add_test(tc, strncpy_11);
  tcase_add_test(tc, strncpy_12);
  tcase_add_test(tc, strncpy_13);
  tcase_add_test(tc, strncpy_14);

  suite_add_tcase(s, tc);
  return s;
}