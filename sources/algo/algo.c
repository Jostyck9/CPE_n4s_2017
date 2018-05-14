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
		free(buffer);
		return (true);
	}
	return (false);
}

int get_forward_distance(int *lidar)
{
	if (lidar == NULL)
		return (0);
	return (lidar[15]);
}

bool manage_lidar(int *lidar, car_t *info)
{
	int forward = get_forward_distance(lidar);

	//check dist coté
	if (forward > LIMIT_WALL) {
		info->speed = 1;
		info->direction = 0;
		return (true);
	}
	info->speed = accelerate_car(lidar);
	info->direction = direction_car(lidar);
	return (true);
}

bool stop_car(void)
{
	int *lidar;
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
