/*
** EPITECH PROJECT, 2024
** get_time
** File description:
** get the time
*/
#include "../../include/myrpg.h"

float get_time(sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    return seconds;
}
