/*
** EPITECH PROJECT, 2019
** unit_tests
** File description:
** printf
*/

#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello");
    cr_assert_stdout_eq_str("hello world");
}