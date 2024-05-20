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

static sfView *init_view(game_t *game_info)
{
    sfView *tmp_view = sfView_create();
    sfFloatRect pos_view = sfSprite_getGlobalBounds(game_info->map);
    sfVector2f center_map = {pos_view.height / 2, pos_view.width / 2};

    sfView_setCenter(tmp_view, (sfVector2f){center_map.y, center_map.x});
    sfView_setSize(tmp_view, (sfVector2f){1920, 1080});
    sfView_zoom(tmp_view, 0.65);
    return tmp_view;
}

static sfSprite *create_player(game_t *game_info)
{
    sfTexture *player = sfTexture_createFromFile(PLAYER_PATH, NULL);
    sfSprite *sprite_player = sfSprite_create();

    sfSprite_setTexture(sprite_player, player, sfFalse);
    sfSprite_setPosition(sprite_player, sfView_getCenter(game_info->map_view));
    return sprite_player;
}

sfImage *init_undermap(void)
{
    sfImage *undermap = sfImage_createFromFile(UNDERMAP_PATH);

    return undermap;
}

static keybinds_t *init_keybinds(void)
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
    return keybinds;
}

game_t *init_game_struct(settings_t *settings)
{
    game_t *game_info = malloc(sizeof(game_t));

    if (!game_info)
        return NULL;
    game_info->map = init_map();
    game_info->undermap = init_undermap();
    game_info->map_view = init_view(game_info);
    game_info->player = create_player(game_info);
    game_info->keybinds = init_keybinds();
    game_info->game_menu = init_game_menu(game_info, settings);
    game_info->show_menu = 0;
    return game_info;
}
