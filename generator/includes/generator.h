/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

/* ___ INCLUDES ___ */

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

/* ___ STRUCTURES ___ */

struct coord
{
    int x;
    int y;
    int i;
    int random;
    int totox;
    int pass;
};

typedef struct coord coord_t;

/* ___ FONCTIONS ___ */

int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int isnumber(char *str);
void my_put_nbr(int n);
char **printe_x(char **map, coord_t *coord, int x);
char **printx_e(char **map, coord_t *coord, int x);
char **parfait(char **map, int x, coord_t *coord);
char **imparfait(char **map, int x, coord_t *coord);
char **exceptions(char **map);
int nb_lines(char **map);
int nb_cols(char **map);

#endif /* !GENERATOR_H_ */
