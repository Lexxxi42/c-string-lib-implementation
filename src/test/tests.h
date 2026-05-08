#ifndef SRC_TESTS
#define SRC_TESTS

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../string.h"

Suite *my_test_memcpy(void);
Suite *my_test_strncat(void);
Suite *my_test_strchr(void);
Suite *my_test_strrchr(void);
Suite *my_test_strncmp(void);
Suite *my_test_strerror(void);
Suite *my_test_strstr(void);
Suite *my_test_strtok(void);
Suite *my_test_strlen(void);
Suite *my_test_memset(void);
Suite *my_test_memcmp(void);
Suite *my_test_memchr(void);
Suite *my_test_strcspn(void);
Suite *my_test_strncpy(void);
Suite *my_test_strpbrk(void);
Suite *my_test_sprintf(void);
Suite *my_test_sprintf_2(void);
Suite *my_test_special_functions(void);

#endif  // SRC_TESTS
