/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my_printf
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_printf(const char *fmt, ...);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
void gest_flag(char const *fmt, va_list ap);
int error_handling(char const *fmt);
void display(char const *fmt, va_list ap);

#endif
