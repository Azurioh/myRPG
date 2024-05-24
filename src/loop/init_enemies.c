/*
** EPITECH PROJECT, 2024
** init_enemies
** File description:
** init all the enemies on the map
*/
#include "../../include/myrpg.h"

void init_top_left_corner_mobs(mobs_t **mobs)
{
    mobs[0] = init_lvl_one(mobs, 0, (sfVector2f){2760, 4120});
    mobs[1] = init_lvl_one(mobs, 1, (sfVector2f){3080, 4260});
    mobs[2] = init_lvl_one(mobs, 2, (sfVector2f){4040, 2973});
    mobs[3] = init_lvl_one(mobs, 3, (sfVector2f){4185, 3010});
    mobs[4] = init_lvl_one(mobs, 4, (sfVector2f){4500, 3320});
    mobs[5] = init_lvl_one(mobs, 5, (sfVector2f){3867, 3910});
    mobs[6] = init_lvl_one(mobs, 6, (sfVector2f){3168, 3348});
    mobs[7] = init_lvl_one(mobs, 7, (sfVector2f){4329, 3990});
    return;
}

void init_bottom_left_corner_mobs(mobs_t **mobs)
{
    mobs[8] = init_lvl_one(mobs, 8, (sfVector2f){3264, 5124});
    mobs[9] = init_lvl_one(mobs, 9, (sfVector2f){3448, 5190});
    mobs[10] = init_lvl_one(mobs, 10, (sfVector2f){4020, 4842});
    mobs[11] = init_lvl_one(mobs, 11, (sfVector2f){3456, 5922});
    mobs[12] = init_lvl_one(mobs, 12, (sfVector2f){3648, 6027});
    mobs[13] = init_lvl_one(mobs, 13, (sfVector2f){3198, 6333});
    mobs[14] = init_lvl_one(mobs, 14, (sfVector2f){2916, 6099});
    mobs[15] = init_lvl_one(mobs, 15, (sfVector2f){5121, 5790});
    mobs[16] = init_lvl_one(mobs, 16, (sfVector2f){4866, 6126});
    mobs[17] = init_lvl_one(mobs, 17, (sfVector2f){4746, 6456});
    return;
}

mobs_t **init_mobs(void)
{
    mobs_t **mobs = malloc(sizeof(mobs_t *) * 40);

    init_top_left_corner_mobs(mobs);
    init_bottom_left_corner_mobs(mobs);
    mobs[18] = NULL;
    return mobs;
}
