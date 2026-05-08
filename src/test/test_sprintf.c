#include "tests.h"
#define BUFFER 1024

// !
// ||--------------------------------------------------------------------------------||
// ! ||                                     s flag || !
// ||--------------------------------------------------------------------------------||

START_TEST(sprintf_1_s_flag) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];
  char *test = "hello world";

  int result1 = my_sprintf(buffer_1, "%s", test);
  int result2 = sprintf(buffer_2, "%s", test);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%10s", test);
  result2 = sprintf(buffer_2, "%10s", test);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%-10s", test);
  result2 = sprintf(buffer_2, "%-10s", test);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%-10.5s", test);
  result2 = sprintf(buffer_2, "%-10.5s", test);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%100s", "test");
  result2 = sprintf(buffer_2, "%100s", "test");

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "empty:'%s'", "");
  result2 = sprintf(buffer_2, "empty:'%s'", "");

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "spaces:'%s'", "   ");
  result2 = sprintf(buffer_2, "spaces:'%s'", "   ");

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "special:'%s'", "test\n\t\r\0test");
  result2 = sprintf(buffer_2, "special:'%s'", "test\n\t\r\0test");

  ck_assert_int_eq(result1, result2);
}
END_TEST

// !
// ||--------------------------------------------------------------------------------||
// ! ||                                     percent || !
// ||--------------------------------------------------------------------------------||

START_TEST(sprintf_2_percent) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];

  int result1 = my_sprintf(buffer_1, "hello world 100%%");
  int result2 = sprintf(buffer_2, "hello world 100%%");

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%%\t55%%\n%%");
  result2 = sprintf(buffer_2, "%%\t55%%\n%%");

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
}
END_TEST

// !
// ||--------------------------------------------------------------------------------||
// ! ||                                     c flag || !
// ||--------------------------------------------------------------------------------||

START_TEST(sprintf_3_c_flag) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];
  char test = 'X';

  int result1 = my_sprintf(buffer_1, "%5c", test);
  int result2 = sprintf(buffer_2, "%5c", test);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%-5c", test);
  result2 = sprintf(buffer_2, "%-5c", test);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%-5c", test);
  result2 = sprintf(buffer_2, "%-5c", test);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "chars: %c %c %c %c", 'A', '\0', '\n', 255);
  result2 = sprintf(buffer_2, "chars: %c %c %c %c", 'A', '\0', '\n', 255);

  ck_assert_int_eq(result1, result2);

  result1 = my_sprintf(buffer_1, "char:%5c char:%-5c", 'X', 'X');
  result2 = sprintf(buffer_2, "char:%5c char:%-5c", 'X', 'X');

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%-1022c", 'X');
  result2 = sprintf(buffer_2, "%-1022c", test);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
}
END_TEST

// !
// ||--------------------------------------------------------------------------------||
// ! ||                                     d flag || !
// ||--------------------------------------------------------------------------------||

