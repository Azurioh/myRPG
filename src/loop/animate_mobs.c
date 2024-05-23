/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Animate the mobs movement
*/

#include "../../include/myrpg.h"
#include <math.h>

void check_left_right(sfVector2f dep)
{
    if (dep.x < 0) {
        puts("left\n");
    } else {
        puts("right\n");
    }
}

void check_up_down(sfVector2f dep)
{
    if (dep.y < 0) {
        puts("up\n");
    } else {
        puts("down\n");
    }
}

void check_where_move(sfVector2f dep)
{
    sfVector2f abs_dep;

    abs_dep.x = fabs(dep.x);
    abs_dep.y = fabs(dep.y);
    if (abs_dep.x > abs_dep.y)
        check_left_right(dep);
    if (abs_dep.y < abs_dep.x)
        check_up_down(dep);
}
