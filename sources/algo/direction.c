/*
** EPITECH PROJECT, 2018
** need for steak
** File description:
** direction of the car
*/

#include <stdlib.h>
#include <stdio.h>
#include "ai.h"

float calc_medium(float val1, float val2)
{
	float result = 0;

	result = (val1 + val2) / 2;
	return (result);
}

float adapt_dir_to_speed(float dir, float dist)
{
	float result = 0;

//	dprintf(2, "\t\tBefore adapting %f\n", dir);
	result = dir * (1 - (dist / LIMIT_WALL));
	if (result > 1)
		result = 1;
	return (result);
}

float direction_car(float *lidar, float speed, float forward)
{
	float medium_l = 0;
	float medium_r = 0;
	float result = 0;
	float average = 0;

	if (lidar == NULL) {
		return (0);
	}
	medium_l = calc_medium(lidar[0], lidar[1]);
	medium_r = calc_medium(lidar[30], lidar[31]);
//	dprintf(2, "\t\tmedium_l %f && medium_r %f\n", medium_l, medium_r);
	average = medium_l - medium_r;
	if (average > 0) {
		if (medium_l != 0)
			result = ((medium_r / medium_l));
		result = adapt_dir_to_speed(result, lidar[15]);
	} else if (average < 0) {
		if (medium_r != 0)
			result = ((medium_l / medium_r));
		result = adapt_dir_to_speed(result, lidar[15]);
		result *= -1;
	}
//	dprintf(2, "\t\tdirection : %f\n", result);
	return (result);
}
