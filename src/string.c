#include "string.h"

#include <stdio.h>
#include <stdlib.h>

#include "handler.h"
#include "subfunction.h"

// @brief Добавляет в конец строки dest не более n символов из строки src
// @param dest указатель на строку
// @param src указатель на строку для копирования
// @param n Максимальное количество символов для копирования из src
// @return указатель dest
char *my_strncat(char *dest, const char *src, my_size_t n) {
  char *original_dest = dest;

  while (*dest != '\0') {
    dest++;
  }

  while ((n--) > 0 && *src != '\0') {
    *dest++ = *src++;
  }
  *dest = '\0';

  return original_dest;
}

// @brief Выполняет поиск первого вхождения символа в строке
// @param str указатель на строку для поиска
// @param c символ для поиска (передается как int, но интерпретируется как
// unsigned char)
// @return Указатель на первое вхождение или my_NULL, если символ не найден
char *my_strchr(const char *str, int c) {
  char *result = my_NULL;
  if (str != my_NULL) {
    int found = 0;
    unsigned char uc = (unsigned char)c;

    while (*str != '\0' && !found) {
      if (*(unsigned char *)str == uc)
        found = 1;
      else
        str++;
    }

    if (found == 1 || uc == '\0') {
      result = (char *)str;
    }
  }

  return result;
}

// @brief выполняет поиск последнего вхождения символа
// @param str указатель на строку для поиска
// @param c символ для поиска (передается как int, но интерпретируется как
// unsigned char)
// @return Указатель на первое вхождение или my_NULL, если символ не найден
char *my_strrchr(const char *str, int c) {
  char *last_result = my_NULL;

  if (str != my_NULL) {
    unsigned char uc = (unsigned char)c;

    while (*str != '\0') {
      if (*(unsigned char *)str == uc) {
        last_result = (char *)str;
      }
      str++;
    }

    if (uc == '\0') {
      last_result = (char *)str;
    }
  }

  return last_result;
}

// @brief Сравнивает не более первых n байтов двух строк
// @param str1 указатель на первую строку для сравнения
// @param str2 указатель на вторую строку для сравнения
// @param n максимальное количество байтов для сравнения
/* @return
 *  - 0, если первые n байтов строк идентичны
 *  - Отрицательное число, если str1 < str2
 *  - Положительное число, если str1 > str2
 */
int my_strncmp(const char *str1, const char *str2, my_size_t n) {
  int result = 0;
  int stop_comparing = 0;

  for (my_size_t i = 0; i < n && stop_comparing == 0; i++) {
    if (str1[i] != str2[i]) {
      result = (unsigned char)str1[i] - (unsigned char)str2[i];
      stop_comparing = 1;
    } else if (str1[i] == '\0') {
      stop_comparing = 1;
    }
  }

  return result;
}

// @brief Возвращает строковое описание ошибки по её номеру
// @param errnum номер ошибки
// @return указатель на строку с описанием ошибки
char *my_strerror(int errnum) {
  int is_exist_error = 1;
  static char error_buffer[256];

  if (errnum >= 0) {
    static const char *errors[] = ERROR_MESSAGES;
    static const int max_error = (int)sizeof(errors) / sizeof(errors[0]) - 1;

    if (errnum <= max_error && errors[errnum] != my_NULL) {
      sprintf(error_buffer, "%s", errors[errnum]);
    } else {
      is_exist_error = 0;
    }
  } else {
    is_exist_error = 0;
  }

  if (is_exist_error == 0) {
    sprintf(error_buffer, "Unknown error %d", errnum);
  }

  return error_buffer;
}

// @brief Разбивает строку на токены, разделенные символами delim
// @param str строка для разбиения (при первом вызове) или my_NULL (при
// последующих)
// @param delim строка с символами-разделителями
// @return указатель на следующий токен или my_NULL если токенов больше нет
char *my_strtok(char *str, const char *delim) {
  static char *last_token = my_NULL;
  static char result_token[1024];
  char *result = my_NULL;

  if (str != my_NULL) {
    last_token = str;
  }

  if (last_token == my_NULL) {
    result = my_NULL;
  } else {
    while (*last_token != '\0' && my_strchr(delim, *last_token) != my_NULL) {
      last_token++;
    }

    int i = 0;
    while (*last_token != '\0' && my_strchr(delim, *last_token) == my_NULL) {
      result_token[i] = *last_token;
      last_token++;
      i++;
    }

    result_token[i] = '\0';
    if (i != 0) {
      result = result_token;
    } else {
      result = my_NULL;
    }

    if (*last_token == '\0') {
      last_token = my_NULL;
    }
  }

  return result;
}

