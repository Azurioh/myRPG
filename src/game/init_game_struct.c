/*
** EPITECH PROJECT, 2024
** init_game_struct.c
** File description:
** Function to malloc the struct about game info
*/

#include "../../include/myrpg.h"
#include "../../include/generation.h"
#include <SFML/Graphics/View.h>

static sfVideoMode *get_window_size_list(void)
{
    sfVideoMode *window_size = malloc(sizeof(sfVideoMode) * 3);

    window_size[0] = (sfVideoMode){ 1280, 720, 32 };
    window_size[1] = (sfVideoMode){ 1920, 1080, 32 };
    window_size[2] = (sfVideoMode){ 2560, 1440, 32 };
    return window_size;
}

static unsigned int *get_framerate_list(void)
{
    unsigned int *framerate_list = malloc(sizeof(int) * 8);

    framerate_list[0] = 30;
    framerate_list[1] = 60;
    framerate_list[2] = 90;
    framerate_list[3] = 120;
    framerate_list[4] = 144;
    framerate_list[5] = 165;
    framerate_list[6] = 240;
    framerate_list[7] = 360;
    return framerate_list;
}

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

game_t *init_game_struct(void)
{
    game_t *game_info = malloc(sizeof(game_t));

    if (!game_info)
        return NULL;
    game_info->actual_window_size = 1;
    game_info->actual_framerate = 1;
    game_info->sound_volume = 50;
    game_info->music_volume = 50;
    game_info->sound_muted = 0;
    game_info->music_muted = 0;
    game_info->framerate_list = get_framerate_list();
    game_info->scaling = (sfVector2f){1, 1};
    game_info->window_size_list = get_window_size_list();
    game_info->map = init_map();
    game_info->undermap = init_undermap();
    game_info->map_view = init_view(game_info);
    game_info->player = create_player(game_info);
    init_window(game_info);
    return game_info;
}
