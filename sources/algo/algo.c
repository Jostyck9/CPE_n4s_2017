/*
** EPITECH PROJECT, 2018
** need for steak
** File description:
** algorithme
*/

#include <stdlib.h>
#include <stdio.h>
#include "ai.h"

float get_forward_distance(float *lidar)
{
	float result = 0;

	if (lidar == NULL)
		return (0);
	result = (lidar[16] + lidar[14] + lidar[15] + lidar[17]);
	result /= 4;
	return (result);
}

bool manage_lidar(float *lidar, car_t *info)
{
	float forward = get_forward_distance(lidar);

	if (forward > LIMIT_WALL) {
		dprintf(2, "\t\tGo FORWARD\n");
		is_too_close_wall(lidar, info);
		dprintf(2, "\t\tdirectoin %f\n", info->direction);
		dprintf(2, "\t\tspeed %f\n", info->speed);
		info->speed = GO_SPEED_MAX;
		return (true);
	}
	//info->speed = accelerate_car(lidar, forward);
	info->speed = SPEED_DRIFT;
	info->direction = direction_car(lidar, info->speed, forward);
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
//		dprintf(2, "End update\n");
		buffer = destroy_buffer(buffer);
		free(lidar);
	}
	return (true);
}
