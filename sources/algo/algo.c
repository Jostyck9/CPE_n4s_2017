/*
** EPITECH PROJECT, 2018
** need for steak
** File description:
** algorithme
*/

#include "ai.h"
#include <stdlib.h>
#include <stdio.h>

int check_if_ko(char *buffer)
{
	int i = 0;

	if (buffer == NULL)
		return (84);
	for (; buffer[i] != ':' && buffer[i] != '\0'; i++);
	if (buffer[i] == '\0' || buffer[i + 1] == 'K') {
		free(buffer);
		return (84);
	}
	return (0);
}

int stop_car(char *buffer)
{
	float speed = 1;

	while (speed > 0) {
		buffer = send_command(LIDAR_CAR);
		if (buffer == NULL || check_if_ko(buffer) == 84)
			return (84);
		speed = accelerate_car(get_lidar(buffer));
		dprintf(2, "speed : %f\n", speed);
		buffer = destroy_buffer(buffer);
		if (speed == -1)
			break;
		buffer = send_command_value(SPEED_CAR, speed);
		if (buffer == NULL || check_if_ko(buffer) == 84)
			return (84);
		buffer = destroy_buffer(buffer);
	}
	return (0);
}
