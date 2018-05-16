/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** speed
*/

#include <stdio.h>
#include <stdlib.h>
#include "ai.h"

float accelerate_car(float *lidar, float dir)
{
	float speed = 0;

	if (lidar == NULL)
		return (0.5);
	if (dir < 0)
		dir *= -1;
	if (dir < 0.2)
		dir = 0.2;
	speed = SPEED_DRIFT * dir;
//	dprintf(2, "\t\tspeed %f\n", speed);
	return (speed);
}