// @brief Находит первое вхождение строки needle в строке haystack
// @param haystack строка, в которой выполняется поиск
// @param needle строка, которую нужно найти
// @return указатель на первое вхождение needle в haystack, или my_NULL, если
// не найдено
char *my_strstr(const char *haystack, const char *needle) {
  if (needle == my_NULL || haystack == my_NULL) {
    return my_NULL;
  } else if (*needle == '\0') {
    return (char *)haystack;
  }

  char *str_first_match = my_NULL;

  my_size_t size_haystack = my_strlen(haystack);
  my_size_t size_needle = my_strlen(needle);

  if (size_needle <= size_haystack) {
    my_size_t max_start_index = size_haystack - size_needle;

    int index_first_match = -1;
    for (my_size_t i = 0; i <= max_start_index && index_first_match == -1;
         i++) {
      int all_match = 1;
      for (my_size_t j = 0; j < size_needle; j++) {
        if (needle[j] != haystack[i + j]) {
          all_match = 0;
        }
      }

      if (all_match == 1) index_first_match = i;
    }

    if (index_first_match != -1) {
      str_first_match = (char *)haystack;
      str_first_match += index_first_match;
    }
  }

  return str_first_match;
}

// @brief Копирует n байт из src в dest
// @param dest указатель на любой тип данных
// @param src указатель на область-источник (любого типа данных) для копирования
// @param n количество байт для копирования
// @return Указатель на dest
// @warning не проверяет поместится ли n байт в буфер dest
void *my_memcpy(void *dest, const void *src, my_size_t n) {
  if (dest == my_NULL || src == my_NULL || n == 0) {
    // не меняем
  } else {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    for (my_size_t i = 0; i < n; i++) {
      d[i] = s[i];
    }
  }

  return dest;
}

/// @brief вычисляет длину заданной строки
/// @param str указатель на строку
/// @return значение типа size_t (целое положительное число)
my_size_t my_strlen(const char *str) {
  my_size_t result = 0;
  while (str[result] != '\0') result++;
  return result;
}

/// @brief Функция заполняет n байтов блока памяти заданым значенем
/// @param str указатель на память, который необходимо инициализировать
/// @param c значение, которым будет заполнена память
/// @param n количество байт, которые заполняются значением
/// @return указатель на заполненный блок памяти
void *my_memset(void *str, int c, my_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  for (my_size_t i = 0; i < n; i++) ptr[i] = (unsigned char)c;
  return str;
}

/// @brief функция, которая сравнивает первые n байты областей память str1 и
/// str2
/// @param str1 первая строка -  указатель на память
/// @param str2 вторая строка -  указатель на память
/// @param n  количество байтов для сравнения
/// @retval 0 Строки равны
/// @retval <0 Строка 1 меньше строки 2
/// @retval >0 Строка 1 больше строки 2
int my_memcmp(const void *str1, const void *str2, my_size_t n) {
  int result = 0;
  if (n != 0) {
    const unsigned char *ptr1 = str1, *ptr2 = str2;

    for (my_size_t i = 0; i < n; i++) {
      if (ptr1[i] != ptr2[i]) {
        result = (int)(ptr1[i] - ptr2[i]);
        break;
      }
    }
  }

  return result;
}

/// @brief функция, которая ищет первое вхождение указанного символа в память
/// @param str указатель на память, в котором будет выполняться поиск
/// @param c искомый символ, передаётся как целое число типа int, но внутри
/// функции преобразуется в unsigned char
/// @param n количество байтов, которые будут анализироваться
/// @return если символ найден, функция возвращает указатель на него, если нет —
/// my_NULL
void *my_memchr(const void *str, int c, my_size_t n) {
  char *result = my_NULL;
  const unsigned char *ptr = str;
  for (my_size_t i = 0; i < n; i++) {
    if (ptr[i] == (unsigned char)c) {
      result = (void *)(ptr + i);
      break;
    }
  }
  return result;
}

/// @brief функция, которая копирует содержимое строки в буфер ограниченного
/// размера
/// @param dest указатель на буфер
/// @param src указатель на исходную строку
/// @param n максимальное количество копируемых символов (включая нулевой
/// символ)
/// @return функция возвращает значение dest
char *my_strncpy(char *dest, const char *src, my_size_t n) {
  my_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  for (; i < n; i++) {
    dest[i] = '\0';
  }
  return dest;
}

/// @brief Функция strcspn выполняет поиск первого вхождения в строку string1
/// любого из символов строки string2
/// @param str1 cтрока, в которой выполняется поиск
/// @param str2 cтрока содержащая символы для поиска в строке str1
/// @return возвращает длину str1 до первого вхождения из str2
my_size_t my_strcspn(const char *str1, const char *str2) {
  my_size_t result = 0;

  for (my_size_t i = 0; str1[i] && !my_strchr(str2, str1[i]); i++) result++;

  return result;
}

