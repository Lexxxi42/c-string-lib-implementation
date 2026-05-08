#ifndef HANDLER_H
#define HANDLER_H

#include "string.h"

int handle_option(const char option, char **current, va_list *args,
                  flags *flag);
int handle_percent(char **str);
int handle_c(va_list *args, flags *flag);
int handle_d(va_list *args, flags *flag);
int handle_f(va_list *args, flags *flag);
int handle_s(va_list *args, flags *flag);
int handle_u(va_list *args, flags *flag);
int handle_g(va_list *args, flags *flag);
int handle_e(va_list *args, flags *flag);
int handle_x(va_list *args, flags *flag);
int handle_o(va_list *args, flags *flag);
int handle_p(va_list *args, flags *flag);

#endif