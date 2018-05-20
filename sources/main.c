/*
** EPITECH PROJECT, 2018
** main
** File description:
** main function
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ai.h"

int main(void)
{
	char *buffer = NULL;

	buffer = send_command(START_N4S);
	dprintf(2, "Start Simulation\n");
	if (buffer == NULL || check_if_ko(buffer) == true)
		return (84);
	buffer = destroy_buffer(buffer);
	if (stop_car() == false)
		return (84);
	buffer = send_command(STOP_N4S);
	dprintf(2, "Stop Simulation\n");
	if (buffer == NULL || check_if_ko(buffer) == true)
		return (84);
	buffer = destroy_buffer(buffer);
	return (0);
}