START_TEST(sprintf_4_d_flag) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];

  int result1 = my_sprintf(buffer_1, "%d", 21);
  int result2 = sprintf(buffer_2, "%d", 21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%d", -21);
  result2 = sprintf(buffer_2, "%d", -21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%5d", -21);
  result2 = sprintf(buffer_2, "%5d", -21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%05d", -21);
  result2 = sprintf(buffer_2, "%05d", -21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
  result1 = my_sprintf(buffer_1, "%-5d", -21);
  result2 = sprintf(buffer_2, "%-5d", -21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%+d", -21);
  result2 = sprintf(buffer_2, "%+d", -21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "% d", -21);
  result2 = sprintf(buffer_2, "% d", -21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%0d", -21);
  result2 = sprintf(buffer_2, "%0d", -21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%d", -1);
  result2 = sprintf(buffer_2, "%d", -1);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%d", 21);
  result2 = sprintf(buffer_2, "%d", 21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%5d", 21);
  result2 = sprintf(buffer_2, "%5d", 21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
  result1 = my_sprintf(buffer_1, "%05d", 21);
  result2 = sprintf(buffer_2, "%05d", 21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
  result1 = my_sprintf(buffer_1, "%-5d", 21);
  result2 = sprintf(buffer_2, "%-5d", 21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%+d", 21);
  result2 = sprintf(buffer_2, "%+d", 21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
  result1 = my_sprintf(buffer_1, "% d", 21);
  result2 = sprintf(buffer_2, "% d", 21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
  result1 = my_sprintf(buffer_1, "%0d", 21);
  result2 = sprintf(buffer_2, "%0d", 21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%d", 1);
  result2 = sprintf(buffer_2, "%d", 1);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%d", INT32_MAX);
  result2 = sprintf(buffer_2, "%d", INT32_MAX);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "% .50d", 21);
  result2 = sprintf(buffer_2, "% .50d", 21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.*d", 5, 21);
  result2 = sprintf(buffer_2, "%.*d", 5, 21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%d", 1);
  result2 = sprintf(buffer_2, "%d", 1);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%d", INT32_MAX);
  result2 = sprintf(buffer_2, "%d", INT32_MAX);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.ld", 123456789123456789);
  result2 = sprintf(buffer_2, "%.ld", 123456789123456789);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.hd", (short)12345);
  result2 = sprintf(buffer_2, "%.hd", (short)12345);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.ld", 12345678912345L);
  result2 = sprintf(buffer_2, "%.ld", 12345678912345L);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
}
END_TEST

// !
// ||--------------------------------------------------------------------------------||
// ! ||                                     f flag || !
// ||--------------------------------------------------------------------------------||

START_TEST(sprintf_5_f_flag) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];

  int result1 = my_sprintf(buffer_1, "%f", 21.21);
  int result2 = sprintf(buffer_2, "%f", 21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
  result1 = my_sprintf(buffer_1, "%.2f", -21.21);
  result2 = sprintf(buffer_2, "%.2f", -21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
  result1 = my_sprintf(buffer_1, "%5f", -21.21);
  result2 = sprintf(buffer_2, "%5f", -21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%05f", -21.21);
  result2 = sprintf(buffer_2, "%05f", -21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%-5f", -21.21);
  result2 = sprintf(buffer_2, "%-5f", -21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%+f", -21.21);
  result2 = sprintf(buffer_2, "%+f", -21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "% f", -21.21);
  result2 = sprintf(buffer_2, "% f", -21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%0f", -21.21);
  result2 = sprintf(buffer_2, "%0f", -21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%f", -1.01);
  result2 = sprintf(buffer_2, "%f", -1.01);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%f", 21.21);
  result2 = sprintf(buffer_2, "%f", 21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%5f", 21.21);
  result2 = sprintf(buffer_2, "%5f", 21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%05f", 21.21);
  result2 = sprintf(buffer_2, "%05f", 21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%-5f", 21.21);
  result2 = sprintf(buffer_2, "%-5f", 21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%+f", 21.21);
  result2 = sprintf(buffer_2, "%+f", 21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "% f", 21.21);
  result2 = sprintf(buffer_2, "% f", 21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "% 0f", 21.21);
  result2 = sprintf(buffer_2, "% 0f", 21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.0f", 1.01);
  result2 = sprintf(buffer_2, "%.0f", 1.01);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%10.2f", 21.21);
  result2 = sprintf(buffer_2, "%10.2f", 21.21);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.5f", 3.14159265358979323846);
  result2 = sprintf(buffer_2, "%.5f", 3.14159265358979323846);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%50.30f", 123.456789);
  result2 = sprintf(buffer_2, "%50.30f", 123.456789);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.Lf", 123.45L);
  result2 = sprintf(buffer_2, "%.Lf", 123.45L);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
}
END_TEST

// !
// ||--------------------------------------------------------------------------------||
// ! ||                                     u flag || !
// ||--------------------------------------------------------------------------------||

START_TEST(sprintf_u_flag) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];

  int result1 = my_sprintf(buffer_1, "%u", 12345);
  int result2 = sprintf(buffer_2, "%u", 12345);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%u", UINT32_MAX);
  result2 = sprintf(buffer_2, "%u", UINT32_MAX);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%10u", 123);
  result2 = sprintf(buffer_2, "%10u", 123);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.5u", 123);
  result2 = sprintf(buffer_2, "%.5u", 123);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.hu", (short)12345);
  result2 = sprintf(buffer_2, "%.hu", (short)12345);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%.lu", 123456789123456789L);
  result2 = sprintf(buffer_2, "%.lu", 123456789123456789L);
}
END_TEST

// !
// ||--------------------------------------------------------------------------------||
// ! ||                                 length modifiers || !
// ||--------------------------------------------------------------------------------||

START_TEST(sprintf_hd) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];

  int result1 = my_sprintf(buffer_1, "%hd", 12345);
  int result2 = sprintf(buffer_2, "%hd", 12345);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%ld", 123456789L);
  result2 = sprintf(buffer_2, "%ld", 123456789L);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%lf", 123.456);
  result2 = sprintf(buffer_2, "%lf", 123.456);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
}
END_TEST

// !
// ||--------------------------------------------------------------------------------||
// ! ||                                      combo || !
// ||--------------------------------------------------------------------------------||

START_TEST(sprintf_combined) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];

  int result1 =
      my_sprintf(buffer_1, "String: %s, Char: %c, Int: %d, Float: %.2f %%",
                  "test", 'X', 42, 3.14159);
  int result2 =
      sprintf(buffer_2, "String: %s, Char: %c, Int: %d, Float: %.2f %%", "test",
              'X', 42, 3.14159);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "%+-10.3f %05d %-10s", 12.3456, 42, "hello");
  result2 = sprintf(buffer_2, "%+-10.3f %05d %-10s", 12.3456, 42, "hello");

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
}
END_TEST

// !
// ||--------------------------------------------------------------------------------||
// ! ||                                      extra || !
// ||--------------------------------------------------------------------------------||

START_TEST(sprintf_extra_val) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];

  int result1 =
      my_sprintf(buffer_1, "int: %d %d %d %d", INT_MAX, INT_MIN, 0, -0);
  int result2 = sprintf(buffer_2, "int: %d %d %d %d", INT_MAX, INT_MIN, 0, -0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);

  result1 = my_sprintf(buffer_1, "uint: %u %u %u", UINT_MAX, 0, 1);
  result2 = sprintf(buffer_2, "uint: %u %u %u", UINT_MAX, 0, 1);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
}
END_TEST

START_TEST(sprintf_star_width_precision) {
  char buffer_1[BUFFER];
  char buffer_2[BUFFER];

  int width = 10;
  int precision = 5;

  int result1 = my_sprintf(buffer_1, "d:%*.*f s:%-*.*s", width, precision,
                            123.456, width, precision, "hello world");
  int result2 = sprintf(buffer_2, "d:%*.*f s:%-*.*s", width, precision, 123.456,
                        width, precision, "hello world");

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer_1, buffer_2);
}
END_TEST

Suite *my_test_sprintf(void) {
  Suite *s = suite_create("SPRINTF");
  TCase *tc = tcase_create("sprintf");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, sprintf_1_s_flag);
  tcase_add_test(tc, sprintf_2_percent);
  tcase_add_test(tc, sprintf_3_c_flag);
  tcase_add_test(tc, sprintf_4_d_flag);
  tcase_add_test(tc, sprintf_5_f_flag);
  tcase_add_test(tc, sprintf_u_flag);
  tcase_add_test(tc, sprintf_hd);
  tcase_add_test(tc, sprintf_combined);
  tcase_add_test(tc, sprintf_extra_val);
  tcase_add_test(tc, sprintf_star_width_precision);

  suite_add_tcase(s, tc);
  return s;
}