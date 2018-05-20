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

struct car_s {
	float speed;
	float direction;
};
typedef struct car_s car_t;

void my_putchar_error(char a);
void my_putstr_error(char *str);
void my_putstr(char *str);
char *send_command_value(char *cmd, float value);
char *send_command(char *cmd);
float accelerate_car(float dist);
float *get_lidar(char *buffer);
bool stop_car(void);
char *destroy_buffer(char *buffer);
bool check_if_ko(char *buffer);
float direction_car(float *lidar, float forward);
bool update_car(car_t info, bool *end);
bool check_end(char *str);
bool is_too_close_wall(float *lidar, car_t *info);
char *destroy_buffer(char *buffer);
char *send_command_value_int(char *cmd, int value);

#endif //_N4S_H_
