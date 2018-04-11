/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** Do same than printf.
*/

#include <stdarg.h>
#include <stdio.h>

void my_printf(char *str, ...)
{
	va_list arg;
	int i = 0;
	int count;

	va_start(arg, str);
	while (str[i] != '\0') {
		if (str[i] == '\\' && str[i + 1] == 'n') {
			my_putchar('\n');
			i += 2;
		}
		if (str[i] != '%') {
			my_putchar(str[i]);
		} else {
			display(str[i + 1], arg);
			i++;
		}
		i++;
	}
	va_end(arg);
}
