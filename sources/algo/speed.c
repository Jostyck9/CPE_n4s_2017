/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** speed
*/

#include <stdio.h>
#include <stdlib.h>
#include "ai.h"

float accelerate_car(float *lidar)
{
	float valr = 0;
	float vall = 0;
	float average = 0;
	float speed;

	if (lidar == NULL)
		return (0.5);
	valr = lidar[15];
	vall = lidar[16];
	average = (valr + vall) / 2;
	if (average <= LIMIT_WALL) {
		speed = average / (LIMIT_WALL * 5);
	} else
		speed = (float)average / 3100.0;
	dprintf(2, "\t\tspeed %f\n", speed);
	return (speed);
}
