/*
** EPITECH PROJECT, 2024
** init.c
** File description:
** Function to init the game struct
*/

#include "../../include/myrpg.h"

static sfSprite *init_map(void)
{
    sfTexture *tmp_texture = sfTexture_createFromFile(MAP_PATH, NULL);
    sfSprite *tmp_sprite = sfSprite_create();

    sfSprite_setTexture(tmp_sprite, tmp_texture, sfFalse);
    return tmp_sprite;
}

static sfView *init_view(myrpg_t *myrpg)
{
    sfView *tmp_view = sfView_create();

    sfView_setCenter(tmp_view, myrpg->player->pos);
    sfView_setSize(tmp_view, (sfVector2f){1920, 1080});
    sfView_zoom(tmp_view, 0.65);
    return tmp_view;
}

static sfSprite *create_player(myrpg_t *myrpg)
{
    sfTexture *player = sfTexture_createFromFile(PLAYER_PATH, NULL);
    sfSprite *sprite_player = sfSprite_create();
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 32;
    rect.height = 64;
    sfSprite_setTexture(sprite_player, player, sfFalse);
    sfSprite_setPosition(sprite_player, myrpg->player->pos);
    sfSprite_setTextureRect(sprite_player, rect);
    sfSprite_setScale(sprite_player, (sfVector2f){1.5, 1.5});
    return sprite_player;
}

sfImage *init_undermap(void)
{
    sfImage *undermap = sfImage_createFromFile(UNDERMAP_PATH);

    return undermap;
}

keybinds_t *init_keybinds(void)
{
    keybinds_t *keybinds = malloc(sizeof(keybinds_t));

    if (!keybinds) {
        return NULL;
    }
    keybinds->move_up = sfKeyZ;
    keybinds->move_down = sfKeyS;
    keybinds->move_left = sfKeyQ;
    keybinds->move_right = sfKeyD;
    keybinds->open_inventory = sfKeyE;
    keybinds->interact = sfKeyF;
    keybinds->skills = sfKeyO;
    keybinds->editing_keybinds = sfFalse;
    keybinds->actions = NULL;
    keybinds->keybind_edit = NULL;
    return keybinds;
}

game_t *init_game_struct(void *args)
{
    myrpg_t *myrpg = args;
    game_t *game_info = malloc(sizeof(game_t));

    if (!game_info)
        return NULL;
    game_info->map = init_map();
    game_info->undermap = init_undermap();
    game_info->map_view = init_view(myrpg);
    game_info->player = create_player(myrpg);
    game_info->keybinds = GAME_INFO->keybinds;
    game_info->game_menu = init_game_menu(game_info, SETTINGS);
    game_info->show_menu = 0;
    game_info->clock = sfClock_create();
    game_info->transition_state = 3;
    return game_info;
}
