/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** little_fonctions
*/

#include "../includes/generator.h"

char **exceptions(char **map)
{
    if (nb_lines(map) == 1 || nb_cols(map) == 1)
        for (int y = 0, x = 0; map[y][x]; map[y][x++] = '*');
    return (map);
}

int isnumber(char *str)
{
    if (str == NULL) return (0);
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9') return (84);
    return (0);
}