/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** File to make the enemies move
*/

#include "../../include/myrpg.h"
#include <math.h>

sfVector2f get_vector(sfVector2f start, sfVector2f end, int speed)
{
    sfVector2f move_vector;
    sfVector2f move_second;
    float norm;

    move_vector.x = end.x - start.x;
    move_vector.y = end.y - start.y;
    norm = sqrt(pow(move_vector.x, 2) + pow(move_vector.y, 2));
    move_second.x = ((speed / norm) * move_vector.x) / 10;
    move_second.y = ((speed / norm) * move_vector.y) / 10;
    return move_second;
}
