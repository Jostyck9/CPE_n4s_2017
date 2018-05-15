/*
** EPITECH PROJECT, 2018
** need for steak
** File description:
** algorithme
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
		return (true);
	}
	return (false);
}

float get_forward_distance(float *lidar, car_t *info)
{
	if (lidar == NULL)
		return (0);
	if (info->direction > 0) {
		return (lidar[13]);
	}
	if (info->direction < 0) {
		return (lidar[17]);
	}
	return (lidar[15]);
}

bool manage_lidar(float *lidar, car_t *info)
{
	float forward = get_forward_distance(lidar, info);

	if (forward > (LIMIT_WALL * 1.5)) {
		dprintf(2, "\t\tGo FORWARD\n");
		is_too_close_wall(lidar, info);
		dprintf(2, "\t\tdirectoin %f\n", info->direction);
		dprintf(2, "\t\tspeed %f\n", info->speed);
		info->speed = 1;
		return (true);
	} else if (forward > LIMIT_WALL) {
		dprintf(2, "\t\tGo FORWARD\n");
		is_too_close_wall(lidar, info);
		dprintf(2, "\t\tdirectoin %f\n", info->direction);
		dprintf(2, "\t\tspeed %f\n", info->speed);
		info->speed = 0.5;
		return (true);
	}
	info->speed = accelerate_car(lidar);
	info->direction = direction_car(lidar, info->speed);
	return (true);
}

bool stop_car(void)
{
	float *lidar;
	char *buffer;
	bool end = false;
	car_t info = {0, 0};

	while (end == false) {
		buffer = send_command(LIDAR_CAR);
		if (buffer == NULL || check_if_ko(buffer) == true)
			return (false);
		if (check_end(buffer)) {
			free(buffer);
			break;
		}
		lidar = get_lidar(buffer);
		if (lidar == NULL) {
			free(buffer);
			return (false);
		}
		if (manage_lidar(lidar, &info) == false) {
			free(lidar);
			free(buffer);
			return (false);
		}
		if (update_car(info, &end) == false) {
			free(lidar);
			free(buffer);
			return (false);
		}
		buffer = destroy_buffer(buffer);
		free(lidar);
	}
	return (true);
}
