/*
** EPITECH PROJECT, 2018
** main.h
** File description:
** main header
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "display.h"
#include "game.h"
#include "utils.h"

int check_map(int *, int);
int *init_map(int);
int all_game(int *, int, int, int);

char *get_next_line(int);

#endif
