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

float adapt_dir_to_dist(float big, float minus, float dist)
{
	float result = 0;

	result = (minus / big) * COEF_ROTATE;
	result = result * (1 - (dist / (LIMIT_WALL)));
	if (result > 1)
		result = 1;
	if (result < 0.1)
		result = 0.1;
	return (result);
}

float direction_car(float *lidar, float forward)
{
	float medium_l = 0;
	float medium_r = 0;
	float result = 0;

	if (lidar == NULL)
		return (0);
	medium_l = calc_medium(lidar[0], lidar[1]);
	medium_r = calc_medium(lidar[30], lidar[31]);
	if (medium_l > medium_r) {
		result = adapt_dir_to_dist(medium_l, medium_r, forward);
	} else if (medium_r > medium_l) {
		result = adapt_dir_to_dist(medium_r, medium_l, forward);
		result *= -1;
	}
	return (result);
}
