#include "subfunction.h"

#include <math.h>
#include <stdio.h>

void parse_format(const char **format, flags *flag, va_list *args) {
  // 1. флаги
  while (**format && my_strchr("+- #0", **format)) {
    switch (**format) {
      case '+':
        flag->plus = 1;
        break;
      case '-':
        flag->minus = 1;
        break;
      case ' ':
        flag->space = 1;
        break;
      case '#':
        flag->alt = 1;
        break;
      case '0':
        flag->zero = 1;
        break;
      default:
        break;
    }
    (*format)++;
  }

  // 2. ширина
  if (**format == '*') {
    int width = va_arg(*args, int);
    if (width < 0) {
      width *= -1;
      flag->minus = 1;
    }
    flag->width = width;
    (*format)++;
  } else if (**format >= '1' && **format <= '9') {
    flag->width = parse_number(format);
  }

  // 3. точность
  if (**format == '.') {
    (*format)++;
    if (**format == '*') {
      flag->precision = va_arg(*args, int);
      (*format)++;
    } else {
      flag->precision = parse_number(format);
    }
  }

  // 4. длина
  if (**format == 'h') {
    flag->is_h = 1;
    (*format)++;
  } else if (**format == 'l') {
    flag->is_l = 1;
    (*format)++;
  } else if (**format == 'L') {
    flag->is_L = 1;
    (*format)++;
  }
}

int parse_number(const char **format_ptr) {
  int number = 0;
  const char *format = *format_ptr;

  if (*format >= '0' && *format <= '9') {
    number = 0;
    while (*format >= '0' && *format <= '9') {
      number = number * 10 + (*format - '0');
      format++;
    }
    *format_ptr = format;
  }

  return number;
}

int format_and_write(char **str, char option, flags *flag, int length) {
  int total_written = 0;
  int content_length = length;

  int precision = get_length_precision(option, flag, length);
  content_length += precision;

  int has_sign = (flag->negative == 1 || flag->plus == 1 || flag->space == 1);
  content_length += has_sign;

  int padding_len = flag->width - content_length;
  if (padding_len < 0) padding_len = 0;

  char fill_char = ' ';
  if (flag->zero == 1) fill_char = '0';

  // 1. пробелы слева
  if (flag->minus == 0 && fill_char != '0') {
    total_written += fill_to_width(str, padding_len, fill_char);
  }

  // 2.знак
  if (has_sign == 1) {
    char sign;
    if (flag->negative == 1)
      sign = '-';
    else if (flag->plus == 1)
      sign = '+';
    else
      sign = ' ';

    *(*str)++ = sign;
    total_written++;
  }

  // 1. нули слева
  if (flag->minus == 0 && fill_char == '0') {
    total_written += fill_to_width(str, padding_len, fill_char);
  }

  // 3. точность
  if (precision > 0) {
    for (int i = 0; i < precision; i++) {
      *(*str)++ = '0';
      total_written++;
    }
  }

  // 4. число/строка
  if (precision != -1) {
    for (int i = 0; i < length; i++) {
      *(*str)++ = flag->buf[i];
      total_written++;
    }
  }

  // 1. пробелы справа
  if (flag->minus == 1) {
    total_written += fill_to_width(str, padding_len, fill_char);
  }

  return total_written;
}

int fill_to_width(char **str, int padding_len, char fill_char) {
  int total_written = 0;
  // 1. пробелы слева/справа
  if (padding_len > 0) {
    for (int i = 0; i < padding_len; i++) {
      *(*str)++ = fill_char;
      total_written++;
    }
  }

  return total_written;
}

int get_length_precision(char option, const flags *flag, int length) {
  int result_precision = 0;

  if (my_strchr("diouxX", option) != my_NULL) {
    if (option != 'x' && option != 'X') {
      result_precision = flag->precision - length;
      if (result_precision < 0) {
        result_precision = 0;
      }
    }
    // Точность 0 означает, что для значения 0 не записывается ни одного
    // символа.
    if (flag->precision == 0 && length == 1 && flag->buf[0] == '0') {
      result_precision = -1;
    }
  }

  return result_precision;
}

