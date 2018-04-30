/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** speed
*/

#include "ai.h"

float accelerate_car(int *lidar)
{
	int vald = lidar[15];
	int valg = lidar[16];
	int average = (vald + valg) / 2;
	float speed;

	if (average <= LIMIT_WALL)
		speed = -1;
	else
		speed = (float)average / 3100.0;
	return (speed);
}
