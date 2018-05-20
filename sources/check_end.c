/*
** EPITECH PROJECT, 2018
** check_end.c
** File description:
** Check if the car ended the map.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ai.h"

bool check_cmd_end(char *cmd)
{
	char *str = cmd;
	char *token = NULL;

	do {
		token = strtok(str, ":");
		str = NULL;
		if (token != NULL && strcmp(token, END_STR) == 0) {
			token = strtok(str, ":");
			dprintf(2, "Track Cleared %s", token);
			free(cmd);
			return (true);
		}
	} while (token != NULL);
	free(cmd);
	return (false);
}

bool check_end(char *str)
{
	char *res = NULL;

	if (str == NULL)
		return (false);
	res = strdup(str);
	if (res == NULL)
		return (false);
	return (check_cmd_end(res));
}