int float_to_str(char *buf, long double num, const flags *flag) {
  long long int_part = (long long)num;
  long double frac_part = num - int_part;

  int precision = flag->precision;
  if (precision == -1) precision = precision_default;

  frac_part = round_to_decimal(frac_part, precision);
  if (frac_part == 1.0L) {
    int_part++;
    frac_part = 0.0L;
  }

  int pos = 0;
  if (int_part == 0) {
    buf[pos++] = '0';
  } else {
    pos = int_to_str(buf, int_part);
  }

  if (precision > 0 || flag->alt == 1) {
    buf[pos++] = '.';
  }

  if (precision > 0) {
    for (int i = 0; i < precision; i++) {
      frac_part *= 10;
      int digit = (int)(frac_part + 1e-10);
      buf[pos++] = '0' + digit;
      frac_part -= digit;
    }
  }

  return pos;
}

int int_to_str(char *buf, unsigned long num) {
  int len = 0;

  if (num == 0) {
    buf[len++] = '0';
  } else {
    int i = 0;
    long temp_num = num;
    while (temp_num > 0) {
      buf[i++] = '0' + (temp_num % 10);
      temp_num /= 10;
    }

    for (int j = 0; j < i / 2; j++) {
      char tmp = buf[j];
      buf[j] = buf[i - 1 - j];
      buf[i - 1 - j] = tmp;
    }

    len = i;
  }

  buf[len] = '\0';

  return len;
}

int g_to_str(char *buf, long double num, const flags *flag) {
  int count_sign_digits = flag->precision;
  if (flag->precision == 0) {
    count_sign_digits = 1;
  } else if (flag->precision == -1)
    count_sign_digits = precision_default;

  int signed_exp = 0;
  int need_exp = 0;
  long double round_num = 0.0L;

  if (num != 0) {
    round_num = round_significant(num, count_sign_digits);
    signed_exp = get_exponent(round_num);
    need_exp = (signed_exp < -4 || signed_exp >= count_sign_digits);
  }

  int k_buf = 0;
  long double fract_part = 0.0L;
  int count_frac = 0;
  if (need_exp == 1) {
    long double normalized = round_num / powl(10.0L, signed_exp);
    int first_digit = (int)normalized;
    buf[k_buf++] = '0' + first_digit;
    fract_part = normalized - first_digit;
    count_frac = count_sign_digits - 1;

  } else {
    long int_part = (long)(round_num + 1e-10L);
    fract_part = round_num - int_part;
    k_buf = int_to_str(buf, (long)int_part);

    count_frac = count_sign_digits;
    if (signed_exp < 0) {
      count_frac += -signed_exp - 1;
    } else {
      count_frac -= signed_exp + 1;
      if (count_frac < 0) count_frac = 0;
    }
  }

  if ((fract_part > 1e-10L && count_frac > 0) || flag->alt == 1) {
    buf[k_buf++] = '.';
  }

  k_buf = get_frac_part(fract_part, count_frac, buf, k_buf, flag->alt);

  if (need_exp == 1) {
    k_buf = mantis_to_buf(signed_exp, buf, k_buf, flag->upper);
  }

  buf[k_buf] = '\0';
  return k_buf;
}

int get_exponent(long double num) {
  // Порядок числа: 1(0), 10(1), 0.1(-1), 0.01(-2)
  int exponent = 0;
  if (num != 0.0) {
    double epsilon = 1e-12;

    if (num < 1.0L) {
      while (num < 1.0L - epsilon) {
        num *= 10.0L;
        exponent--;
      }
    } else {
      while (num >= 10.0L - epsilon) {
        num /= 10.0L;
        exponent++;
      }
    }
  }

  return exponent;
}

int get_frac_part(long double fract_part, int count_frac, char *buf, int k,
                  int show_zero) {
  if (count_frac > 0) {
    int first_zero = -1;
    for (int i = 0; i < count_frac; i++) {
      fract_part *= 10;
      int dig = (int)(fract_part + 1e-10L);

      if (dig == 0 && first_zero == -1) {
        first_zero = k;
      } else if (dig != 0 && first_zero != -1) {
        first_zero = -1;
      }

      buf[k++] = '0' + dig;
      fract_part -= dig;
    }

    if (show_zero == 0 && first_zero != -1) {
      buf[first_zero] = '\0';
      k = first_zero;
    }
  }

  return k;
}

long double round_significant(long double num, int count_sign_digits) {
  long double round_num = 0;
  if (num != 0.0L) {
    int exp = get_exponent(num);
    long double normalized = num / powl(10.0L, exp);

    long double rounded = round_to_decimal(normalized, count_sign_digits - 1);
    if (rounded >= 10.0L) {
      rounded /= 10.0L;
      exp++;
    }

    round_num = rounded * powl(10.0L, exp);
  }

  return round_num;
}

double round_to_decimal(long double value, int decimals) {
  long double factor = powl(10.0L, decimals);
  return roundl(value * factor) / factor;
}

