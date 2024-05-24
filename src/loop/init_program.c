/*
** EPITECH PROJECT, 2024
** init_program.c
** File description:
** Function to init the program and start the game
*/

#include "../../include/myrpg.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

static void init_tmp_game_info(myrpg_t *myrpg)
{
    myrpg->game_info = malloc(sizeof(game_t));
    myrpg->game_info->map_view = NULL;
    myrpg->game_info->keybinds = init_keybinds();
}

static myrpg_t *init_myrpg(void)
{
    myrpg_t *myrpg = malloc(sizeof(myrpg_t));

    myrpg->game_open = 1;
    myrpg->transition_state = 3;
    myrpg->settings = init_settings();
    myrpg->events = malloc(sizeof(event_t));
    myrpg->can_interact = 0;
    myrpg->is_inventory = 0;
    myrpg->background = NULL;
    myrpg->buttons = NULL;
    myrpg->player = NULL;
    myrpg->hud = NULL;
    myrpg->music = NULL;
    myrpg->music_started = false;
    myrpg->quests = create_quest_list();
    myrpg->portal = portal_map();
    myrpg->items = NULL;
    myrpg->npc = NULL;
    init_tmp_game_info(myrpg);
    return myrpg;
}

mobs_t *create_sprite(mobs_t *mobs)
{
    sfIntRect rect;
    sfTexture *mob = sfTexture_createFromFile
    ("assets/enemies/sprite_enemibg.png", NULL);

    rect.top = 0;
    rect.left = 0;
    rect.width = 48;
    rect.height = 48;
    mobs->clock_move = sfClock_create();
    mobs->sprite = sfSprite_create();
    mobs->rect = rect;
    sfSprite_setTexture(mobs->sprite, mob, sfFalse);
    sfSprite_setPosition(mobs->sprite, mobs->pos);
    sfSprite_setTextureRect(mobs->sprite, mobs->rect);
    sfSprite_scale(mobs->sprite, (sfVector2f){2, 2});
    return mobs;
}

int **init_loot(void)
{
    int **loot_table = malloc(sizeof(int *) * 4);

    loot_table[0] = malloc(sizeof(int) * 6);
    loot_table[1] = malloc(sizeof(int) * 5);
    loot_table[2] = malloc(sizeof(int) * 5);
    loot_table[3] = malloc(sizeof(int) * 6);
    loot_table = init_all_lootables(loot_table);
    return loot_table;
}

static sfRectangleShape *init_hitbox(game_t *game_info)
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

    myrpg->fight_infos = malloc(sizeof(fight_t));
    myrpg->mobs = init_mobs();
    myrpg->fight_infos->in_fight = 0;
    myrpg->hitbox = init_hitbox(myrpg->game_info);
    myrpg->portal = portal_map();
    load_game_save(myrpg);
    load_main_menu(myrpg);
    if (!myrpg) {
        return 84;
    } else {
        return loop(myrpg);
    }
}
