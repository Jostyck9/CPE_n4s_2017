/*
** EPITECH PROJECT, 2018
** need4steak
** File description:
** printing functions
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void my_putchar(char a)
{
	write(1, &a, 1);
}

void my_putchar_error(char a)
{
	write(2, &a, 1);
}

void my_putstr_error(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		my_putchar_error(str[i]);
}

void my_putstr(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
}
