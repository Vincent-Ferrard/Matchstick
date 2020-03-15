/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display
*/

#include "main.h"

void print_game_board(int *map, int line)
{
	int i;

	for (i = 0; i < line * 2 + 1; i++)
		my_putchar('*');
	my_putchar('\n');
	print_inter_board(map, line);
	for (i = 0; i < line * 2 + 1; i++)
		my_putchar('*');
	my_putchar('\n');
}

void print_inter_board(int *map, int line)
{
	int i;
	int j;
	int nb_space1 = 0;

	for (j = 0; j < line; j++) {
		my_putchar('*');
		for (i = 0; i < ((2 * line - 1) - ((j + 1) * 2 - 1)) / 2; i++)
			my_putchar(' ');
		nb_space1 = i;
		for (i = 0; i < map[j]; i++)
			my_putchar('|');
		for (i = 0; i < (2 * line - 1) - map[j] - nb_space1; i++)
			my_putchar(' ');
		my_putchar('*');
		my_putchar('\n');
	}
}
