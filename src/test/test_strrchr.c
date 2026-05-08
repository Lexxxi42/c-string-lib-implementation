#include "tests.h"

START_TEST(strrchr_1) {
  char str[] = "Hello, world!";
  int ch = 'o';
  ck_assert_ptr_eq(strrchr(str, ch), my_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_2) {
  char str[] = "Hello";
  int ch = 'z';
  ck_assert_ptr_eq(strrchr(str, ch), my_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_3) {
  char str[] = "Hello";
  int ch = '\0';
  ck_assert_ptr_eq(strrchr(str, ch), my_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_4) {
  char str[] = "";
  int ch = 'a';
  ck_assert_ptr_eq(strrchr(str, ch), my_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_5) {
  char str[] = "";
  int ch = '\0';
  ck_assert_ptr_eq(strrchr(str, ch), my_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_6) {
  char str[] = "Hello, world!";
  int ch = 'l';
  ck_assert_ptr_eq(strrchr(str, ch), my_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_7) {
  char str[] = "Hello\tWorld\n";
  int ch = '\t';
  ck_assert_ptr_eq(strrchr(str, ch), my_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_8) {
  char str[] = "Hello©World";
  int ch = 0xA9;

  ck_assert_ptr_eq(strrchr(str, ch), my_strrchr(str, ch));

  // printf("strrchr_8:\nstrrchr: \"%s\", my_strrchr: \"%s\"\n", strrchr(str,
  // ch), my_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_9) {
  char str[] = "Hello";
  int ch = -1;
  ck_assert_ptr_eq(strrchr(str, ch), my_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_10) {
  char str[] = "Hello";
  int ch = 300;
  ck_assert_ptr_eq(strrchr(str, ch), my_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_11) {
  char str[1000];
  memset(str, 'a', 999);
  str[999] = '\0';
  str[500] = 'X';
  int ch = 'X';
  ck_assert_ptr_eq(strrchr(str, ch), my_strrchr(str, ch));
}
END_TEST

Suite *my_test_strrchr(void) {
  Suite *s = suite_create("STRRCHR");
  TCase *tc = tcase_create("strrchr");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);
  tcase_add_test(tc, strrchr_9);
  tcase_add_test(tc, strrchr_10);
  tcase_add_test(tc, strrchr_11);

  suite_add_tcase(s, tc);
  return s;
}