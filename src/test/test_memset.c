#include "tests.h"

//// MEMSET
START_TEST(memset_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  my_size_t n = my_strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), my_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_2) {
  const char *str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  ck_assert_int_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(memset_3) {
  char s1[] = "";
  char s2[] = "";
  int ch = '\0';
  my_size_t n = my_strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), my_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = 80;
  my_size_t n = my_strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), my_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_5) {
  char s1[] = "\0";
  char s2[] = "\0";
  int ch = ' ';
  my_size_t n = my_strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), my_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  my_size_t n = my_strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), my_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_7) {
  char s1[] = "";
  char s2[] = "";
  int ch = ' ';
  my_size_t n = my_strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), my_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_8) {
  char s1[] = "\n\n\n\n\n\n\n\n\nstrlen\n\n\n\n\n";
  char s2[] = "\n\n\n\n\n\n\n\n\nstrlen\n\n\n\n\n";
  int ch = ' ';
  my_size_t n = my_strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), my_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_9) {
  char s1[] = "\0\0\0\0\n";
  char s2[] = "\0\0\0\0\n";
  int ch = ' ';
  my_size_t n = my_strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), my_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_10) {
  char s1[] = "\t\t";
  char s2[] = "\t\t";
  int ch = ' ';
  my_size_t n = my_strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), my_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_11) {
  char s1[] = "\0test";
  char s2[] = "\0test";
  int ch = ' ';
  my_size_t n = my_strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), my_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_12) {
  char s1[] = "wtf \0 wtf";
  char s2[] = "wtf \0 wtf";
  int ch = ' ';
  my_size_t n = my_strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), my_memset(s2, ch, n));
}
END_TEST

Suite *my_test_memset(void) {
  Suite *s = suite_create("MEMSET");
  TCase *tc = tcase_create("memset");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);
  tcase_add_test(tc, memset_6);
  tcase_add_test(tc, memset_7);
  tcase_add_test(tc, memset_8);
  tcase_add_test(tc, memset_9);
  tcase_add_test(tc, memset_10);
  tcase_add_test(tc, memset_11);
  tcase_add_test(tc, memset_12);

  suite_add_tcase(s, tc);
  return s;
}