/*
** EPITECH PROJECT, 2024
** init_program.c
** File description:
** Function to init the program and start the game
*/

#include "../../include/myrpg.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

static myrpg_t *init_myrpg(void)
{
    myrpg_t *myrpg = malloc(sizeof(myrpg_t));

    if (!myrpg)
        return NULL;
    myrpg->game_open = 1;
    myrpg->fight_infos = malloc(sizeof(fight_t));
    myrpg->settings = init_settings();
    myrpg->events = malloc(sizeof(event_t));
    myrpg->can_interact = 0;
    myrpg->is_inventory = 0;
    myrpg->background = NULL;
    myrpg->buttons = NULL;
    myrpg->player = NULL;
    myrpg->hud = NULL;
    myrpg->game_info = malloc(sizeof(game_t));
    myrpg->music = NULL;
    myrpg->music_started = false;
    myrpg->game_info->keybinds = init_keybinds();
    load_main_menu(myrpg);
    return myrpg;
}

mobs_t **init_mobs(void)
{
    mobs_t **mobs = malloc(sizeof(mobs_t *) * 1);

    mobs[0] = malloc(sizeof(mobs_t));
    mobs[0]->life = 100;
    mobs[0]->id = 0;
    mobs[0]->can_collide = 1;
    mobs[0]->level = 1;
    mobs[0]->damages = 20;
    mobs[0]->xp_loot = 15;
    mobs[0]->item_loot = 1;
    mobs[0]->pos = (sfVector2f){4500, 4500};
    mobs[0]->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(mobs[0]->hitbox, mobs[0]->pos);
    sfRectangleShape_setSize(mobs[0]->hitbox, (sfVector2f){100, 100});
    sfRectangleShape_setFillColor(mobs[0]->hitbox, sfBlack);
    return mobs;
}

sfRectangleShape *init_hitbox(game_t *game_info)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    (void)game_info;
    sfRectangleShape_setSize(rect, (sfVector2f){20, 20});
    sfRectangleShape_setPosition(rect, (sfVector2f){20, 20});
    return rect;
}

int start_game(void)
{
    myrpg_t *myrpg = init_myrpg();

    myrpg->mobs = init_mobs();
    myrpg->fight_infos->in_fight = 0;
    myrpg->hitbox = init_hitbox(myrpg->game_info);
    if (!myrpg) {
        return 84;
    } else {
        return loop(myrpg);
    }
}
