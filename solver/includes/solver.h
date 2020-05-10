/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

/* ___ INCLUDES ___ */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

/* ___ DEFINE ___ */

#define BUFFER sol->buffer
#define CHAR_UP (i - sol->char_line - 1)
#define CHAR_RIGHT (i + 1)
#define CHAR_LEFT (i - 1)
#define CHAR_DOWN (i + sol->char_line + 1)
#define NO_SOLUTION my_putstr("no solution found\n");
#define LAST_CHAR ((sol->char_line * sol->lines) + (sol->lines - 1) - 1)
#define IS_THERE_X_IN_ONE_LINE if (BUFFER[i] == 'X') { \
                NO_SOLUTION; \
                exit(0); \
            }
#define SOLVER_CONDITIONS if (i == 0 && BUFFER[CHAR_RIGHT] == 'X' && BUFFER[CHAR_DOWN] == 'X') { \
        NO_SOLUTION; \
        exit(0); \
    } else if (i == 0 && (BUFFER[CHAR_RIGHT] == '*' || \
    BUFFER[CHAR_DOWN] == '*')) BUFFER[i] = 'o'; \
    if (BUFFER[CHAR_DOWN] == '*') { \
        if (BUFFER[i] != 'o') BUFFER[i] = 'o'; \
        BUFFER[CHAR_DOWN] = 'o'; \
        i = CHAR_DOWN; \
        return (i); \
    } else if (BUFFER[CHAR_DOWN] == 'o') { \
        if (BUFFER[i] == 'o') BUFFER[i] = 'X'; \
        BUFFER[CHAR_DOWN] = 'X'; \
        i = CHAR_DOWN; \
        return (i); \
    } \
    if (BUFFER[CHAR_RIGHT] == '*') { \
        if (BUFFER[i] != 'o') BUFFER[i] = 'o'; \
        BUFFER[CHAR_RIGHT] = 'o'; \
        i = CHAR_RIGHT; \
        return (i); \
    } else if (BUFFER[CHAR_RIGHT] == 'o') { \
        if (BUFFER[i] == 'o') BUFFER[i] = 'X'; \
        BUFFER[CHAR_RIGHT] = 'X'; \
        i = CHAR_RIGHT; \
        return (i); \
    } \
    if (BUFFER[CHAR_LEFT] == '*') { \
        if (BUFFER[i] != 'o' || BUFFER[i] != 'p') BUFFER[i] = 'p'; \
        BUFFER[CHAR_LEFT] = 'p'; \
        i = CHAR_LEFT; \
        return (i); \
    } else if (BUFFER[CHAR_LEFT] == 'o') { \
        if (BUFFER[i] == 'o') BUFFER[i] = 'X'; \
        BUFFER[CHAR_LEFT] = 'o'; \
        i = CHAR_LEFT; \
        printf("L-"); \
        return (i); \
    } \
    if (BUFFER[CHAR_UP] == '*') { \
        if (BUFFER[i] != 'o') BUFFER[i] = 'o'; \
        BUFFER[CHAR_UP] = 'o'; \
        i = CHAR_UP; \
        return (i); \
    } else if (BUFFER[CHAR_UP] == 'o') { \
        if (BUFFER[i] == 'o') BUFFER[i] = 'X'; \
        BUFFER[CHAR_UP] = 'X'; \
        i = CHAR_UP; \
        return (i); \
    } \
    return (i);

/* ___ STRUCTURES ___ */
typedef struct my_struct_s {
    int char_line;
    int lines;
    int ancient_pos;
    char *buffer;
    char *map;
} my_t;

/* ___ FONCTIONS ___ */
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);

#endif /* !SOLVER_H_ */