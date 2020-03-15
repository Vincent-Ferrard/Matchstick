/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game
*/

#include "main.h"

int get_nb(void)
{
	int i;
	char *s = NULL;

	if ((s = get_next_line(0)) == NULL)
		return (-2);
	if (s[0] == '\0') {
		my_putstr("Error: invalid input "); 
		my_putstr("(positive number expected)\n");
		return (-1);
	}
	for (i = 0; s[i]; i++)
		if ((s[i] < 48 || s[i] > 57) && s[i] != ' ') {
			my_putstr("Error: invalid input "); 
			my_putstr("(positive number expected)\n");
			return (-1);
		}
	return (my_getnbr(s));
}

int choose_line(int *map, int line)
{
	int line_choose = -1;

	while (line_choose == -1) {
		my_putstr("Line: ");
		if ((line_choose = get_nb()) == -2)
			return (-2);
		if (line_choose > line || line_choose == 0) {
			line_choose = -1;
			my_putstr("Error: this line is out of range\n");
		} else if (map[line_choose - 1] == 0) {
			line_choose = -1;
			my_putstr("Error: no matches on this line\n");
		}
	}
	return (line_choose);
}

int choose_matches(int *map, int matches_max, int matches, int line_choose)
{
	while (matches == -1 || matches > matches_max) {
		my_putstr("Matches: ");
		if ((matches = get_nb()) == -2)
			return (-2);
		if (matches > matches_max) {
			matches = -1;
			my_putstr("Error: you cannot remove more than ");
			my_put_nbr(matches_max);
			my_putstr(" matches per turn\n");
		}
		if (matches > map[line_choose - 1]) {
			matches = -1;
			my_putstr("Error: not enough matches on this line\n");
		} else if (matches == 0) {
			matches = -1;
			my_putstr("Error: you have to remove ");
			my_putstr("at least one match\n");
		}
	}
	return (matches);
}

int game_play(int *map, int matches_max, int line)
{
	int line_choose;
	int matches;

	if ((line_choose = choose_line(map, line)) == -2)
		return (-1);
	matches = choose_matches(map, matches_max, -1, line_choose);
	if (matches == -2)
		return (-1);
	map[line_choose - 1] = map[line_choose - 1] - matches;
	my_putstr("Player removed ");
	my_put_nbr(matches);
	my_putstr(" match(es) from line ");
	my_put_nbr(line_choose);
	my_putchar('\n');
	return (0);
}
