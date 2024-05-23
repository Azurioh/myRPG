/*
** EPITECH PROJECT, 2024
** loop.c
** File description:
** The initial loop game
*/

#include "../../include/myrpg.h"
#include <SFML/Config.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>
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
        && GAME_INFO->show_menu != 1 && myrpg->fight_infos->in_fight != 1) {
        dep = get_vector(player_pos, sfSprite_getPosition
        (myrpg->mobs[i]->sprite), -7);
        check_where_move(dep);
        sfSprite_move(myrpg->mobs[i]->sprite, dep);
        sfCircleShape_move(myrpg->mobs[i]->detection, dep);
        sfRectangleShape_move(myrpg->mobs[i]->hitbox, dep);
        return;
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
        fight(myrpg);
        sfClock_restart(myrpg->mobs[i]->clock);
    }
}

void game_loop(myrpg_t *myrpg)
{
    settings_t *settings = myrpg->settings;

    while (sfRenderWindow_pollEvent(settings->window,
        &EVENTS->event) && myrpg->transition_state == 3) {
        if (EVENTS->event.type == sfEvtClosed) {
            myrpg->game_open = 0;
            return;
        }
        EVENTS->event_function(myrpg);
    }
    sfRenderWindow_clear(settings->window, sfBlack);
    EVENTS->display_function(myrpg);
    update_quest(myrpg->quests);
    sfRenderWindow_display(settings->window);
    if (GAME_INFO->map_view)
        make_transition(myrpg);
}

int loop(myrpg_t *myrpg)
{
    EVENTS->load_function(myrpg);
    while (myrpg->game_open == 1) {
        game_loop(myrpg);
    }
    free_myrpg(myrpg);
    return 0;
}
