/*
** EPITECH PROJECT, 2018
** main
** File description:
** main function
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ai.h"

char *destroy_buffer(char *buffer)
{
	if (buffer == NULL) {
		return (NULL);
	}
	free(buffer);
	return (NULL);
}

int main(void)
{
	char *buffer = NULL;

	buffer = send_command(START_N4S);
	if (buffer == NULL || check_if_ko(buffer) == true)
		return (84);
	buffer = destroy_buffer(buffer);
	if (stop_car() == false)
		return (84);
	buffer = send_command(STOP_N4S);
	if (buffer == NULL || check_if_ko(buffer) == true)
		return (84);
	buffer = destroy_buffer(buffer);
	return (0);
}
