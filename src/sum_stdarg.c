/*
** EPITECH PROJECT, 2019
** sum_stdarg.c
** File description:
** bootstrap
*/

#include "my.h"

int sum_stdarg(int i, int nb, ...)
{
    va_list ap;
    int sum = 0;

    va_start (ap, nb);
    if (i == 0) {
        for (int j = 0; nb != 0; j++) {
            sum = sum + va_arg (ap, int);
            nb--;
        }
        return (sum);
    }
    if (i == 1) {
        for (int j = 0; nb != 0; j++) {
            sum = sum + my_strlen(va_arg (ap, char*));
            nb--;
        }
        return (sum);
    }
    va_end(ap);
    return(0);
}
