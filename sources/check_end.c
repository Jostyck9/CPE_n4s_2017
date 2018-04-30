/*
** EPITECH PROJECT, 2018
** check_end.c
** File description:
** Check if the car ended the map.
*/

#include "ai.h"

bool check_end(char *str)
{
	if (strcmp(str, END_STR) == 0)
		return (true);
	return (false);
}
