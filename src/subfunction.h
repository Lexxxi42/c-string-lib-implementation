#ifndef SUBFUNCTION_H
#define SUBFUNCTION_H

#include "string.h"

#define precision_default 6

int float_to_str(char *buf, long double num, const flags *flag);
int int_to_str(char *buf, unsigned long num);
int g_to_str(char *buf, long double num, const flags *flag);
int e_to_str(char *buf, long double num, const flags *flag);
int x_to_str(char *buf, unsigned long num, const flags *flag);
int o_to_str(char *buf, unsigned long num, flags *flag);
int p_to_str(char *buf, void *ptr);

void parse_format(const char **format, flags *flag, va_list *args);
int parse_number(const char **format_ptr);
int format_and_write(char **str, char option, flags *flag, int length);
int get_length_precision(char option, const flags *flag, int length);
int fill_to_width(char **str, int padding_len, char fill_char);
int check_nan_inf(char *buf, long double num, int upper);
int get_exponent(long double num);
int get_frac_part(long double fract_part, int count_frac, char *buf, int k,
                  int show_zero);
long double round_significant(long double num, int count_sign_digits);
int mantis_to_buf(int exp, char *buf, int k_buf, int upper);
double round_to_decimal(long double value, int decimals);

#endif