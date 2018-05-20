/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** speed
*/

#include <stdio.h>
#include <stdlib.h>
#include "ai.h"

float accelerate_car(float dist)
{
	float speed = 0;

	if (dist < 200) {
		dprintf(2, "Dead end\n");
		return (0);
	}
	if (dist < LIMIT_WALL_DRIFT)
		dist = LIMIT_WALL_DRIFT;
	speed = SPEED_DRIFT * (dist / LIMIT_WALL);
	return (speed);
}
