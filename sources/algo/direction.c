/*
** EPITECH PROJECT, 2018
** need for steak
** File description:
** direction of the car
*/

#include <stdlib.h>
#include <stdio.h>
#include "ai.h"

float calc_medium(float val1, float val2, float val3)
{
	float result = 0;

	result = (val1 + val2 + val3) / 4;
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
	medium_l = calc_medium(lidar[0], lidar[1], lidar[2]);
	medium_r = calc_medium(lidar[28], lidar[29], lidar[30]);
	average = medium_l - medium_r;
	if (average > 0) {
		if (medium_l != 0)
			result = ((medium_r / medium_l));
	} else if (average < 0) {
		if (medium_r != 0)
			result = ((medium_l / medium_r));
		result *= -1;
	}
	dprintf(2, "\t\tdirection : %f\n", result);
	return (result);
}
