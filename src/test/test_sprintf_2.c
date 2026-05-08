#include "tests.h"
#define BUFFER 512

#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

START_TEST(test_g_specifier) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];

  int result1 = my_sprintf(buffer_1, "%g", 123.456);
  int result2 = sprintf(buffer_2, "%g", 123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.*g", 3, 123.456789);
  result2 = sprintf(buffer_2, "%.*g", 3, 123.456789);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.*G", 0, 0.0);
  result2 = sprintf(buffer_2, "%.*G", 0, 0.0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.0G", 0.0);
  result2 = sprintf(buffer_2, "%.0G", 0.0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.*g", 0, 123.456789);
  result2 = sprintf(buffer_2, "%.*g", 0, 123.456789);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.G", 123.456);
  result2 = sprintf(buffer_2, "%.G", 123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*g", 10, 123.456);
  result2 = sprintf(buffer_2, "%*g", 10, 123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*.*g", 12, 2, 1234.5678);
  result2 = sprintf(buffer_2, "%*.*g", 12, 2, 1234.5678);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%#.*g", 4, 100.0);
  result2 = sprintf(buffer_2, "%#.*g", 4, 100.0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*g", 8, 123.456);
  result2 = sprintf(buffer_2, "%*g", 8, 123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.*g", 5, 1e-10);
  result2 = sprintf(buffer_2, "%.*g", 5, 1e-10);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*.*g", 15, 3, -123.456);
  result2 = sprintf(buffer_2, "%*.*g", 15, 3, -123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%+*.*g", 10, 2, 123.456);
  result2 = sprintf(buffer_2, "%+*.*g", 10, 2, 123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%#4.g", 3.11);
  result2 = sprintf(buffer_2, "%#4.g", 3.11);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.Lg", 123.45L);
  result2 = sprintf(buffer_2, "%.Lg", 123.45L);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.LG", 123.45L);
  result2 = sprintf(buffer_2, "%.LG", 123.45L);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
}
END_TEST

// ==================== Спецификатор e/E ====================

START_TEST(test_e_specifier) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];

  int result1 = my_sprintf(buffer_1, "%.*e", 3, 123.456789);
  int result2 = sprintf(buffer_2, "%.*e", 3, 123.456789);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*E", 15, 123.456);
  result2 = sprintf(buffer_2, "%*E", 15, 123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*.*e", 18, 4, 123.456789);
  result2 = sprintf(buffer_2, "%*.*e", 18, 4, 123.456789);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%#.*e", 2, 100.0);
  result2 = sprintf(buffer_2, "%#.*e", 2, 100.0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%#.*E", 0, 100.0);
  result2 = sprintf(buffer_2, "%#.*E", 0, 100.0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%0*e", 15, 123.456);
  result2 = sprintf(buffer_2, "%0*e", 15, 123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.*e", 0, 123.456);
  result2 = sprintf(buffer_2, "%.*e", 0, 123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%-*e", 15, 123.456);
  result2 = sprintf(buffer_2, "%-*e", 15, 123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%+*.*e", 12, 3, 123.456);
  result2 = sprintf(buffer_2, "%+*.*e", 12, 3, 123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "% *e", 15, 123.456);
  result2 = sprintf(buffer_2, "% *e", 15, 123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*.*e", 16, 2, -123.456);
  result2 = sprintf(buffer_2, "%*.*e", 16, 2, -123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%#.e", 3.11);
  result2 = sprintf(buffer_2, "%#.e", 3.11);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.E", 3.11);
  result2 = sprintf(buffer_2, "%.E", 3.11);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.4E", 1e-8);
  result2 = sprintf(buffer_2, "%.4E", 1e-8);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 =
      my_sprintf(buffer_1, "%*.*e | %*.*E", 10, 2, 123.456, 12, 3, 789.123);
  result2 = sprintf(buffer_2, "%*.*e | %*.*E", 10, 2, 123.456, 12, 3, 789.123);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.Le", 123.45L);
  result2 = sprintf(buffer_2, "%.Le", 123.45L);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.LE", 123.45L);
  result2 = sprintf(buffer_2, "%.LE", 123.45L);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
}
END_TEST

// ==================== Спецификатор x/X ====================

START_TEST(test_x_specifier) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];

  int result1 = my_sprintf(buffer_1, "%.*x", 5, 255);
  int result2 = sprintf(buffer_2, "%.*x", 5, 255);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*X", 10, 255);
  result2 = sprintf(buffer_2, "%*X", 10, 255);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*.*x", 12, 6, 255);
  result2 = sprintf(buffer_2, "%*.*x", 12, 6, 255);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%#.*x", 5, 255);
  result2 = sprintf(buffer_2, "%#.*x", 5, 255);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%0*x", 10, 255);
  result2 = sprintf(buffer_2, "%0*x", 10, 255);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%-*x", 10, 255);
  result2 = sprintf(buffer_2, "%-*x", 10, 255);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.*x", 5, 0);
  result2 = sprintf(buffer_2, "%.*x", 5, 0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.*x", 0, 0);
  result2 = sprintf(buffer_2, "%.*x", 0, 0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.*x", 0, 5);
  result2 = sprintf(buffer_2, "%.*x", 0, 5);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*.*x", 15, 8, UINT_MAX);
  result2 = sprintf(buffer_2, "%*.*x", 15, 8, UINT_MAX);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%#*X", 10, 255);
  result2 = sprintf(buffer_2, "%#*X", 10, 255);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%#-*.*x", 12, 6, 255);
  result2 = sprintf(buffer_2, "%#-*.*x", 12, 6, 255);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.hx", (short)12345);
  result2 = sprintf(buffer_2, "%.hx", (short)12345);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.lx", 123456789123456789L);
  result2 = sprintf(buffer_2, "%.lx", 123456789123456789L);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.hX", (short)123);
  result2 = sprintf(buffer_2, "%.hX", (short)123);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.lX", 123456789123456789L);
  result2 = sprintf(buffer_2, "%.lX", 123456789123456789L);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
}
END_TEST

// ==================== Спецификатор o ====================

START_TEST(test_o_specifier) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];

  int result1 = my_sprintf(buffer_1, "%.*o", 5, 64);
  int result2 = sprintf(buffer_2, "%.*o", 5, 64);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*o", 10, 64);
  result2 = sprintf(buffer_2, "%*o", 10, 64);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*.*o", 12, 6, 64);
  result2 = sprintf(buffer_2, "%*.*o", 12, 6, 64);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%#.*o", 5, 64);
  result2 = sprintf(buffer_2, "%#.*o", 5, 64);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%0*o", 10, 64);
  result2 = sprintf(buffer_2, "%0*o", 10, 64);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%-*o", 10, 64);
  result2 = sprintf(buffer_2, "%-*o", 10, 64);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.*o", 5, 0);
  result2 = sprintf(buffer_2, "%.*o", 5, 0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%#*o", 8, 0);
  result2 = sprintf(buffer_2, "%#*o", 8, 0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*.*o", 20, 10, UINT_MAX);
  result2 = sprintf(buffer_2, "%*.*o", 20, 10, UINT_MAX);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%#-*.*o", 15, 8, 64);
  result2 = sprintf(buffer_2, "%#-*.*o", 15, 8, 64);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%#.*o", 0, 0);
  result2 = sprintf(buffer_2, "%#.*o", 0, 0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.*o", 0, 0);
  result2 = sprintf(buffer_2, "%.*o", 0, 0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.ho", (short)12345);
  result2 = sprintf(buffer_2, "%.ho", (short)12345);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.lo", 123456789123456789L);
  result2 = sprintf(buffer_2, "%.lo", 123456789123456789L);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
}
END_TEST

// ==================== Спецификатор p ====================

START_TEST(test_p_specifier) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];
  int x = 42;
  char str[] = "test";
  void *ptr1 = &x;
  void *ptr2 = str;

  int result1 = my_sprintf(buffer_1, "%*p", 15, ptr1);
  int result2 = sprintf(buffer_2, "%*p", 15, ptr1);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%-*p", 15, ptr1);
  result2 = sprintf(buffer_2, "%-*p", 15, ptr1);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*p", 10, NULL);
  result2 = sprintf(buffer_2, "%*p", 10, NULL);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*p", -15, ptr1);
  result2 = sprintf(buffer_2, "%*p", -15, ptr1);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*p", 12, (void *)0);
  result2 = sprintf(buffer_2, "%*p", 12, (void *)0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  int arr[3] = {1, 2, 3};

  result1 = my_sprintf(buffer_1, "%*p", 18, &arr[1]);
  result2 = sprintf(buffer_2, "%*p", 18, &arr[1]);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*p %*p", 10, ptr1, 12, ptr2);
  result2 = sprintf(buffer_2, "%*p %*p", 10, ptr1, 12, ptr2);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "Address: %*p", 15, ptr1);
  result2 = sprintf(buffer_2, "Address: %*p", 15, ptr1);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*p", 30, ptr1);
  result2 = sprintf(buffer_2, "%*p", 30, ptr1);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%*p", 0, ptr1);
  result2 = sprintf(buffer_2, "%*p", 0, ptr1);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
}
END_TEST

Suite *my_test_sprintf_2(void) {
  Suite *s = suite_create("SPRINTF_2");
  TCase *tc = tcase_create("sprintf_2");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_g_specifier);
  tcase_add_test(tc, test_e_specifier);
  tcase_add_test(tc, test_x_specifier);
  tcase_add_test(tc, test_o_specifier);
  tcase_add_test(tc, test_p_specifier);

  suite_add_tcase(s, tc);
  return s;
}