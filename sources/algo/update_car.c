/*
** EPITECH PROJECT, 2018
** need for steak
** File description:
** update_car
*/

#include <stdlib.h>
#include <stdio.h>
#include "ai.h"

bool update_speed(car_t info, bool *end)
{
	static float last_speed = 0;
	char *buffer = NULL;

	if (info.speed != last_speed) {
		buffer = send_command_value(SPEED_CAR, info.speed);
		last_speed = info.speed;
		if (buffer == NULL || check_if_ko(buffer) == true) {
			destroy_buffer(buffer);
			return (false);
		}
		if (end[0] != true)
			end[0] = check_end(buffer);
		destroy_buffer(buffer);
	}
	return (true);
}

bool update_direction(car_t info, bool *end)
{
	static float last_dir = 0;
	char *buffer = NULL;

	if (info.direction != last_dir) {
		buffer = send_command_value(TURN_CAR, info.direction);
		last_dir = info.direction;
		if (buffer == NULL || check_if_ko(buffer) == true) {
			destroy_buffer(buffer);
			return (false);
		}
		end[0] = check_end(buffer);
		destroy_buffer(buffer);
	}
	return (true);
}

bool update_car(car_t info, bool *end)
{
	if (update_speed(info, end) == false)
		return (false);
	if (end[0] == true)
		return (true);
	if (update_direction(info, end) == false)
		return (false);
	return (true);
}
