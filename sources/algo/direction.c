/*
** EPITECH PROJECT, 2018
** need for steak
** File description:
** direction of the car
*/

#include "ai.h"
#include <stdlib.h>
#include <stdio.h>

float calc_medium(int val1, int val2, int val3, int val4)
{
	float result = 0;

	dprintf(2, "val1 : %i, val2 : %i, val3 : %i val4 : %i", val1, val2, val3, val4);
	result = (val1 + val2 + val3 + val4) / 4;
	dprintf(2, "medium : %.2f\n", result);
	return (result);
}

float direction_car(int *lidar)
{
	float medium_l = 0;
	float medium_r = 0;
	float result = 0;
	float average = 0;

	if (lidar == NULL) {
		return (0);
	}
	medium_l = calc_medium(lidar[0], lidar[1], lidar[2], lidar[3]);
	medium_r = calc_medium(lidar[28], lidar[29], lidar[30], lidar[31]);
	dprintf(2, "medium_l : %.2f medium_r : %.2f \n", medium_l, medium_r);
	average = medium_l - medium_r;
	if (average > 250) {
		if (medium_l != 0)
			result = (1 - (medium_r / medium_l));
	} else if (average < -250) {
		if (medium_r != 0)
			result = (1 - (medium_l / medium_r));
		result *= -1;
	}
	return (result);
}
