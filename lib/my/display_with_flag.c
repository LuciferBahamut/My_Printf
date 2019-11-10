/*
** EPITECH PROJECT, 2019
** display with flags
** File description:
** my_printf
*/

#include "my.h"

void display(char const *fmt, va_list ap)
{
    for (int i = 0; fmt[i] != '\0'; i++) {
        if (fmt[i] >= ' ' && fmt[i] < '%' || fmt[i] <= 127 && fmt[i] > '%')
            my_putchar(fmt[i]);
        if (fmt[i] == '%') {
            i++;
            gest_flag(fmt, ap);
        }
    }
}
