/*
** EPITECH PROJECT, 2018
** game.h
** File description:
** game header
*/

#ifndef GAME_H_
#define GAME_H_

int get_nb(void);
int choose_line(int *, int);
int choose_matches(int *, int, int, int);
int game_play(int *, int, int);
void game_ai(int *, int, int);
int ai_matches(int *, int, int);

#endif
