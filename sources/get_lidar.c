/*
** EPITECH PROJECT, 2018
** get_lidar
** File description:
** n4s
*/

#include <stdlib.h>
#include <stdbool.h>

bool is_number(char c)
{
	if (c < '0' || c > '9')
		return (false);
	return (true);
}

int red_lidar(char *buffer, int *i, char *str)
{
	int result;
	int j = 0;

	for (; buffer[i[0]] && buffer[i[0]] != ':' && j != 6; \
i[0]++, j++)
		str[j] = buffer[i[0]];
	str[j] = '\0';
	result = atof(str);
	return (result);
}

float *get_lidar(char *buffer)
{
	int i = 0;
	int k = 0;
	float *res = malloc(sizeof(int) * 33);
	char *str = malloc(sizeof(char) * 7);

	if (res == NULL || str == NULL)
		return (NULL);
	for (; buffer[i] != ':'; i++);
	for (; buffer[i] < '0' || buffer[i] > '9'; i++);
	for (; buffer[i] != '\0'; i++) {
		if (k != 0 && (is_number(buffer[i]) == false || \
res[k - 1] == -1)) {
			res[k] = -1;
			break;
		}
		res[k] = red_lidar(buffer, &i, str);
		k++;
	}
	free(str);
	return (res);
}
