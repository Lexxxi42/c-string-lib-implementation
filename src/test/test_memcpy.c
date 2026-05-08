#include "tests.h"

START_TEST(memcpy_test_basic_1) {
  // Копирование строки
  char dest_std[20] = "test";
  char dest_my[20] = "test";
  char src[] = "Hello, World!";
  my_size_t copy_size = strlen(src) + 1;

  ck_assert_str_eq(memcpy(dest_std, src, copy_size),
                   my_memcpy(dest_my, src, copy_size));
  ck_assert_mem_eq(dest_std, dest_my, copy_size);

  // printf("basic_1:\nmemcpy: \"%s\", my_memcpy: \"%s\"\n", dest_std,
  // dest_my);
}
END_TEST

START_TEST(memcpy_test_basic_2) {
  // Копирование массива целых чисел
  int dest_std[5];
  int dest_my[5];
  int src[] = {1, 2, 3, 4, 5};
  my_size_t copy_size = 5 * sizeof(int);

  ck_assert_mem_eq(memcpy(dest_std, src, copy_size),
                   my_memcpy(dest_my, src, copy_size), copy_size);
}
END_TEST

START_TEST(memcpy_test_basic_3) {
  // Копирование одного символа
  char dest_std[10] = "aaaa";
  char dest_my[10] = "aaaa";
  char src[] = "X";

  ck_assert_str_eq(memcpy(dest_std, src, 1), my_memcpy(dest_my, src, 1));

  // printf("basic_3:\nmemcpy: \"%s\", my_memcpy: \"%s\"\n", dest_std,
  // dest_my);
}
END_TEST

// Тест 2: граничный случай (NULL/пустая строка)
START_TEST(memcpy_test_empty_string_1) {
  char src1[] = "Test";
  char dest1_std[10] = "original";
  char dest1_my[10] = "original";

  ck_assert_ptr_eq(dest1_my, my_memcpy(dest1_my, src1, 0));
  ck_assert_str_eq(memcpy(dest1_std, src1, 0), my_memcpy(dest1_my, src1, 0));

  // printf("empty_string_1:\nmemcpy: \"%s\", my_memcpy: \"%s\"\n", dest1_std,
  // dest1_my);
}
END_TEST

START_TEST(memcpy_test_empty_string_2) {
  // Копирование пустой строки
  char src[] = "";
  char dest_std[10] = "test";
  char dest_my[10] = "test";

  memcpy(dest_std, src, 1);
  my_memcpy(dest_my, src, 1);

  ck_assert_str_eq(dest_std, dest_my);

  // printf("empty_string_2:\nmemcpy: \"%s\", my_memcpy: \"%s\"\n", dest_std,
  // dest_my);
}
END_TEST

START_TEST(memcpy_test_empty_string_3) {
  char src[] = "newstr";
  char dest_std[] = "old";
  char dest_my[] = "old";

  memcpy(dest_std, src, 0);
  my_memcpy(dest_my, src, 0);

  ck_assert_str_eq(dest_std, dest_my);

  // printf("empty_string_3:\nmemcpy: \"%s\", my_memcpy: \"%s\"\n", dest_std,
  // dest_my);
}
END_TEST

// Тест 3: Частичное копирование
START_TEST(memcpy_test_substring_replacement_1) {
  char src[] = "ffffffffff";
  char dest_std[10] = "aaabbbccc";
  char dest_my[10] = "aaabbbccc";

  ck_assert_str_eq(memcpy(dest_std, src, 5), my_memcpy(dest_my, src, 5));
  ck_assert_mem_eq(dest_std, dest_my, 10);  // сравниваем весь буфер
  ck_assert_str_eq(dest_std + 5, "bccc\0");  // проверяем неизмененную часть

  // printf("substr_1:\nmemcpy: \"%s\", my_memcpy: \"%s\"\n", dest_std,
  // dest_my);
}
END_TEST

START_TEST(memcpy_test_substring_replacement_2) {
  char src[3] = "OK";
  char dest_std[7] = "abcdef\0";
  char dest_my[7] = "abcdef\0";

  my_memcpy(dest_my + 2, src, 2);
  memcpy(dest_std + 2, src, 2);

  ck_assert_mem_eq(dest_std, dest_my, 7);

  // printf("substr_2:\nmemcpy: \"%s\", my_memcpy: \"%s\"\n", dest_std,
  // dest_my);
}
END_TEST

START_TEST(memcpy_test_substring_replacement_3) {
  char src[] = "XXXXX";
  char dest_std[12] = "hello world";
  char dest_my[12] = "hello world";

  ck_assert_str_eq(memcpy(dest_std + 6, src, 5),
                   my_memcpy(dest_my + 6, src, 5));
  ck_assert_mem_eq(dest_std, dest_my, 12);  // сравниваем весь буфер

  // printf("substr_3:\nmemcpy: \"%s\", my_memcpy: \"%s\"\n", dest_std,
  // dest_my);
}
END_TEST

Suite *my_test_memcpy(void) {
  Suite *s = suite_create("MEMCPY");
  TCase *tc = tcase_create("memcpy");

  tcase_add_test(tc, memcpy_test_basic_1);
  tcase_add_test(tc, memcpy_test_basic_2);
  tcase_add_test(tc, memcpy_test_basic_3);

  tcase_add_test(tc, memcpy_test_empty_string_1);
  tcase_add_test(tc, memcpy_test_empty_string_2);
  tcase_add_test(tc, memcpy_test_empty_string_3);

  tcase_add_test(tc, memcpy_test_substring_replacement_1);
  tcase_add_test(tc, memcpy_test_substring_replacement_2);
  tcase_add_test(tc, memcpy_test_substring_replacement_3);

  suite_add_tcase(s, tc);
  return s;
}