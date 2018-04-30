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

int check_if_ko(char *buffer)
{
	int i = 0;

	if (buffer == NULL)
		return (84);
	for (; buffer[i] != ':' && buffer[i] != '\0'; i++);
	if (buffer[i] == '\0') {
		free(buffer);
		return (84);
	}
	if (buffer[i + 1] == 'K') {
		free(buffer);
		return (84);
	}
	return (0);
}

char *recup_std_input(void)
{
	size_t size = 0;
	char *buffer = NULL;

	if (getline(&buffer, &size, stdin) != -1) {
		my_putstr_error(buffer);
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

char *send_command_value(char *cmd, float value)
{
	char *buffer_cmd = NULL;
	char *buffer = NULL;

	if (cmd == NULL) {
		return (NULL);
	}
	buffer_cmd = malloc(sizeof(*buffer_cmd) * (snprintf(NULL, 0, cmd, value) + 1));
	sprintf(buffer_cmd, cmd, value);
	my_putstr(buffer_cmd);
	free(buffer_cmd);
	buffer = recup_std_input();
	return (buffer);
}

int transform_lidar_in_speed(char *buffer)
{
	int i = 0;
	int nbr_value = 0;
	int j = 0;
	int result = 0;
	float speed = 0;

	for (; nbr_value < 19; i++) {
		if (buffer[i] == ':')
			nbr_value++;
	}
	for (j = i; buffer[j] != '.' ; j++);
	buffer[j] = '\0';
	my_putchar_error('\n');
	my_putstr_error(&buffer[i]);
	my_putchar_error('\n');
	result = atoi(&buffer[i]);
	result /= 10;
	if (result < 90)
		speed = 0;
	else if (result > 200)
		speed = 1;
	else
		speed = result / 100;
	return (speed);
}

int stop_car(char *buffer, float speed)
{
	while (speed != 0) {
		buffer = send_command("GET_INFO_LIDAR\n");
		if (buffer == NULL || check_if_ko(buffer) == 84)
			return (84);
		speed = transform_lidar_in_speed(buffer);
		buffer = destroy_buffer(buffer);
		buffer = send_command_value("CAR_FORWARD:%f\n", speed);
		if (buffer == NULL || check_if_ko(buffer) == 84)
			return (84);
		buffer = destroy_buffer(buffer);
	}
	return (0);
}

int main(void)
{
	char *buffer = NULL;
	float speed = 1;

	buffer = send_command("START_SIMULATION\n");
	if (buffer == NULL || check_if_ko(buffer) == 84)
		return (84);
	buffer = destroy_buffer(buffer);
	buffer = send_command_value("CAR_FORWARD:%f\n", speed);
	if (buffer == NULL || check_if_ko(buffer) == 84)
		return (84);
	buffer = destroy_buffer(buffer);
	if (stop_car(buffer, speed) == 84)
		return (84);
	buffer = send_command("STOP_SIMULATION\n");
	if (buffer == NULL || check_if_ko(buffer) == 84)
		return (84);
	buffer = destroy_buffer(buffer);
	return (0);
}
