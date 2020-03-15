/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils
*/

#include "main.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *s)
{
	for (int i = 0; s[i]; i++)
		my_putchar(s[i]);
}

int my_getnbr(char *s)
{
	int i;
	int nb = 0;
	int check = 0;

	for (i = 0; s[i]; i++) {
		if (check == 1 && s[i] > 47 && s[i] < 58) {
			my_putstr("Error: invalid input ");
			my_putstr("(positive number expected)\n");
			return (-1);
		}
		if (check == 0 && s[i] != ' ')
			nb = nb * 10 + s[i] - 48;
		if (s[i] != ' ' && s[i + 1] == ' ')
			check = 1;
	}
	return (nb);
}

int number_isneg(int nb)
{
	if (nb < 0) {
		write(1, "-", 1);
		nb = -nb;
	}
	return (nb);
}

int my_put_nbr(int nb)
{
	char c[9];
	char c2[9];
	int i = 0;
	int j = 0;

	nb = number_isneg(nb);
	while (nb > 0 || i == 0) {
		c[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	c[i] = '\0';
	for (j = 0; c[j] != '\0'; j++) {
		c2[j] = c[i - j - 1];
	}
	c2[j] = '\0';
	my_putstr(c2);
	return (0);
}
