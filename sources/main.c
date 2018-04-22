/*
** EPITECH PROJECT, 2018
** main
** File description:
** main function
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void my_putchar(char a)
{
	write(1, &a, 1);
}

void my_putchar_error(char a)
{
	write(2, &a, 1);
}

void my_putstr_error(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		my_putchar_error(str[i]);
}

void my_putstr(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
}

//====================================================

int check_if_ko(char *buffer)
{
	int i = 0;

	if (buffer == NULL)
		return (84);
	for (; buffer[i] != ':' && buffer[i] != '\0'; i++);
	if (buffer[i] == '\0') {
		free(buffer);
		return (84);
	}
	if (buffer[i + 1] == 'K') {
		free(buffer);
		return (84);
	}
	return (0);
}

char *recup_std_input(char *buffer)
{
	size_t size = 0;

	if (getline(&buffer, &size, stdin) != -1) {
		my_putstr_error(buffer);
		return (buffer);
	}
	free(buffer);
	return (NULL);
}

char *send_command(char *buffer, char *cmd)
{
	if (cmd == NULL) {
		free(buffer);
		return (NULL);
	}
	my_putstr(cmd);
	buffer = recup_std_input(buffer);
	return (buffer);
}

char *send_command_value(char *buffer, char *cmd, int value)
{
	if (cmd == NULL) {
		free(buffer);
		return (NULL);
	}
	my_printf(cmd, value);
	buffer = recup_std_input(buffer);
	return (buffer);
}

int transform_lidar_in_speed(char *buffer)
{
	int i = 0;
	int nbr_value = 0;
	int j = 0;
	int result = 0;
	int speed = 0;

	for (; nbr_value < 19; i++) {
		if (buffer[i] == ':')
			nbr_value++;
	}
	for (j = i; buffer[j] != '.' ; j++);
	buffer[j] = '\0';
	my_putchar_error('\n');
	my_putstr_error(&buffer[i]);
	my_putchar_error('\n');
	result = my_getnbr(&buffer[i]);
	result /= 10;
	if (result < 90)
		speed = 0;
	else if (result > 200)
		speed = 999;
	else
		speed = result;
	return (speed);
}

int transform_lidar_in_rotation(char *buffer)
{
	int i = 0;
	int nbr_value = 0;
	int j = 0;
	int result1 = 0;
	int result2 = 0;
	char *cmd = NULL;

	for (; nbr_value < 3; i++) {
		if (buffer[i] == ':')
			nbr_value++;
	}
	for (j = i; buffer[j] != '.' ; j++);
	buffer[j] = '\0';
	result1 = my_getnbr(&buffer[i]);
	for (; nbr_value < 34; i++) {
		if (buffer[i] == ':')
			nbr_value++;
	}
	for (j = i; buffer[j] != '.' ; j++);
	buffer[j] = '\0';
	result2 = my_getnbr(&buffer[i]);
	cmd = malloc(sizeof(*cmd) * (snprintf(NULL, 0, "\nresult1 : %i && result2 : %i\n", result1, result2) + 1));
	sprintf(cmd, "\nresult1 : %i && result2 : %i\n", result1, result2);
	my_putstr_error(cmd);
	free(cmd);
	if (result1 < result2) {
		cmd = malloc(sizeof(*cmd) * (snprintf(NULL, 0, "WHEELS_DIR:-0.%i\n", 1) + 1));
		sprintf(cmd, "WHEELS_DIR:-0.%i\n", 3);
		my_putstr_error(cmd);
		buffer = send_command(buffer, cmd);
	} else {
		cmd = malloc(sizeof(*cmd) * (snprintf(NULL, 0, "WHEELS_DIR:0.%i\n", 1) + 1));
		sprintf(cmd, "WHEELS_DIR:0.%i\n", 3);
		my_putstr_error(cmd);
		buffer = send_command(buffer, cmd);
	}
	free(cmd);
	return (0);
}

int stop_car(char *buffer, int speed)
{
	speed = 1;
	while (speed != 0) {
		buffer = send_command(buffer, "GET_INFO_LIDAR\n");
		if (buffer == NULL || check_if_ko(buffer) == 84)
			return (84);
//		speed = transform_lidar_in_speed(buffer);
		transform_lidar_in_rotation(buffer);
		free(buffer);
//		buffer = send_command_value(buffer, "CAR_FORWARD:0.%i\n", speed);
//		if (buffer == NULL || check_if_ko(buffer) == 84)
//			return (84);
//		free(buffer);
	}
	return (0);
}

int main(void)
{
	char *buffer = NULL;
	int speed = 3;

	buffer = send_command(buffer, "START_SIMULATION\n");
	if (buffer == NULL || check_if_ko(buffer) == 84)
		return (84);
	free(buffer);
	buffer = send_command_value(buffer, "CAR_FORWARD:0.%i\n", speed);
	if (buffer == NULL || check_if_ko(buffer) == 84)
		return (84);
	free(buffer);
	if (stop_car(buffer, speed) == 84)
		return (84);
	buffer = send_command(buffer, "STOP_SIMULATION\n");
	if (buffer == NULL || check_if_ko(buffer) == 84)
		return (84);
	free(buffer);
	return (0);
}
