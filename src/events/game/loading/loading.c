/*
** EPITECH PROJECT, 2024
** loading.c
** File description:
** Function used to load the elements for the game
*/

#include "../../../../include/myrpg.h"

static void init_ingame_music(myrpg_t *myrpg)
{
    sfMusic *music = sfMusic_createFromFile("assets/musics/ingame.ogg");

    myrpg->music_started = true;
    sfMusic_destroy(myrpg->music);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, SETTINGS->music_volume);
    myrpg->music = music;
    sfMusic_play(myrpg->music);
}

void load_game_elements(void *args)
{
    myrpg_t *myrpg = args;
    sfVector2f center = sfView_getCenter(GAME_INFO->map_view);
    sfVector2f size = sfView_getSize(GAME_INFO->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    myrpg->hud = init_hud(myrpg->player->name, myrpg->game_info);
    myrpg->can_interact = 0;
    myrpg->is_inventory = 0;
    if (myrpg->music_started == false) {
        init_ingame_music(myrpg);
    }
    if (SETTINGS->show_settings_menu == 1) {
        update_settings_scaling(SETTINGS);
        update_settings_position(SETTINGS, resize);
    }
}
