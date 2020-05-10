/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** toolbox
*/

#include "../includes/solver.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i]) my_putchar(str[i++]);
}

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL) return (0);
    for (i = 0; str[i]; i++);
    return (i);
}