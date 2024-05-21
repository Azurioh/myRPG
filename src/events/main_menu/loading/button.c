/*
** EPITECH PROJECT, 2024
** button.c
** File description:
** Functions to load main menu buttons
*/

#include "../../../../include/myrpg.h"

static void close_game(button_t *button, void *args)
{
    myrpg_t *myrpg = args;

    (void) button;
    myrpg->game_open = 0;
}

static void show_settings_menu(button_t *button, void *args)
{
    (void) button;
    load_settings(args);
}

static void launch_game(button_t *button, void *args)
{
    myrpg_t *myrpg = args;

    (void) button;
    EVENTS->unload_function(myrpg);
    sfMusic_stop(myrpg->music);
    myrpg->music_started = false;
    myrpg->player = init_player();
    myrpg->game_info = init_game_struct(myrpg);
    load_game(args);
    EVENTS->load_function(myrpg);
}

static button_t **generate_main_menu_buttons(myrpg_t *myrpg)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    char *resume_button = my_strdup("assets/resume-cancel-button.png");

    if (myrpg->save_loaded == true)
        resume_button = my_strdup("assets/resume-button.png");
    buttons[0] = init_button("Nouvelle partie", (sfVector2f){960 * SCALING,
        700 * SCALING}, "assets/new-game-button.png", &launch_game);
    buttons[1] = init_button("Reprendre la partie", (sfVector2f){960 * SCALING,
        800 * SCALING}, resume_button, &launch_game);
    buttons[2] = init_button("Paramètres", (sfVector2f){960 * SCALING,
        900 * SCALING}, "assets/settings-button.png", &show_settings_menu);
    buttons[3] = init_button("Quitter", (sfVector2f){960 * SCALING,
        1000 * SCALING}, "assets/quit-button.png", &close_game);
    buttons[4] = NULL;
    if (myrpg->save_loaded == false)
        buttons[1]->clickable = sfFalse;
    for (int i = 0; i < 4; i++)
        sfSprite_setScale(buttons[i]->image_sprite,
            (sfVector2f){SCALING, SCALING});
    return buttons;
}

static sfMusic *load_music(void)
{
    char *music_path = my_strdup("assets/musics/diggy_instru.ogg");
    sfMusic *music;
    int random;

    srand(time(NULL));
    random = rand() % 100;
    if (random <= 25) {
        free(music_path);
        music_path = my_strdup("assets/musics/diggy_instru_secret.ogg");
    }
    music = sfMusic_createFromFile(music_path);
    return music;
}

void load_main_menu_buttons(void *args)
{
    myrpg_t *myrpg = args;
    button_t **buttons;

    if (myrpg->buttons) {
        for (int i = 0; myrpg->buttons[i]; i++) {
            free_button(myrpg->buttons[i]);
        }
        free(myrpg->buttons);
    }
    buttons = generate_main_menu_buttons(myrpg);
    for (int i = 0; buttons[i]; i++) {
        buttons[i]->initial_scaling = SCALING;
    }
    myrpg->buttons = buttons;
    if (!myrpg->music) {
        myrpg->music = load_music();
        myrpg->music_started = false;
    }
}
