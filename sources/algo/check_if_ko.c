/*
** EPITECH PROJECT, 2018
** need for steak
** File description:
** function check_if_ko
*/

#include <stdlib.h>
#include <stdio.h>
#include "ai.h"

bool check_if_ko(char *buffer)
{
	int i = 0;

	if (buffer == NULL)
		return (true);
	for (; buffer[i] != ':' && buffer[i] != '\0'; i++);
	if (buffer[i] == '\0' || buffer[i + 1] == 'K') {
		dprintf(2, "Error: %s", buffer);
		return (true);
	}
	return (false);
}
