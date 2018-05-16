/*
** EPITECH PROJECT, 2018
** destroy_buffer.c
** File description:
** destroy_buffer function
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ai.h"

char *destroy_buffer(char *buffer)
{
	if (buffer == NULL) {
		return (NULL);
	}
	free(buffer);
	return (NULL);
}
