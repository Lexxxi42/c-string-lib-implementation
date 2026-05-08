#include "tests.h"

START_TEST(strpbrk_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_pstr_eq(strpbrk(s1, s2), my_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_2) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strpbrk(s1, s2), my_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_3) {
  char s1[] = "";
  char s2[] = "He";
  ck_assert_pstr_eq(strpbrk(s1, s2), my_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_4) {
  char s1[] = "\0";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), my_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), my_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_6) {
  char s1[] = "1242434246364377659";
  char s2[] = "364377659";
  ck_assert_pstr_eq(strpbrk(s1, s2), my_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_7) {
  char str[] = "Hello";
  char accept[] = "xyz";
  ck_assert_ptr_eq(strpbrk(str, accept), my_strpbrk(str, accept));
}
END_TEST

START_TEST(strpbrk_8) {
  char str[] = "Hello©World";
  char accept[] = "©";
  ck_assert_ptr_eq(strpbrk(str, accept), my_strpbrk(str, accept));
}
END_TEST

START_TEST(strpbrk_9) {
  char str[] = "Hello\tWorld\n";
  char accept[] = "\t\n";
  ck_assert_ptr_eq(strpbrk(str, accept), my_strpbrk(str, accept));
}
END_TEST

START_TEST(strpbrk_10) {
  char str[] = "Hello";
  char accept[] = "\0abc";
  ck_assert_ptr_eq(strpbrk(str, accept), my_strpbrk(str, accept));
}
END_TEST

START_TEST(strpbrk_11) {
  char str[] = "Hello";
  char accept[1000];
  memset(accept, 'x', 999);
  accept[999] = '\0';
  accept[500] = 'H';
  ck_assert_ptr_eq(strpbrk(str, accept), my_strpbrk(str, accept));
}
END_TEST

Suite *my_test_strpbrk(void) {
  Suite *s = suite_create("STRPBRK");
  TCase *tc = tcase_create("strpbrk");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  tcase_add_test(tc, strpbrk_6);
  tcase_add_test(tc, strpbrk_7);
  tcase_add_test(tc, strpbrk_8);
  tcase_add_test(tc, strpbrk_9);
  tcase_add_test(tc, strpbrk_10);
  tcase_add_test(tc, strpbrk_11);

  suite_add_tcase(s, tc);
  return s;
}
