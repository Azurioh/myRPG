/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Check if we collide with an enemy
*/

#include "../../include/myrpg.h"
#include <SFML/Config.h>
#include <math.h>

static int check_mob_collide(sfVector2f tw, sfVector2f pl, int rad)
{
    float calcul = pow(tw.x - pl.x, 2) + pow(tw.y - pl.y, 2);

    if (calcul <= pow(rad + 20, 2)) {
        return 1;
    }
    return 0;
}

void check_if_mob_mov(myrpg_t *myrpg, int i)
{
    sfVector2f dep;
    sfVector2f mob_pos;
    sfVector2f player_pos = sfSprite_getPosition(myrpg->game_info->player);
    sfVector2f player_cent = {player_pos.x + 10, player_pos.y + 10};
    int radius;

    mob_pos = sfCircleShape_getPosition(myrpg->mobs[i]->detection);
    radius = sfCircleShape_getRadius(myrpg->mobs[i]->detection);
    if (check_mob_collide(mob_pos, player_cent, radius) == 1
        && myrpg->mobs[i]->can_collide == 1 && myrpg->is_inventory != 1
        && GAME_INFO->show_menu == 0 && myrpg->fight_infos->in_fight != 1) {
        dep = get_vector(player_pos, sfSprite_getPosition
        (myrpg->mobs[i]->sprite), -7);
        check_where_move(dep, i, myrpg);
        sfSprite_move(myrpg->mobs[i]->sprite, dep);
        sfCircleShape_move(myrpg->mobs[i]->detection, dep);
        sfRectangleShape_move(myrpg->mobs[i]->hitbox, dep);
        return;
    }
}

void check_boss(myrpg_t *myrpg, int i)
{
    if (myrpg->mobs[i]->level == 5 && myrpg->quests->quests[8]->is_validate
        != sfTrue) {
        myrpg->mobs[i]->damages = 10000000;
        myrpg->mobs[i]->life = 10000000;
    }
}

void check_coll_enemy(myrpg_t *myrpg, int i)
{
    sfFloatRect rect_enemy = sfRectangleShape_getGlobalBounds(
    myrpg->mobs[i]->hitbox);
    sfFloatRect rect_player = sfRectangleShape_getGlobalBounds(myrpg->hitbox);

    if (sfFloatRect_intersects(&rect_player, &rect_enemy, NULL) == sfTrue &&
    myrpg->mobs[i]->can_collide == 1) {
        myrpg->fight_infos->enemy_id = myrpg->mobs[i]->id;
        check_boss(myrpg, i);
        fight(myrpg);
        sfClock_restart(myrpg->mobs[i]->clock);
    }
}
