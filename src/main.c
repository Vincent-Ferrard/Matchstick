/*
** EPITECH PROJECT, 2018
** print_game_board.c
** File description:
** print_game_board
*/

#include "main.h"

int check_map(int *map, int line)
{
	for (int i = 0; i < line; i++)
		if (map[i] != 0)
			return (0);
	return (1);
}

int *init_map(int line)
{
	int i;
	int *map = malloc(sizeof(int) * line);

	for (i = 0; i < line; i++)
		map[i] = i * 2 + 1;
	return (map);
}

int all_game(int *map, int line, int matches_max, int player)
{
	print_game_board(map, line);
	my_putchar('\n');
	if (player == 1) {
		my_putstr("Your turn:\n");
		if (game_play(map, matches_max, line) == -1)
			return (-1);
		player = 2;
	} else {
		my_putstr("AI's turn...\n");
		game_ai(map, line, matches_max);
		player = 1;
	}
	return (player);
}

int main(int ac, char **av)
{
	int line;
	int matches_max;
	int *map;
	int player = 1;

	if (ac != 3) {
		my_putstr("Bad number of arguments.\n");
		return (84);
	}
	line = my_getnbr(av[1]);
	if (line == -1 || line < 2 || line > 99)
		return (84);
	matches_max = my_getnbr(av[2]);
	if (matches_max < 1)
		return (84);
	map = init_map(line);
	while (check_map(map, line) != 1)
		if ((player = all_game(map, line, matches_max, player)) == -1)
			return (0);
	print_game_board(map, line);
	free(map);
	if (player == 1) {
		my_putstr("I lost... snif... but I'll get you next time!!\n");
		return (1);
	} else {
		my_putstr("You lost, too bad...\n");
		return (2);
	}
}
