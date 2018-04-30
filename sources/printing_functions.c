/*
** EPITECH PROJECT, 2018
** need4steak
** File description:
** printing functions
*/

#include <string.h>
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
	int size = 0;

	if (str != NULL) {
		size = strlen(str);
		write(2, str, size);
	}
}

void my_putstr(char *str)
{
	int size = 0;

	if (str != NULL) {
		size = strlen(str);
		write(1, str, size);
	}
}
