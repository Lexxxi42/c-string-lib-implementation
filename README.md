# string+

Implementation of the string.h library with extensions.

## Contents
1. [Chapter I](#chapter-i) \
    1.1. [Introduction](#introduction)
2. [Chapter II](#chapter-ii) \
    2.1. [Information](#information)
3. [Chapter III](#chapter-iii) \
    3.1. [Features & constraints](#features--constraints)  
    3.2. [Part 2](#part-2-partial-implementation-of-the-sprintf-function)  
    3.3. [Part 3](#part-3-advanced-implementation-of-some-format-modifiers-of-the-sprintf-function)  
    3.4. [Part 4](#part-4-advanced-implementation-of-the-sscanf-function)  
    3.5. [Part 5](#part-5-advanced-implementation-of-special-string-handling-functions)  

## Chapter I

## Introduction

In this project, it was necessary to develop an own implementation of the string.h library in the C programming language with some extensions (with own implementation of the sprintf and sscanf functions (sscanf in implementation)).

## Chapter II

## Information

The C programming language includes a set of functions that implement string operations (character strings and byte strings) in its standard library. It supports operations such as: copying, concatenation, marking, and searching. For character strings, the standard library has a rule that strings must end with a terminating null character: a string of n characters is represented as an array of n + 1 elements, the last of which is a 'NULL' character.

The only string support in the C programming language itself is that the compiler converts quoted string constants into null-terminated strings.

<details>
<summary>Description of the implemented library functionality.</summary>

### string.h Types

| No. | Variable | Description |
| ------ | ------ | ------ |
| 1 | size_t | This is the unsigned integral type and is the result of the sizeof keyword. |
	
### string.h Macro

| No. | Macro | Description |
| ------ | ------ | ------ |
| 1 | NULL | This macro is the value of a null pointer constant. |

### string.h Functions

| No. | Function | Description |
| ------ | ------ | ------ |
| 1 | void *memchr(const void *str, int c, size_t n) | Searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str. |
| 2 | int memcmp(const void *str1, const void *str2, size_t n) | Compares the first n bytes of str1 and str2. |
| 3 | void *memcpy(void *dest, const void *src, size_t n) | Copies n characters from src to dest. |
| 4 | void *memset(void *str, int c, size_t n) | Copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str. |
| 5 | char *strncat(char *dest, const char *src, size_t n) | Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long. |
| 6	| char *strchr(const char *str, int c) | Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str. |
| 7 | int strncmp(const char *str1, const char *str2, size_t n) | Compares at most the first n bytes of str1 and str2. |
| 8 | char *strncpy(char *dest, const char *src, size_t n) | Copies up to n characters from the string pointed to, by src to dest. |
| 9 | size_t strcspn(const char *str1, const char *str2) | Calculates the length of the initial segment of str1 which consists entirely of characters not in str2. |
| 10 | char *strerror(int errnum) | Searches an internal array for the error number errnum and returns a pointer to an error message string. You need to declare macros containing arrays of error messages for mac and linux operating systems. Error descriptions are available in the original library. Checking the current OS is carried out using directives. |
| 11 | size_t strlen(const char *str) | Computes the length of the string str up to but not including the terminating null character. |
| 12 | char *strpbrk(const char *str1, const char *str2) | Finds the first character in the string str1 that matches any character specified in str2. |
| 13 | char *strrchr(const char *str, int c) | Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str. |
| 14 | char *strstr(const char *haystack, const char *needle) | Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack. |
| 15 | char *strtok(char *str, const char *delim) | Breaks string str into a series of tokens separated by delim. |

### sprintf and sscanf

- int sscanf(const char *str, const char *format, ...) — reads formatted input from a string;
- int sprintf(char *str, const char *format, ...) — sends formatted output to a string pointed to, by str.

where:
- str — This is the C string that the function processes as its source to retrieve the data;
- format — This is the C string that contains one or more of the following items: Whitespace character, Non-whitespace character and Format specifiers. A format specifier for print functions follows this prototype: %[flags][width][.precision][length]specifier. A format specifier for scan functions follows this prototype: %[*][width][length]specifier.

### sprintf And sscanf Specifiers

| No. | Specifier | sprintf output | sscanf output |
| --- | --- | --- | --- |
| 1 | c | Character | Character |
| 2 | d | Signed decimal integer | Signed decimal integer |
| 3 | i | Signed decimal integer | Signed integer (may be decimal, octal or hexadecimal) |
| 4 | e | Scientific notation (mantissa/exponent) using e character (the output of the numbers must match up to e-6) | Decimal floating point or scientific notation (mantissa/exponent) |
| 5 | E | Scientific notation (mantissa/exponent) using E character | Decimal floating point or scientific notation (mantissa/exponent) |
| 6 | f | Decimal floating point | Decimal floating point or scientific notation (mantissa/exponent) |
| 7 | g | Uses the shortest representation of decimal floating point | Decimal floating point or scientific notation (mantissa/exponent) |
| 8 | G | Uses the shortest representation of decimal floating point | Decimal floating point or scientific notation (mantissa/exponent) |
| 9 | o | Unsigned octal | Unsigned octal |
| 10 | s | String of characters | String of characters |
| 11 | u | Unsigned decimal integer | Unsigned decimal integer |
| 12 | x | Unsigned hexadecimal integer | Unsigned hexadecimal integer (any letters) |
| 13 | X | Unsigned hexadecimal integer (capital letters) | Unsigned hexadecimal integer (any letters) |
| 14 | p | Pointer address | Pointer address |
| 15 | n | Number of characters printed until %n occurs | Number of characters scanned until %n occurs |
| 16 | % | Character % | Character % |

### sprintf Flags

| No. | Flags | Description |
| --- | --- | --- |
| 1 | - | Left-justify within the given field width; Right justification is the default (see width sub-specifier). |
| 2 | + | Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a -ve sign. |
| 3 | (space) | If no sign is going to be written, a blank space is inserted before the value. |
| 4 | # | Used with o, x or X specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero. Used with e, E and f, it forces the written output to contain a decimal point even if no digits would follow. By default, if no digits follow, no decimal point is written. Used with g or G the result is the same as with e or E but trailing zeros are not removed. |
| 5 | 0 | Left-pads the number with zeroes (0) instead of spaces, where padding is specified (see width sub-specifier). |

### sprintf And sscanf Width Description

| No. |	Width | Description |
| --- | --- | --- |
| 1	| (number) | Minimum number of characters to be printed with sprintf. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. For sscanf, this is the maximum number of characters that will be read for this field. |
| 2 | * | In sprintf the * sign means, that the width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. In sscanf the * sign placed after % and before the format specifier reads data of the specified type, but suppresses their assignment. |

### sprintf Precision Description

| No. |	.precision | Description |
| --- | --- | --- |
| 1	| .number | For integer specifiers (d, i, o, u, x, X) — precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For e, E and f specifiers — this is the number of digits to be printed after the decimal point. For g and G specifiers — This is the maximum number of significant digits to be printed. For s — this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For c type — it has no effect. When no precision is specified for specifiers e, E, f, g and G, the default one is 6. When no precision is specified for all other kind of specifiers, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed. |
| 2	| .* | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. |

### sprintf And sscanf Length Description

| No. |	Length | Description |
| --- | --- | --- |
| 1 | h | The argument is interpreted as a short int or unsigned short int (only applies to integer specifiers: i, d, o, u, x and X). |
| 2 | l | The argument is interpreted as a long int or unsigned long int for integer specifiers (i, d, o, u, x and X), and as a wide character or wide character string for specifiers c and s. |
| 3 | L | The argument is interpreted as a long double (only applies to floating point specifiers — e, E, f, g and G). |

### Special string processing functions (from the String class in C#)

| No. | Function | Description |
| ------ | ------ | ------ |
| 1 | void *to_upper(const char *str) | Returns a copy of string (str) converted to uppercase. In case of any error, return NULL. |
| 2 | void *to_lower(const char *str) | Returns a copy of string (str) converted to lowercase. In case of any error, return NULL. |
| 3 | void *insert(const char *src, const char *str, size_t start_index) | Returns a new string in which a specified string (str) is inserted at a specified index position (start_index) in the given string (src). In case of any error, return NULL. |
| 4 | void *trim(const char *src, const char *trim_chars) | Returns a new string in which all leading and trailing occurrences of a set of specified characters (trim_chars) from the given string (src) are removed. In case of any error, return NULL. |
</details>

## Chapter III

## Features & constraints

The [above](#stringh-functions) described functions of the string.h library have been implemented, as well as an own size_t type and the NULL macro:

- The library is developed in C language of the C11 standard using the gcc compiler.
- Obsolete and deprecated language constructs and library functions have not been used. Reference legacy and obsolete in the official documentation for the language and used libraries. Standard POSIX.1-2017.
- Google Style, borrowed from the standard for the C++ language ([link](https://google.github.io/styleguide/cppguide.html)).
- The product is a static library *string.a*.
- Developed according to the principles of structured programming.
- Unit tests are developed using the Check library and compare the work of the own implementation with the implementation of the standard string.h library.
- Copying the implementation and using the standard string.h library and other string processing libraries is prohibited everywhere except in unit tests.
- The use of system error lists, including lists not specified in POSIX standards (sys_nerr, sys_errlist), is prohibited. Instead, it is necessary to implement own platform-dependent error lists, as mentioned in the description of the [strerror](#stringh-functions) function.
- The logic of the standard string.h library is followed.
- Functions work with z-strings of single-byte characters in ASCII encoding.

## Part 2. Partial implementation of the sprintf function

The sprintf function from the stdio.h library has been implemented:
- All requirements outlined in [Part 1](#part-1-implementation-of-the-stringh-library-functions) apply to the function implementation.
- Partial formatting is supported:
  - Specifiers: c, d, f, s, u, %
  - Flags: -, +, (space)
  - Width: (number)
  - Precision: .(number)
  - Length: h, l

## Part 3. Advanced. Implementation of some format modifiers of the sprintf function

Some format modifiers of the sprintf function from the stdio.h library have been implemented:
- All requirements outlined in [Part 1](#part-1-implementation-of-the-stringh-library-functions) apply to the function implementation.
- The following additional format modifiers are supported:
  - Specifiers: g, G, e, E, x, X, o, p
  - Flags: #, 0 
  - Width: *
  - Precision: .*
  - Length: L

## Part 4. Advanced. Implementation of the sscanf function (in development)

The sscanf function from the stdio.h library is being implemented:
- All requirements outlined in [Part 1](#part-1-implementation-of-the-stringh-library-functions) apply to the function implementation.
- Full formatting must be supported (taking into account flags, width, modifiers, and conversion types).

## Part 5. Advanced. Implementation of special string handling functions

Some string handling functions from the String class (described [here](#special-string-handling-functions-inspired-by-the-string-class-in-c)) have been implemented:
- All requirements outlined in [Part 1](#part-1-implementation-of-the-stringh-library-functions) apply to the function implementation, except for the requirement to compare the own implementation with the standard.

## Quick start

```bash
make             # build the library
make test        # run unit tests
make gcov_report # generate coverage report (report/index.html)
