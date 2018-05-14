/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** speed
*/

#include <stdlib.h>
#include "ai.h"

float accelerate_car(int *lidar)
{
	int vald = 0;
	int valg = 0;
	int average = (vald + valg) / 2;
	float speed;

	if (lidar == NULL)
		return (0.5);
	vald = lidar[15];
	valg = lidar[16];
	if (average <= LIMIT_WALL)
		speed = 1;
	else
		speed = (float)average / 3100.0;
	free(lidar);
	dprintf(2, "%f\n", speed);
	return (speed);
}