/// @brief функция, которая находит первое вхождение символа из из str1, который
/// есть в str2
/// @param str1 cтрока, в которой выполняется поиск
/// @param str2 cтрока содержащая символы для поиска в строке str1
/// @return указатель на позицию в str1
char *my_strpbrk(const char *str1, const char *str2) {
  char *result = my_NULL;

  for (my_size_t i = 0; !result && str1[i] != '\0'; i++) {
    if (my_strchr(str2, str1[i])) result = (char *)(str1 + i);
  }
  return result;
}

/// @brief преобразование upper или lower
/// @param str указатель на исходную строку
/// @param to_upper флаг к какому регистру приводить: 1 - upper; 0 - lower
/// @retval копия строки с преобразованным регистром
/// @retval NULL - в случае какой-либо ошибки
/// @note Работает только с символами латинского алфавита (a-z, A-Z)
void *my_change_register(const char *str, int to_upper) {
  char *res = my_NULL;

  if (str != my_NULL) {
    my_size_t len = my_strlen(str);

    res = malloc((len + 1) * sizeof(char));

    if (res != my_NULL) {
      for (my_size_t i = 0; i < len; i++) {
        if (to_upper && str[i] >= 'a' && str[i] <= 'z')
          res[i] = str[i] - 32;
        else if (!to_upper && str[i] >= 'A' && str[i] <= 'Z')
          res[i] = str[i] + 32;
        else
          res[i] = str[i];
      }
      res[len] = '\0';
    }
  }
  return res;
}

/// @brief преобразует элемент входной последовательности из нижнего регстра в
/// верхний
/// @param str указатель на строку
/// @retval копия строки в верхнем регистре
/// @retval NULL - в случае какой-либо ошибки
/// @warning не очищает память. очищать собственноручно
/// @note Работает только с символами латинского алфавита (a-z)
void *my_to_upper(const char *str) { return my_change_register(str, 1); }

/// @brief преобразует элемент входной последовательности из верхнего регстра в
/// нижний
/// @param str указатель на строку
/// @retval копия строки в нижнем регистре
/// @retval NULL - в случае какой-либо ошибки
/// @warning не очищает память. очищать собственноручно
/// @note Работает только с символами латинского алфавита (A-Z)
void *my_to_lower(const char *str) { return my_change_register(str, 0); }

/// @brief вставляет строку str в строку src на указанную позицию
/// @param src исходная строка
/// @param str вставляемая строка
/// @param start_index индекс вставки
/// @retval новая строка с результатом вставки
/// @retval NULL - в случае какой-либо ошибки
void *my_insert(const char *src, const char *str, my_size_t start_index) {
  char *res = my_NULL;
  if (src != my_NULL && str != my_NULL) {
    my_size_t src_len = my_strlen(src);
    my_size_t str_len = my_strlen(str);

    if (start_index <= src_len) {
      my_size_t total_len = src_len + str_len;

      res = (char *)malloc(total_len + 1);

      if (res != my_NULL) {
        // сохраняем до указанной позиции
        my_memcpy(res, src, start_index);
        // вставляем строку до ее конца
        my_memcpy(res + start_index, str, str_len);
        // после вставки вставляем оставшуюся
        my_memcpy(res + start_index + str_len, src + start_index,
                   src_len - start_index);
        res[total_len] = '\0';
      }
    }
  }
  return res;
}

/// @brief удаляет из начала и конца строки символы из trim_chars
/// @param src исходная строка
/// @param trim_chars набор символов для удаления
/// @retval новая строка без символов trim_chars по краям
/// @retval NULL - в случае какой-либо ошибки
void *my_trim(const char *src, const char *trim_chars) {
  char *result = my_NULL;
  if (src != my_NULL && trim_chars != my_NULL) {
    my_size_t start = 0;
    my_size_t end = my_strlen(src);

    while (start < end && my_strchr(trim_chars, src[start]) != my_NULL) {
      start++;
    }

    while (end > start && my_strchr(trim_chars, src[end - 1]) != my_NULL) {
      end--;
    }

    my_size_t len = end > start ? end - start : 0;

    result = (char *)malloc(len + 1);

    if (result != my_NULL) {
      for (my_size_t i = 0; i < len; i++) {
        result[i] = src[start + i];
      }
      result[len] = '\0';
    }
  }
  return result;
}

int my_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int written = dispatcher(str, format, &args);
  str[written] = '\0';
  va_end(args);
  return written;
}

int dispatcher(char *str, const char *format, va_list *args) {
  char *current = str;
  int written = 0;

  while (*format) {
    if (*format != '%') {
      *current++ = *format++;
      written++;
    } else {
      format++;
      if (*format == '\0') {
        *current++ = '%';
        written++;
        break;
      }

      flags flag = {0};
      flag.precision = -1;

      parse_format(&format, &flag, args);

      int added = handle_option(*format, &current, args, &flag);
      if (added == -1) {
        *current++ = '%';
        *current++ = *format;
        added = 2;
      }

      format++;
      written += added;
    }
  }
  return written;
}
