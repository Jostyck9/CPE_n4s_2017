/*
** EPITECH PROJECT, 2017
** needs_for_my_printf.c
** File description:
** Functions for my_printf.
*/

#include <stdarg.h>
#include <stdio.h>

int display1(char c, va_list arg)
{
	switch (c) {
	case 'i':
	case 'd':
		my_put_nbr(va_arg(arg, int));
		return (0);
	case 'c':
		my_putchar(va_arg(arg, int));
		return (0);
	case 's':
		my_putstr(va_arg(arg, char*));
		return (0);
	case '%':
		my_putchar('%');
		return (0);
	}
	return (1);
}

int display(char c, va_list arg)
{
	if (display1(c, arg) == 1)
		return (84);
	return (0);
}
