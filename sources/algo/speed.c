/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** speed
*/

float accelerate_car(int *lidar)
{
	int vald = lidar[15];
	int valg = lidar[16];
	int average = (vald + valg) / 2;
	int speed;
	
	if (average >= 914)
		speed = -1;
	else
		speed = (float)average / 3100.0;
	return (speed);
}
