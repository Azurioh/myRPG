/*
** EPITECH PROJECT, 2024
** load_main_menu.c
** File description:
** Function to load the main menu in the myrpg struct
*/

#include "../../../../include/myrpg.h"

static void load_main_menu_background(myrpg_t *myrpg)
{
    sfSprite *background = generate_sprite_with_file(
        "assets/main_menu_background.png", SCALING);

    if (myrpg->background) {
        sfSprite_destroy(myrpg->background);
    }
    sfSprite_setScale(background, (sfVector2f){0.5 * SCALING, 0.5 * SCALING});
    myrpg->background = background;
    return;
}

void load_main_menu_elements(void *args)
{
    myrpg_t *myrpg = args;

    load_main_menu_background(myrpg);
    load_main_menu_buttons(myrpg);
}
