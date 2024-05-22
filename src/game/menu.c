/*
** EPITECH PROJECT, 2024
** menu.c
** File description:
** Function to init the ingame menu
*/

#include "../../include/myrpg.h"

static void show_settings(button_t *button, void *args)
{
    myrpg_t *myrpg = args;

    (void) button;
    load_settings(myrpg);
    EVENTS->load_function(myrpg);
}

static void manage_ingame_button_action(button_t *button, void *args)
{
    myrpg_t *myrpg = args;

    button->release(button);
    button->actually_clicked = sfFalse;
    sfSprite_setScale(button->image_sprite,
        (sfVector2f){button->initial_scaling, button->initial_scaling});
    if (strcmp(button->button_name, "resume") == 0) {
        GAME_INFO->show_menu = sfFalse;
    }
    if (strcmp(button->button_name, "save") == 0)
        return save_game(myrpg);
    if (strcmp(button->button_name, "load") == 0) {
        player_save(myrpg);
        inventory_save(myrpg);
        return;
    }
    if (strcmp(button->button_name, "settings") == 0)
        show_settings(button, args);
    if (strcmp(button->button_name, "quit") == 0)
        return;
}

static button_t **init_game_menu_buttons(float scaling, sfVector2f resize)
{
    button_t **buttons = malloc(sizeof(button_t *) * 6);

    buttons[0] = init_button("resume",
        (sfVector2f){ 620 * scaling + resize.x, 190 * scaling + resize.y },
        "assets/resume-button.png", &manage_ingame_button_action);
    buttons[1] = init_button("save",
        (sfVector2f){ 620 * scaling + resize.x, 270 * scaling + resize.y },
        "assets/save_button.png", &manage_ingame_button_action);
    buttons[2] = init_button("load",
        (sfVector2f){ 620 * scaling + resize.x, 350 * scaling + resize.y },
        "assets/load_button.png", &manage_ingame_button_action);
    buttons[3] = init_button("settings",
        (sfVector2f){ 620 * scaling + resize.x, 430 * scaling + resize.y },
        "assets/settings-button.png", &manage_ingame_button_action);
    buttons[4] = init_button("quit",
        (sfVector2f){ 620 * scaling + resize.x, 510 * scaling + resize.y },
        "assets/quit-button.png", &manage_ingame_button_action);
    buttons[5] = NULL;
    return buttons;
}

static sfSprite *load_game_background(float scaling, sfVector2f resize)
{
    sfSprite *sprite = generate_sprite_with_file(
        "assets/settings-background.png", 1);
    sfFloatRect size;

    size = sfSprite_getGlobalBounds(sprite);
    sfSprite_setOrigin(sprite,
        (sfVector2f){ size.width / 2, size.height / 2 });
    sfSprite_setPosition(sprite,
        (sfVector2f){ 620 * scaling + resize.x, 350 * scaling + resize.y });
    sfSprite_setScale(sprite, (sfVector2f){scaling / 1.7, scaling / 1.7});
    return sprite;
}

game_menu_t *init_game_menu(game_t *game_info, settings_t *settings)
{
    game_menu_t *game_menu = malloc(sizeof(game_menu_t));
    sfVector2f center = sfView_getCenter(game_info->map_view);
    sfVector2f size = sfView_getSize(game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    game_menu->background = load_game_background(settings->scaling, resize);
    game_menu->buttons = init_game_menu_buttons(settings->scaling, resize);
    for (int i = 0; game_menu->buttons[i]; i++) {
        sfSprite_setScale(game_menu->buttons[i]->image_sprite,
            (sfVector2f){settings->scaling / 1.5, settings->scaling / 1.5});
        game_menu->buttons[i]->initial_scaling = settings->scaling / 1.5;
    }
    return game_menu;
}
