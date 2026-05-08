#include "tests.h"

Suite *my_sute(void) {
  Suite *s = suite_create("my_STRING");
  return s;
}

int main(void) {
  SRunner *sr = srunner_create(my_sute());

  srunner_add_suite(sr, my_test_memcpy());
  srunner_add_suite(sr, my_test_strncat());
  srunner_add_suite(sr, my_test_strchr());
  srunner_add_suite(sr, my_test_strrchr());
  srunner_add_suite(sr, my_test_strncmp());
  srunner_add_suite(sr, my_test_strerror());
  srunner_add_suite(sr, my_test_strstr());
  srunner_add_suite(sr, my_test_strtok());
  srunner_add_suite(sr, my_test_strlen());
  srunner_add_suite(sr, my_test_memset());
  srunner_add_suite(sr, my_test_memchr());
  srunner_add_suite(sr, my_test_memcmp());
  srunner_add_suite(sr, my_test_strcspn());
  srunner_add_suite(sr, my_test_strncpy());
  srunner_add_suite(sr, my_test_strpbrk());
  srunner_add_suite(sr, my_test_sprintf());
  srunner_add_suite(sr, my_test_sprintf_2());
  srunner_add_suite(sr, my_test_special_functions());

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
