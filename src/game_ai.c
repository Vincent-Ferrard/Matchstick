/*
** EPITECH PROJECT, 2018
** game_ai.c
** File description:
** game_ai
*/

#include "main.h"

void game_ai(int *map, int line, int matches_max)
{
	int line_choose = -1;
	int matches = 0;

	srand(time(NULL));
	while (line_choose == -1) {
		line_choose = rand() % line;
		if (map[line_choose] == 0)
			line_choose = -1;
	}
	while (matches == 0) {
		matches = (rand() % matches_max) + 1;
		matches = ai_matches(map, matches, line_choose);
	}
	map[line_choose] = map[line_choose] - matches;
	my_putstr("AI removed ");
	my_put_nbr(matches);
	my_putstr(" match(es) from line ");
	my_put_nbr(line_choose + 1);
	my_putchar('\n');
}

int ai_matches(int *map, int matches, int line_choose)
{
	int less = 1;

	if (matches > map[line_choose])
		matches = 0;
	else if (matches == map[line_choose] && map[line_choose] != 1) {
		for (int i = 0; map[i]; i++)
			if (map[i] != 0 && i != line_choose)
				less = 0;
		if (less == 1)
			matches--;
	}
	return (matches);
}
