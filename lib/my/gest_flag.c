/*
** EPITECH PROJECT, 2019
** gest_flag
** File description:
** my_printf
*/

#include "my.h"

int convert_octal_i(int nb)
{
    int result = 0;

    for (int base = 8; nb != 0; nb /= base) {
        result = (nb % base) + '0';
    }
    return (result);
}

void nprint(char const *fmt, va_list ap)
{
    char *str = va_arg(ap, char *);
    int nbo;
    char *result = malloc(3 + 1);
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= ' ' && str[i] < '%' || str[i] <= 127 && str[i] > '%')
            my_putchar(str[i]);
        if (str[i] <= ' ' && str[i] < '%' || str[i] >= 127 && str[i] < '%') {
            nbo = str[i];
            my_putchar('\\');
            nbo = convert_octal_i(nbo);
            if (nbo <= 7)
                my_putstr("00");
            if (nbo <= 77)
                my_putchar('0');
            my_put_nbr(nbo);
        }
    }
}

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
            case 'u' : my_put_nbr(va_arg(ap, int));
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
            case 'S' : nprint(fmt, ap);
                break;
            case '%' : my_putchar('%');
                break;
            }
        }
    }
    next_flag(fmt, ap);
}

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
