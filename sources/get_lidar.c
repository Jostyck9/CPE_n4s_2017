/*
** EPITECH PROJECT, 2018
** get_lidar
** File description:
** n4s
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int red_lidar(char *buffer, int *i, char *str)
{
	int result;
	int j = 0;

	for (; buffer[i[0]] && buffer[i[0]] != ':' && j != 6; \
i[0]++, j++)
		str[j] = buffer[i[0]];
	str[j] = '\0';
	result = atoi(str);
	if (result == 0)
		result = -1;
	return (result);
}

int *get_lidar(char *buffer)
{
	int i = 0;
	int k = 0;
	int *res = malloc(sizeof(int) * 33);
	char *str = malloc(sizeof(char) * 7);

	if (res == NULL || str == NULL)
		return (NULL);
	for (; buffer[i] != ':'; i++);
	for (; buffer[i] < '0' || buffer[i] > '9'; i++);
	for (; buffer[i] != '\0'; i++) {
		if (k != 0 && (buffer[i] == 'N' || res[k - 1] == -1)) {
			res[k - 1] = -1;
			break;
		}
		res[k] = red_lidar(buffer, &i, str);
		k++;
	}
	free(str);
	return (res);
}
