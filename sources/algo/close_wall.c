/*
** EPITECH PROJECT, 2018
** need for steak
** File description:
** check_if_we are not too close from a wall
*/

#include <stdlib.h>
#include <stdio.h>
#include "ai.h"

void put_direction_close_wall(float dist, car_t *info, bool neg)
{
	float warn = dist;
	float dir = warn;

	dir = 0.05;
	if (neg)
		dir *= -1;
	info->direction = dir;
}

bool is_too_close_wall(float *lidar, car_t *info)
{
	float left_value = lidar[0];
	float right_value = lidar[31];

	if (left_value > 3 * right_value) {
		put_direction_close_wall(right_value, info, false);
		return (true);
	} else if (right_value > 3 * left_value) {
		put_direction_close_wall(left_value, info, true);
		return (true);
	}
	info->direction = 0;
	return (false);
}
