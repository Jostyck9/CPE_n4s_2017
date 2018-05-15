/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** speed
*/

#include <stdio.h>
#include <stdlib.h>
#include "ai.h"

float accelerate_car(float *lidar, float dist)
{
	float speed;

	if (lidar == NULL)
		return (0.5);
	speed = ((dist * SPEED_DRIFT) / LIMIT_WALL);
	dprintf(2, "\t\tspeed %f\n", speed);
	return (speed);
}
