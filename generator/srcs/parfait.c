/*
** EPITECH PROJECT, 2020
** generator
** File description:
** parfait
*/

#include "../includes/generator.h"

int nb_lines(char **map)
{
    int lines = 0;

    while (map[lines]) lines++;
    return (lines);
}

int nb_cols(char **map)
{
    int y = 0;
    int cols = 0;

    while (map[y][cols]) cols++;
    return (cols);
}

char **printx_e(char **map, coord_t *coord, int x)
{
    if (coord->y % 2) {
        map[coord->y][coord->x] = 'X';
        coord->x++;
        if (coord->x == x) {
            coord->x = 0;
            coord->y++;
        }
    } else {
        map[coord->y][coord->x] = '*';
        coord->x++;
        if (coord->x == x) {
            coord->x = 0;
            coord->y++;
        }
    } return (map);
}

char **printe_x(char **map, coord_t *coord, int x)
{
    if (coord->y % 2) {
        map[coord->y][coord->x] = '*';
        coord->x++;
        if (coord->x == x) {
            coord->x = 0;
            coord->y++;
        }
    } else {
        map[coord->y][coord->x] = 'X';
        coord->x++;
        if (coord->x == x) {
            coord->x = 0;
            coord->y++;
        }
    } return (map);
}

char **parfait(char **map, int x, coord_t *coord)
{
    coord->random = rand();
    if (coord->random % 2) {
        while (map[coord->y])
            printx_e(map, coord, x);
    } if (!(coord->random % 2)) {
        while (map[coord->y])
            printe_x(map, coord, x);
    } coord->y = 0;
    while (map[coord->y+2]) {
        coord->y++;
        coord->totox = rand() % x;
        if (map[coord->y][coord->x] == 'X') map[coord->y][coord->totox] = '*';
    } exceptions(map);
    return (map);
}