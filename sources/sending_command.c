/*
** EPITECH PROJECT, 2018
** need_4_steak
** File description:
** sending commands functions
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ai.h"

char *recup_std_input(void)
{
	size_t size = 0;
	char *buffer = NULL;

	if (getline(&buffer, &size, stdin) != -1) {
		return (buffer);
	}
	return (NULL);
}

char *send_command(char *cmd)
{
	char *buffer = NULL;

	if (cmd == NULL) {
		return (NULL);
	}
	my_putstr(cmd);
	buffer = recup_std_input();
	return (buffer);
}

char *send_command_value_int(char *cmd, int value)
{
	char *buffer = NULL;

	if (cmd == NULL) {
		return (NULL);
	}
	buffer = malloc(sizeof(*buffer) * (snprintf(NULL, 0, cmd, value) + 1));
	if (buffer == NULL) {
		return (NULL);
	}
	sprintf(buffer, cmd, value);
	my_putstr(buffer);
	free(buffer);
	buffer = recup_std_input();
	return (buffer);
}

char *send_command_value(char *cmd, float value)
{
	char *buffer = NULL;

	if (cmd == NULL) {
		return (NULL);
	}
	buffer = malloc(sizeof(*buffer) * (snprintf(NULL, 0, cmd, value) + 1));
	if (buffer == NULL) {
		return (NULL);
	}
	sprintf(buffer, cmd, value);
	my_putstr(buffer);
	free(buffer);
	buffer = recup_std_input();
	return (buffer);
}
