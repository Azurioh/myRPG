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
        myrpg->game_open = 0;
}

static button_t **init_game_menu_buttons(sfVector2f resize)
{
    button_t **buttons = malloc(sizeof(button_t *) * 6);

    buttons[0] = init_button("resume",
        (sfVector2f){ 620 + resize.x, 190 + resize.y },
        "assets/resume-button.png", &manage_ingame_button_action);
    buttons[1] = init_button("save",
        (sfVector2f){ 620 + resize.x, 270 + resize.y },
        "assets/save_button.png", &manage_ingame_button_action);
    buttons[2] = init_button("load",
        (sfVector2f){ 620 + resize.x, 350 + resize.y },
        "assets/load_button.png", &manage_ingame_button_action);
    buttons[3] = init_button("settings",
        (sfVector2f){ 620 + resize.x, 430 + resize.y },
        "assets/settings-button.png", &manage_ingame_button_action);
    buttons[4] = init_button("quit",
        (sfVector2f){ 620 + resize.x, 510 + resize.y },
        "assets/quit-button.png", &manage_ingame_button_action);
    buttons[5] = NULL;
    return buttons;
}

static sfSprite **load_game_background(sfVector2f resize)
{
    sfSprite **sprite = malloc(sizeof(sfSprite *) * 2);
    sfFloatRect size;

    sprite[0] = generate_sprite_with_file("assets/settings-background.png", 1);
    sprite[1] = generate_sprite_with_file("assets/settings-background.png", 1);
    size = sfSprite_getGlobalBounds(sprite[0]);
    sfSprite_setOrigin(sprite[0],
        (sfVector2f){ size.width / 2, size.height / 2 });
    sfSprite_setPosition(sprite[0],
        (sfVector2f){ 620 + resize.x, 350 + resize.y });
    sfSprite_setScale(sprite[0], (sfVector2f){1.0 / 1.7, 1.0 / 1.7});
    size = sfSprite_getGlobalBounds(sprite[1]);
    sfSprite_setOrigin(sprite[1],
        (sfVector2f){ size.width / 2, size.height / 2 });
    sfSprite_setPosition(sprite[1],
        (sfVector2f){ 200 + resize.x, 350 + resize.y });
    sfSprite_setScale(sprite[1], (sfVector2f){1.0 / 3, 1.0 / 3});
    return sprite;
}

game_menu_t *init_game_menu(game_t *game_info, settings_t *settings)
{
    game_menu_t *game_menu = malloc(sizeof(game_menu_t));
    sfVector2f center = sfView_getCenter(game_info->map_view);
    sfVector2f size = sfView_getSize(game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    (void) settings;
    game_menu->background = load_game_background(resize);
    game_menu->buttons = init_game_menu_buttons(resize);
    for (int i = 0; game_menu->buttons[i]; i++) {
        sfSprite_setScale(game_menu->buttons[i]->image_sprite,
            (sfVector2f){1 / 1.5, 1 / 1.5});
        game_menu->buttons[i]->initial_scaling = 1 / 1.5;
    }
    game_menu->texts = load_texts_elements(game_info, resize);
    return game_menu;
}
