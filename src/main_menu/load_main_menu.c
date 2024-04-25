/*
** EPITECH PROJECT, 2024
** load_main_menu.c
** File description:
** Function to load the main menu in the myrpg struct
*/

#include "../../include/myrpg.h"

static void load_main_menu_background(myrpg_t *myrpg)
{
    sfSprite *background = generate_sprite_with_file(
        "assets/main_menu_background.jpg", SCALING);

    if (myrpg->background) {
        sfSprite_destroy(myrpg->background);
    }
    sfSprite_setScale(background, (sfVector2f){0.5 * SCALING, 0.5 * SCALING});
    myrpg->background = background;
    return;
}

static button_t **generate_main_menu_buttons(myrpg_t *myrpg)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);

    if (!buttons) {
        return NULL;
    }
    buttons[0] = init_button("Nouvelle partie", (sfVector2f){360 * SCALING,
        900 * SCALING}, "assets/new-game-button.png", NULL);
    buttons[1] = init_button("Reprendre la partie", (sfVector2f){760 * SCALING,
        900 * SCALING}, "assets/resume-game-button.png", NULL);
    buttons[2] = init_button("Paramètres", (sfVector2f){1160 * SCALING,
        900 * SCALING}, "assets/settings-button.png", &show_settings_menu);
    buttons[3] = init_button("Quitter", (sfVector2f){1560 * SCALING,
        900 * SCALING}, "assets/quit-button.png", NULL);
    buttons[4] = NULL;
    for (int i = 0; i < 4; i++) {
        sfSprite_setScale(buttons[i]->image_sprite,
            (sfVector2f){SCALING, SCALING});
    }
    return buttons;
}

static void load_main_menu_buttons(myrpg_t *myrpg)
{
    button_t **buttons;

    if (myrpg->buttons) {
        for (int i = 0; myrpg->buttons[i]; i++) {
            free_button(myrpg->buttons[i]);
        }
        free(myrpg->buttons);
    }
    buttons = generate_main_menu_buttons(myrpg);
    myrpg->buttons = buttons;
}

void load_main_menu(myrpg_t *myrpg)
{
    load_main_menu_background(myrpg);
    load_main_menu_buttons(myrpg);
}
