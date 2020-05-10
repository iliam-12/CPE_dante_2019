/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** generator
*/

#include "../includes/generator.h"

char **printtab(char **map)
{
    for (int y = 0; map[y]; y++) {
        my_putstr(map[y]);
        if (map[y+1])
            my_putchar('\n');
    } return (map);
}

char **add_aster_begin_end(int x, int y, char **map)
{
    map[0][0] = '*';
    map[y - 1][x - 1] = '*';
    return (map);
}

void g_laby(char **map, coord_t *coord, int ac, char **av)
{
    coord->x = 0;
    coord->y = 0;
    if (ac == 4 && my_strcmp(av[3], "perfect") == 0)
        parfait(map, my_getnbr(av[1]), coord);
    else
        imparfait(map, my_getnbr(av[1]), coord);
    add_aster_begin_end(my_getnbr(av[1]), my_getnbr(av[2]), map);
    printtab(map);
}

int main(int ac, char **av)
{
    srand(time(NULL));
    coord_t *coord = malloc(sizeof(coord_t));
    char **map = NULL;

    if (ac < 3 || ac > 4) return (84);
    coord->x = my_getnbr(av[1]);
    coord->y = my_getnbr(av[2]);
    if (coord->x <= 1 || coord->y <= 1) return (84);
    map = malloc(sizeof(char *) * coord->y + 1);
    if (isnumber(av[1]) != 0 || isnumber(av[2]) != 0) return (84);
    for (int i = 0; i != coord->y; i++) {
        if ((map[i] = malloc(sizeof(char) * (coord->x + 1))) == NULL)
            map[i][coord->x] = '\0';
    } g_laby(map, coord, ac, av);
}