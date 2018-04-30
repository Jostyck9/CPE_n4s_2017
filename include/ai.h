/*
** EPITECH PROJECT, 2018
** need for steak
** File description:
** include for the need for steak
*/

#ifndef _N4S_H_
#define _N4S_H_

#include "cmd_n4s.h"

#include <stdbool.h>
#include <string.h>

#define END_STR "1:OK:No errors so far:Track Cleared"

void my_putchar_error(char a);
void my_putstr_error(char *str);
void my_putstr(char *str);
char *send_command_value(char *cmd, float value);
char *send_command(char *cmd);
float accelerate_car(int *lidar);
int *get_lidar(char *buffer);
int stop_car(char *buffer);
char *destroy_buffer(char *buffer);
int check_if_ko(char *buffer);

#endif //_N4S_H_