int mantis_to_buf(int exp, char *buf, int k_buf, int upper) {
  buf[k_buf++] = (upper == 0) ? 'e' : 'E';

  if (exp == 0) {
    my_memcpy(buf + k_buf, "+00", 3);
    k_buf += 3;
  } else {
    char sign = '+';
    if (exp < 0) {
      exp *= -1;
      sign = '-';
    }
    buf[k_buf++] = sign;

    char tmp_exp[12];
    int len_tmp = int_to_str(tmp_exp, exp);
    if (len_tmp == 1) {
      buf[k_buf++] = '0';
    }
    my_strncpy(buf + k_buf, tmp_exp, len_tmp);
    k_buf += len_tmp;
  }

  return k_buf;
}

int e_to_str(char *buf, long double num, const flags *flag) {
  int count_sign_digits = flag->precision;
  if (flag->precision == -1) count_sign_digits = precision_default;

  int k_buf = 0;
  int signed_exp = 0;
  long double round_num = 0.0L;

  if (num != 0) {
    round_num = round_significant(num, count_sign_digits + 1);
    signed_exp = get_exponent(round_num);
  }

  long double normalized = round_num / powl(10.0L, signed_exp);
  int first_digit = (int)normalized;
  buf[k_buf++] = '0' + first_digit;
  long double fract_part = normalized - first_digit;

  if (count_sign_digits > 0 || flag->alt == 1) {
    buf[k_buf++] = '.';
  }
  k_buf = get_frac_part(fract_part, count_sign_digits, buf, k_buf, 1);
  k_buf = mantis_to_buf(signed_exp, buf, k_buf, flag->upper);

  buf[k_buf] = '\0';

  return k_buf;
}

int x_to_str(char *buf, unsigned long num, const flags *flag) {
  int i = 0;
  char temp[32];
  int non_zero = 1;

  if (num == 0) {
    temp[i++] = '0';
    non_zero = 0;
  } else {
    char hex_digits[7];
    if (flag->upper == 0)
      my_memcpy(hex_digits, "abcdef", 7);
    else
      my_memcpy(hex_digits, "ABCDEF", 7);

    while (num > 0) {
      int ostatok = num % 16;
      char ch;

      if (ostatok >= 10)
        ch = hex_digits[ostatok - 10];
      else {
        ch = '0' + ostatok;
      }

      temp[i++] = ch;
      num /= 16;
    }
  }

  if (flag->precision > 0) {
    int count_zero = flag->precision - i;
    while (count_zero > 0) {
      temp[i++] = '0';
      count_zero--;
    }
  }

  if (flag->alt == 1 && non_zero == 1) {
    temp[i++] = (flag->upper == 0) ? 'x' : 'X';
    temp[i++] = '0';
  }

  int k_buf = 0;
  while (i > 0) {
    buf[k_buf++] = temp[--i];
  }

  buf[k_buf] = '\0';

  return k_buf;
}

int o_to_str(char *buf, unsigned long num, flags *flag) {
  char temp[32];
  int i = 0;

  if (num == 0) {
    temp[i++] = '0';
    if (flag->alt == 1 && flag->precision == 0) {
      flag->precision = -1;
    }
  } else {
    while (num > 0) {
      int ostatok = num % 8;
      char ch = '0' + ostatok;
      ;
      temp[i++] = ch;
      num /= 8;
    }

    if (flag->alt == 1) {
      temp[i++] = '0';
    }
  }

  int k_buf = 0;
  while (i > 0) {
    buf[k_buf++] = temp[--i];
  }

  buf[k_buf] = '\0';

  return k_buf;
}

int p_to_str(char *buf, void *ptr) {
  int k_buf = 0;

  if (ptr == my_NULL) {
    my_memcpy(buf, "(nil)", 6);
    k_buf = 5;
  } else {
    my_size_t address = (my_size_t)ptr;

    flags flag_x = {0};
    flag_x.alt = 1;

    int x_len = x_to_str(buf + k_buf, address, &flag_x);
    k_buf += x_len;
  }

  buf[k_buf] = '\0';

  return k_buf;
}

int check_nan_inf(char *buf, long double num, int upper) {
  const char *special_value = NULL;
  int len = 0;

  if (isinf(num)) {
    special_value = upper ? "INF" : "inf";
  } else if (isnan(num)) {
    special_value = upper ? "NAN" : "nan";
  }

  if (special_value != NULL) {
    len = 3;
    my_strncpy(buf, special_value, len);
  }

  buf[len] = '\0';
  return len;
}