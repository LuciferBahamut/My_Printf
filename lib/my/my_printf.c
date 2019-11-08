/*
** EPITECH PROJECT, 2019
** myprintf
** File description:
** myprintf
*/

#include "my.h"

int my_printf(const char *fmt, ...)
{
    va_list ap;

    disp_stdarg(fmt, ap);
    return (0);
}
