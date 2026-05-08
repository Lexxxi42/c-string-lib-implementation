#include "tests.h"

START_TEST(strcspn_1) {
  char str[] = "Hello, world!";
  char reject[] = " ,!";
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

START_TEST(strcspn_2) {
  char str[] = "Hello";
  char reject[] = "aeiou";
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

START_TEST(strcspn_3) {
  char str[] = "Hello";
  char reject[] = "xyz";
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

START_TEST(strcspn_4) {
  char str[] = "";
  char reject[] = "a";
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

START_TEST(strcspn_5) {
  char str[] = "Hello";
  char reject[] = "";
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

START_TEST(strcspn_6) {
  char str[] = "";
  char reject[] = "";
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

START_TEST(strcspn_7) {
  char str[] = "Apple";
  char reject[] = "A";
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

START_TEST(strcspn_8) {
  char str[] = "Helloo";
  char reject[] = "o";
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

START_TEST(strcspn_9) {
  char str[] = "Hello, world!";
  char reject[] = "ol";
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

START_TEST(strcspn_10) {
  char str[] = "Hello\tWorld\n";
  char reject[] = "\t\n";
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

START_TEST(strcspn_11) {
  char str[] = "Hello©World";
  char reject[] = "©";
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

START_TEST(strcspn_12) {
  char str[1000];
  char reject[] = "X";
  memset(str, 'a', 999);
  str[999] = '\0';
  str[500] = 'X';
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

START_TEST(strcspn_13) {
  char str[] = "Hello";
  char reject[1000];
  memset(reject, 'x', 999);
  reject[999] = '\0';
  reject[500] = 'H';
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

START_TEST(strcspn_14) {
  char str[] = "Hello";
  char reject[] = "\0abc";
  ck_assert_int_eq(strcspn(str, reject), my_strcspn(str, reject));
}
END_TEST

Suite *my_test_strcspn(void) {
  Suite *s = suite_create("STRCSPN");
  TCase *tc = tcase_create("strcspn");

  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);
  tcase_add_test(tc, strcspn_7);
  tcase_add_test(tc, strcspn_8);
  tcase_add_test(tc, strcspn_9);
  tcase_add_test(tc, strcspn_10);
  tcase_add_test(tc, strcspn_11);
  tcase_add_test(tc, strcspn_12);
  tcase_add_test(tc, strcspn_13);
  tcase_add_test(tc, strcspn_14);

  suite_add_tcase(s, tc);
  return s;
}