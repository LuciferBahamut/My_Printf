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
            case 'o' : my_putchar('o');
                break;
            case 'u' : my_putchar('u');
                break;
            case 'x' : my_putchar('x');
                break;
            case 'X' : my_putchar('X');
                break;
            case 'p' : my_putchar('p');
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
            case 'b' : my_putchar('b');
                break;
            case 'S' : my_putchar('S');
                break;
            case '%' : my_putchar('%');
                break;
            }
        }
    }
    next_flag(fmt, ap);
}
