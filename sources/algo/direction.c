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

float adapt_dir_to_speed(float dir, float speed)
{
	float result = 0;

	result = dir * (1 - speed) * COEF_ROTATE;
	if (result > 1)
		result = 1;
	return (result);
}

float direction_car(float *lidar, float speed)
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
	average = medium_l - medium_r;
	if (average > 0) {
		if (medium_l != 0)
			result = ((medium_r / medium_l));
		result = adapt_dir_to_speed(result, speed);
	} else if (average < 0) {
		if (medium_r != 0)
			result = ((medium_l / medium_r));
		result = adapt_dir_to_speed(result, speed);
		result *= -1;
	}
	dprintf(2, "\t\tdirection : %f\n", result);
	return (result);
}
