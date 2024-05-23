/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Animate the mobs movement
*/

#include "../../include/myrpg.h"
#include <math.h>

static void animate_mob(myrpg_t *myrpg, int top, int i)
{
    float seconds = get_time(myrpg->mobs[i]->clock);
    static int offset = 0;
    float animation_time = 0.1;

    if (seconds > animation_time) {
        myrpg->mobs[i]->rect.top = myrpg->mobs[i]->rect.height * top;
        myrpg->mobs[i]->rect.left = offset * myrpg->mobs[i]->rect.width;
        sfClock_restart(myrpg->mobs[i]->clock);
        offset += 1;
        if (offset == 4)
            offset = 0;
        sfSprite_setTextureRect(myrpg->mobs[i]->sprite, myrpg->mobs[i]->rect);
    }
}

void check_left_right(sfVector2f dep, int i, myrpg_t *myrpg)
{
    if (dep.x < 0) {
        animate_mob(myrpg, 1, i);
    } else if (dep.x > 0) {
        animate_mob(myrpg, 0, i);
    }
}

void check_up_down(sfVector2f dep, int i, myrpg_t *myrpg)
{
    if (dep.y < 0) {
        animate_mob(myrpg, 2, i);
    } else if (dep.y > 0){
        animate_mob(myrpg, 3, i);
    }
}

void check_where_move(sfVector2f dep, int i, myrpg_t *myrpg)
{
    sfVector2f abs_dep;

    (void)i;
    (void)myrpg;
    (void)abs_dep;
    abs_dep.x = fabs(dep.x);
    abs_dep.y = fabs(dep.y);
    if (abs_dep.x > abs_dep.y)
        check_left_right(dep, i, myrpg);
    if (abs_dep.y > abs_dep.x)
        check_up_down(dep, i, myrpg);
}
