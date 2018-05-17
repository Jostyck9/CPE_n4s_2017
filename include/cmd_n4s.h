/*
** EPITECH PROJECT, 2018
** need for steak
** File description:
** include for the need for steak
*/

#ifndef _CMD_N4S_H_
#define _CMD_N4S_H_

#define GO_SPEED_MAX (1)
#define COEF_ROTATE (1.3)
#define LIMIT_WALL_DRIFT (300)
#define LIMIT_WALL (1000)
#define SPEED_DRIFT (0.8)
#define END_STR "Track Cleared"

#define START_N4S ("START_SIMULATION\n")
#define STOP_N4S ("STOP_SIMULATION\n")
#define SPEED_CAR ("CAR_FORWARD:%f\n")
#define BACK_CAR ("CAR_BACKWARDS:%f\n")
#define TURN_CAR ("WHEELS_DIR:%f\n")
#define LIDAR_CAR ("GET_INFO_LIDAR\n")
#define GET_SPEED ("GET_CURRENT_SPEED\n")
#define GET_WHEELS ("GET_CURRENT_WHEELS\n")
#define CYCLE_WAIT ("CYCLE_WAIT:%i\n")
#define SPEED_MAX ("GET_CAR_SPEED_MAX\n")
#define SPEED_MIN ("GET_CAR_SPEED_MIN\n")
#define SIMTIME ("GET_INFO_SIMTIME\n")

#endif //_CMD_N4S_H_
