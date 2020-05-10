/*
** EPITECH PROJECT, 2020
** solver
** File description:
** solver.c
*/

#include "../includes/solver.h"

void no_solutions(my_t *sol)
{
    for (int i = 0; BUFFER[i]; i++) {
        if (BUFFER[i] != '*' && BUFFER[i] != 'X' && BUFFER[i] != '\n') {
            NO_SOLUTION;
            exit(0);
        }
    } if (BUFFER[0] != '*' || BUFFER[LAST_CHAR] != '*') {
        NO_SOLUTION;
        exit(0);
    } if (sol->lines == 1) {
        for (int i = 0; BUFFER[i]; i++) {
            IS_THERE_X_IN_ONE_LINE;
        } for (int i = 0; BUFFER[i]; i++) BUFFER[i] = 'o';
    }
}
int solver_conditions(my_t *sol, int i)
{
    SOLVER_CONDITIONS;
}
void solver(my_t *sol)
{
    sol->map = malloc(sizeof(char) * my_strlen(BUFFER));
    for (int i = 0; BUFFER[i]; i++) sol->map[i] = BUFFER[i];
    sol->char_line = 0;
    sol->lines = 1;
    for (; BUFFER[sol->char_line] != '\n' && BUFFER[sol->char_line];
    sol->char_line++);
    for (int i = 0; BUFFER[i]; i++) if (BUFFER[i] == '\n') sol->lines++;
    no_solutions(sol);
    for (int i = 0; i != LAST_CHAR;) {
        i = solver_conditions(sol, i);
        if (i == LAST_CHAR) break;
    } for (int i = 0; BUFFER[i]; i++)
        if (BUFFER[i] == 'o' || BUFFER[i] == 'p') sol->map[i] = 'o';
}

int main(int ac, char **av)
{
    int fd = 0;
    int len = 0;
    int map_size = 0;
    struct stat stat_struct;

    my_t *sol = malloc(sizeof(my_t));
    if (ac != 2) return (84);
    if ((fd = open(av[1], O_RDONLY)) == -1) return (84);
    stat(av[1], &stat_struct);
    map_size = stat_struct.st_size;
    BUFFER = malloc(sizeof(char) * map_size + 1);
    if ((len = read(fd, BUFFER, map_size)) == -1) return (84);
    solver(sol);
    my_putstr(sol->map);
}