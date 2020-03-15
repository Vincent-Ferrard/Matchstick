/*
** EPITECH PROJECT, 2018
** test.c
** File description:
** test
*/

#include "main.h"

char *get_next_line(int fd)
{
	int i;
	char *s = malloc(sizeof(char) * 10);

	read(fd, &s[0], 1);
	if (s[0] == '\0')
		return (NULL);
	for (i = 1; s[i - 1] != '\n'; i++)
		read(fd, &s[i], 1);
	s[i - 1] = '\0';
	return (s);
}
