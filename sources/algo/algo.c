/*
** EPITECH PROJECT, 2018
** need for steak
** File description:
** algorithme
*/

#include <stdlib.h>
#include <stdio.h>
#include "ai.h"

float get_forward_distance(float *lidar, car_t *info)
{
	float result = 0;

	if (lidar == NULL)
		return (0);
	result = (lidar[13] + lidar[14] + lidar[15]);
	result /= 3;
	return (result);
}

bool manage_lidar(float *lidar, car_t *info)
{
	float forward = get_forward_distance(lidar, info);

	if (forward > LIMIT_WALL && lidar[31] > 10 && lidar[0] > 10) {
		dprintf(2, "\t\tGo FORWARD\n");
		is_too_close_wall(lidar, info);
		dprintf(2, "\t\tdirectoin %f\n", info->direction);
		dprintf(2, "\t\tspeed %f\n", info->speed);
		info->speed = GO_SPEED_MAX;
		return (true);
	}
	info->speed = SPEED_DRIFT;
	info->direction = direction_car(lidar, info->speed);
	info->speed = accelerate_car(lidar, info->direction);
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
