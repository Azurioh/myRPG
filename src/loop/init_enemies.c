/*
** EPITECH PROJECT, 2024
** init_enemies
** File description:
** init all the enemies on the map
*/
#include "../../include/myrpg.h"

void init_left_right_corner_mobs(mobs_t **mobs)
{
    mobs[0] = init_lvl_one(mobs, 0, (sfVector2f){4500, 4500});
    return;
}

mobs_t **init_mobs(void)
{
    mobs_t **mobs = malloc(sizeof(mobs_t *) * 40);

    init_left_right_corner_mobs(mobs);
    mobs[1] = NULL;
    return mobs;
}
