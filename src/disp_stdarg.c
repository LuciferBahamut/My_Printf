/*
** EPITECH PROJECT, 2019
** disp_stdarg.c
** File description:
** bootstrap
*/

#include "my.h"

int disp_stdarg(char *s, ...)
{
    va_list ap;

    va_start (ap, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 's')
            my_putstr(va_arg(ap, char *));
        if (s[i] == 'i')
            my_put_nbr(va_arg(ap, int));
        if (s[i] == 'c')
            my_putchar((char) va_arg(ap, int));
        my_putchar('\n');
    }
    va_end(ap);
    return (0);
}
