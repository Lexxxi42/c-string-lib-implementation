#include "tests.h"

START_TEST(memcmp_1) {
  char str1[] = "Hello";
  char str2[] = "Hellp";
  ck_assert_int_eq(memcmp(str1, str2, 5), my_memcmp(str1, str2, 5));
}
END_TEST

START_TEST(memcmp_2) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  ck_assert_int_eq(memcmp(str1, str2, 0), my_memcmp(str1, str2, 0));
}
END_TEST

START_TEST(memcmp_3) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(memcmp(str1, str2, 1), my_memcmp(str1, str2, 1));
}
END_TEST

START_TEST(memcmp_4) {
  char str1[] = "";
  char str2[] = "Hello";
  ck_assert_int_eq(memcmp(str1, str2, 1), my_memcmp(str1, str2, 1));
}
END_TEST

START_TEST(memcmp_5) {
  char str1[] = "Hello World";
  char str2[] = "Hello Youuu";
  ck_assert_int_eq(memcmp(str1, str2, 6), my_memcmp(str1, str2, 6));
}
END_TEST

START_TEST(memcmp_6) {
  unsigned char data1[] = {0x00, 0x01, 0x02, 0x03};
  unsigned char data2[] = {0x00, 0x01, 0x02, 0x04};
  ck_assert_int_eq(memcmp(data1, data2, 4), my_memcmp(data1, data2, 4));
}
END_TEST

START_TEST(memcmp_7) {
  char str1[] = "Hello\0World";
  char str2[] = "Hello\0There";
  ck_assert_int_eq(memcmp(str1, str2, 11), my_memcmp(str1, str2, 11));
}
END_TEST

START_TEST(memcmp_8) {
  struct test_struct {
    int a;
    char b;
    double c;
  };
  struct test_struct s1 = {1, 'A', 3.14};
  struct test_struct s2 = {1, 'A', 3.14};
  struct test_struct s3 = {1, 'B', 3.14};

  ck_assert_int_eq(memcmp(&s1, &s2, sizeof(s1)),
                   my_memcmp(&s1, &s2, sizeof(s1)));
  ck_assert_int_eq(memcmp(&s1, &s3, sizeof(s1)),
                   my_memcmp(&s1, &s3, sizeof(s1)));
}
END_TEST

START_TEST(memcmp_9) {
  char *str1 = (char *)0x1;
  char *str2 = (char *)0x2;
  ck_assert_int_eq(memcmp(str1, str2, 0), my_memcmp(str1, str2, 0));
}
END_TEST

Suite *my_test_memcmp(void) {
  Suite *s = suite_create("MEMCMP");
  TCase *tc = tcase_create("memcmp");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);
  //   tcase_add_test(tc, memcmp_10);
  //   tcase_add_test(tc, memcmp_11);
  //   tcase_add_test(tc, memcmp_12);

  suite_add_tcase(s, tc);
  return s;
}