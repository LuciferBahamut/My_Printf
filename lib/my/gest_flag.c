/*
** EPITECH PROJECT, 2019
** gest_flag
** File description:
** my_printf
*/

#include "my.h"

void next_flag(char const *fmt, va_list ap)
{
    for (int i = 0; fmt[i] != '\0'; i++) {
        if (fmt[i] == '%') {
            i++;
            switch(fmt[i]) {
            case 'i' : my_put_nbr(va_arg(ap, int));
                break;
            case 'o' : convert_base(8, va_arg(ap, int), 1);
                break;
            case 'u' : my_put_nbr(va_arg(ap,int));
                break;
            case 'x' : convert_base(16, va_arg(ap, int), 2);
                break;
            case 'X' : convert_base(16, va_arg(ap, int), 3);
                break;
            case 'p' : convert_base(16, va_arg(ap, int), 4);
                break;
            }
        }
    }
}

void gest_flag(char const *fmt, va_list ap)
{
    for (int i = 0; fmt[i] != '\0'; i++) {
        if (fmt[i] == '%') {
            i++;
            switch(fmt[i]) {
            case 's' : my_putstr(va_arg(ap, char *));
                break;
            case 'd' : my_put_nbr(va_arg(ap, int));
                break;
            case 'c' : my_putchar((char) va_arg(ap, int));
                break;
            case 'b' : convert_base(2, va_arg(ap, int), 0);
                break;
            case 'S' : convert_base(8, va_arg(ap, int), 1);
                break;
            case '%' : my_putchar('%');
                break;
            }
        }
    }
    next_flag(fmt, ap);
}
