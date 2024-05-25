/*
** EPITECH PROJECT, 2024
** init_enemies
** File description:
** init all the enemies on the map
*/
#include "../../include/myrpg.h"

void init_top_left_corner_mobs(mobs_t **mobs)
{
    mobs[0] = init_lvl_four(mobs, 0, (sfVector2f){2760, 4120});
    mobs[1] = init_lvl_four(mobs, 1, (sfVector2f){3080, 4260});
    mobs[2] = init_lvl_four(mobs, 2, (sfVector2f){4040, 2973});
    mobs[3] = init_lvl_four(mobs, 3, (sfVector2f){4185, 3010});
    mobs[4] = init_lvl_one(mobs, 4, (sfVector2f){4500, 3320});
    mobs[5] = init_lvl_four(mobs, 5, (sfVector2f){3867, 3910});
    mobs[6] = init_lvl_four(mobs, 6, (sfVector2f){3168, 3348});
    mobs[7] = init_lvl_one(mobs, 7, (sfVector2f){4329, 3990});
    return;
}

void init_bottom_left_corner_mobs(mobs_t **mobs)
{
    mobs[8] = init_lvl_three(mobs, 8, (sfVector2f){3264, 5124});
    mobs[9] = init_lvl_three(mobs, 9, (sfVector2f){3448, 5190});
    mobs[10] = init_lvl_three(mobs, 10, (sfVector2f){4020, 4842});
    mobs[11] = init_lvl_three(mobs, 11, (sfVector2f){3456, 5922});
    mobs[12] = init_lvl_three(mobs, 12, (sfVector2f){3648, 6027});
    mobs[13] = init_lvl_three(mobs, 13, (sfVector2f){3198, 6333});
    mobs[14] = init_lvl_three(mobs, 14, (sfVector2f){2916, 6099});
    mobs[15] = init_lvl_three(mobs, 15, (sfVector2f){5121, 5790});
    mobs[16] = init_lvl_three(mobs, 16, (sfVector2f){4866, 6126});
    mobs[17] = init_lvl_three(mobs, 17, (sfVector2f){4746, 6456});
    mobs[18] = init_lvl_three(mobs, 18, (sfVector2f){4124, 5916});
    return;
}

void init_top_right_corner_mobs(mobs_t **mobs)
{
    mobs[19] = init_lvl_one(mobs, 19, (sfVector2f){5620, 3112});
    mobs[20] = init_lvl_one(mobs, 20, (sfVector2f){5470, 3768});
    mobs[21] = init_lvl_one(mobs, 21, (sfVector2f){5058, 2878});
    mobs[22] = init_lvl_one(mobs, 22, (sfVector2f){5094, 3000});
    mobs[23] = init_lvl_one(mobs, 23, (sfVector2f){6066, 4142});
    mobs[24] = init_lvl_one(mobs, 24, (sfVector2f){6374, 4554});
    mobs[25] = init_lvl_one(mobs, 25, (sfVector2f){6216, 4510});
}

void init_bottom_right_corner_mobs(mobs_t **mobs)
{
    mobs[26] = init_lvl_two(mobs, 26, (sfVector2f){5728, 4766});
    mobs[27] = init_lvl_two(mobs, 27, (sfVector2f){5520, 6354});
    mobs[28] = init_lvl_two(mobs, 28, (sfVector2f){6044, 5596});
    mobs[29] = init_lvl_two(mobs, 29, (sfVector2f){6396, 5118});
    mobs[30] = init_lvl_two(mobs, 30, (sfVector2f){6480, 5126});
    mobs[31] = init_lvl_two(mobs, 31, (sfVector2f){5572, 5426});
}

mobs_t **init_mobs(void)
{
    mobs_t **mobs = malloc(sizeof(mobs_t *) * 33);

    init_top_left_corner_mobs(mobs);
    init_bottom_left_corner_mobs(mobs);
    init_top_right_corner_mobs(mobs);
    init_bottom_right_corner_mobs(mobs);
    mobs[32] = NULL;
    return mobs;
}
