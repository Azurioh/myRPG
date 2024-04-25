/*
** EPITECH PROJECT, 2024
** init_program.c
** File description:
** Function to init the program and start the game
*/

#include "../../include/myrpg.h"

static settings_t *init_settings(game_t *game_info)
{
    settings_t *settings = malloc(sizeof(settings_t));

    settings->scaling = 1;
    settings->window = game_info->window;
    settings->show_settings_menu = 0;
    settings->visual_elements = NULL;
    load_settings_menu(settings);
    return settings;
}

static myrpg_t *init_myrpg(void)
{
    myrpg_t *myrpg = malloc(sizeof(myrpg_t));

    if (!myrpg) {
        return NULL;
    }
    myrpg->player = init_player();
    myrpg->game_info = init_game_struct();
    myrpg->settings = init_settings(GAME_INFO);
    myrpg->list_of_events = init_events();
    myrpg->background = NULL;
    myrpg->buttons = NULL;
    return myrpg;
}

int start_game(void)
{
    myrpg_t *myrpg = init_myrpg();

    if (!myrpg) {
        return 84;
    } else {
        return loop(myrpg);
    }
}
