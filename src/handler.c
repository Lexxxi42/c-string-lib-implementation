#include "handler.h"

#include <stdarg.h>

#include "string.h"
#include "subfunction.h"

int handle_option(const char option, char **current, va_list *args,
                  flags *flag) {
  int added = 0;
  if (option == '%') {
    added = handle_percent(current);
  } else if (option == 'd') {
    added = handle_d(args, flag);
  } else if (option == 'c') {
    added = handle_c(args, flag);
  } else if (option == 'f') {
    added = handle_f(args, flag);
  } else if (option == 's') {
    added = handle_s(args, flag);
  } else if (option == 'u') {
    added = handle_u(args, flag);
  } else if (option == 'g' || option == 'G') {
    if (option == 'G') flag->upper = 1;
    added = handle_g(args, flag);
  } else if (option == 'e' || option == 'E') {
    if (option == 'E') flag->upper = 1;
    added = handle_e(args, flag);
  } else if (option == 'x' || option == 'X') {
    if (option == 'X') flag->upper = 1;
    added = handle_x(args, flag);
  } else if (option == 'o') {
    added = handle_o(args, flag);
  } else if (option == 'p') {
    added = handle_p(args, flag);
  } else {
    added = -1;
  }

  if (added != -1 && option != '%') {
    added = format_and_write(current, option, flag, added);
  }

  return added;
}

int handle_g(va_list *args, flags *flag) {
  long double num;
  int len = 0;

  if (flag->is_L) {
    num = va_arg(*args, long double);
  } else {
    num = (long double)va_arg(*args, double);
  }
  if (num < 0) {
    flag->negative = 1;
    num = -num;
  }

  len = check_nan_inf(flag->buf, num, flag->upper);
  if (len == 0) {
    len = g_to_str(flag->buf, num, flag);
  }

  return len;
}

int handle_e(va_list *args, flags *flag) {
  long double num;
  int len = 0;

  if (flag->is_L) {
    num = va_arg(*args, long double);
  } else {
    num = (long double)va_arg(*args, double);
  }

  if (num < 0) {
    flag->negative = 1;
    num = -num;
  }

  len = check_nan_inf(flag->buf, num, flag->upper);
  if (len == 0) {
    len = e_to_str(flag->buf, num, flag);
  }

  return len;
}

int handle_x(va_list *args, flags *flag) {
  unsigned long long num;
  if (flag->is_h) {
    num = (unsigned short)va_arg(*args, unsigned int);
  } else if (flag->is_l) {
    num = va_arg(*args, unsigned long int);
  } else {
    num = va_arg(*args, unsigned int);
  }
  return x_to_str(flag->buf, num, flag);
}

int handle_o(va_list *args, flags *flag) {
  unsigned long long num;
  if (flag->is_h) {
    num = (unsigned short)va_arg(*args, unsigned int);
  } else if (flag->is_l) {
    num = va_arg(*args, unsigned long int);
  } else {
    num = va_arg(*args, unsigned int);
  }
  return o_to_str(flag->buf, num, flag);
}

int handle_p(va_list *args, flags *flag) {
  void *ptr = va_arg(*args, void *);
  int len = p_to_str(flag->buf, ptr);

  return len;
}

int handle_percent(char **str) {
  **str = '%';
  (*str)++;
  return 1;
}

int handle_c(va_list *args, flags *flag) {
  char ch = (char)va_arg(*args, int);
  flag->buf[0] = ch;
  flag->buf[1] = '\0';

  return 1;
}

int handle_d(va_list *args, flags *flag) {
  long long num;
  if (flag->is_h) {
    num = (short int)va_arg(*args, int);
  } else if (flag->is_l) {
    num = va_arg(*args, long int);
  } else {
    num = va_arg(*args, int);
  }

  unsigned long long absnum;
  if (num < 0) {
    flag->negative = 1;
    absnum = -(unsigned long long)num;
  } else {
    absnum = num;
  }

  return int_to_str(flag->buf, absnum);
}

int handle_f(va_list *args, flags *flag) {
  long double num;
  int len = 0;

  if (flag->is_L) {
    num = va_arg(*args, long double);
  } else {
    num = (long double)va_arg(*args, double);
  }
  if (num < 0) {
    flag->negative = 1;
    num = -num;
  }

  len = check_nan_inf(flag->buf, num, 0);

  if (len == 0) {
    len = float_to_str(flag->buf, num, flag);
  }

  return len;
}

int handle_s(va_list *args, flags *flag) {
  const char *s = va_arg(*args, char *);
  int len = 0;

  if (!s) {
    len = 6;
    my_strncpy(flag->buf, "(null)", len);
  } else {
    const int max_buf_size = 32;
    int precision = flag->precision;
    while (len < max_buf_size - 1 && s[len] != '\0' &&
           (precision > len || precision == -1)) {
      flag->buf[len] = s[len];
      len++;
    }

    flag->buf[len] = '\0';
  }

  return len;
}

int handle_u(va_list *args, flags *flag) {
  unsigned long long num;
  if (flag->is_h) {
    num = (unsigned short)va_arg(*args, unsigned int);
  } else if (flag->is_l) {
    num = va_arg(*args, unsigned long int);
  } else {
    num = va_arg(*args, unsigned int);
  }

  return int_to_str(flag->buf, num);
}