/*
** EPITECH PROJECT, 2020
** generator
** File description:
** imparfait
*/

#include "../includes/generator.h"

int nb_aster_on_line(char **map, coord_t *coord)
{
    int i = 0;

    coord->x = 0;
    while (map[coord->x]) {
        if (map[coord->y][coord->x] == '*') i++;
        coord->x++;
    } return (i);
}

char **fucking_conditional_branching(char **map, coord_t *coord, int x)
{
    if (coord->x < x+1) map[coord->y][coord->x] = '*';
    return (map);
}

char **add_some_aster(char **map, coord_t *coord, int x)
{
    coord->x = 0;
    coord->y = 0;
    if (nb_lines(map) == 1 || nb_cols(map) == 1) return (map);
    while (map[coord->y]) {
        coord->random = rand() % x;
        coord->x = 0;
        coord->x += coord->random;
        while (map[coord->y][coord->x] == 'X')
            fucking_conditional_branching(map, coord, x);
        if (nb_aster_on_line(map, coord) > 1) coord->y++;
    } return (map);
}

char **imparfait(char **map, int x, coord_t *coord)
{
    coord->random = rand();
    if (coord->random % 2)
        while (map[coord->y]) printx_e(map, coord, x);
    else
        while (map[coord->y]) printe_x(map, coord, x);
    coord->y = 0;
    while (map[coord->y+2]) {
        coord->y++;
        coord->totox = rand() % (x/2);
        if (map[coord->y][coord->x] == 'X') map[coord->y][coord->totox] = '*';
    } add_some_aster(map, coord, x);
    return (map);
}