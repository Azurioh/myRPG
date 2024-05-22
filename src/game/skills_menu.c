/*
** EPITECH PROJECT, 2024
** skills_menu.c
** File description:
** Function to init the skills menu
*/

#include "../../include/myrpg.h"

static void manage_skills_button(button_t *button, void *args)
{
    myrpg_t *myrpg = args;

    if (button->clickable == sfFalse) {
        return;
    }
    if (strcmp(button->button_name, "quit") == 0) {
        free(GAME_INFO->game_menu);
        GAME_INFO->game_menu = init_game_menu(GAME_INFO, SETTINGS);
        return;
    }
    update_skill(PLAYER, atoi(button->button_name) - 1);
}

static sfSprite **load_skills_background(sfVector2f resize)
{
    sfSprite **sprite = malloc(sizeof(sfSprite *) * 2);
    sfFloatRect size;

    sprite[0] = generate_sprite_with_file("assets/settings-background.png", 1);
    sprite[1] = generate_sprite_with_file("assets/settings-background.png", 1);
    for (int i = 0; i < 2; i++) {
        size = sfSprite_getGlobalBounds(sprite[0]);
        sfSprite_setOrigin(sprite[0],
            (sfVector2f){ size.width / 2, size.height / 2 });
        sfSprite_setPosition(sprite[0],
            (sfVector2f){ 620 + resize.x, 350 + resize.y });
        sfSprite_setScale(sprite[0], (sfVector2f){1.0 / 1.7, 1.0 / 1.7});
    }
    return sprite;
}

static void load_disabled_skills_buttons(game_menu_t *game_menu,
    sfVector2f resize)
{
    game_menu->buttons[3] = init_button("disabled",
        (sfVector2f){ 620 + resize.x, 190 + resize.y },
        "assets/resume-button.png", &manage_skills_button);
    game_menu->buttons[4] = init_button("disabled",
        (sfVector2f){ 620 + resize.x, 270 + resize.y },
        "assets/save_button.png", &manage_skills_button);
    game_menu->buttons[5] = init_button("disabled",
        (sfVector2f){ 620 + resize.x, 350 + resize.y },
        "assets/load_button.png", &manage_skills_button);
}

static void load_skills_buttons(game_menu_t *game_menu, sfVector2f resize)
{
    game_menu->buttons = malloc(sizeof(button_t *) * 8);
    game_menu->buttons[0] = init_button("1",
        (sfVector2f){ 620 + resize.x, 190 + resize.y },
        "assets/more.png", &manage_skills_button);
    game_menu->buttons[1] = init_button("2",
        (sfVector2f){ 620 + resize.x, 270 + resize.y },
        "assets/more.png", &manage_skills_button);
    game_menu->buttons[2] = init_button("3",
        (sfVector2f){ 620 + resize.x, 350 + resize.y },
        "assets/more.png", &manage_skills_button);
    load_disabled_skills_buttons(game_menu, resize);
    game_menu->buttons[6] = init_button("quit",
        (sfVector2f){ 620 + resize.x, 510 + resize.y },
        "assets/quit-button.png", &manage_skills_button);
    for (int i = 0; i < 7; i++) {
        game_menu->buttons[i]->initial_scaling = 1;
    }
    game_menu->buttons[7] = NULL;
}

static sfText **load_skills_texts(sfVector2f resize)
{
    sfText **texts = malloc(sizeof(sfText *) * 4);

    texts[0] = init_text("1/4",
        (sfVector2f){ 100 + resize.x, 100 + resize.y }, 30, sfWhite);
    texts[1] = init_text("1/4",
        (sfVector2f){ 100 + resize.x, 200 + resize.y }, 30, sfWhite);
    texts[2] = init_text("1/4",
        (sfVector2f){ 100 + resize.x, 300 + resize.y }, 30, sfWhite);
    texts[3] = NULL;
    return texts;
}

void init_skills_menu(myrpg_t *myrpg)
{
    game_menu_t *game_menu = GAME_INFO->game_menu;
    sfVector2f resize = get_resize(myrpg);

    free(game_menu);
    game_menu = malloc(sizeof(game_menu_t));
    game_menu->background = load_skills_background(resize);
    load_skills_buttons(game_menu, resize);
    game_menu->texts = load_skills_texts(resize);
    GAME_INFO->game_menu = game_menu;
}
