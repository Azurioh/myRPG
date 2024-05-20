/*
** EPITECH PROJECT, 2024
** display.c
** File description:
** Display function for settings menu
*/

#include "../../../include/myrpg.h"

static void update_text_placement(sfText **texts)
{
    sfFloatRect rect;

    for (int i = 4; i < 8; i++) {
        rect = sfText_getGlobalBounds(texts[i]);
        sfText_setOrigin(texts[i],
            (sfVector2f){(rect.width / 2) / 1.2, (rect.height / 2) / 1.2});
    }
}

static void update_settings_text(sfText **texts, settings_t *settings)
{
    char *resolution = my_nbr_to_str(
        settings->window_size_list[settings->actual_window_size].width);

    sfText_setString(texts[4], my_nbr_to_str(
        settings->framerate_list[settings->actual_framerate]));
    resolution = my_strcat(resolution, strdup("x"));
    resolution = my_strcat(resolution, my_nbr_to_str(
        settings->window_size_list[settings->actual_window_size].height));
    sfText_setString(texts[5], resolution);
    sfText_setString(texts[6], my_nbr_to_str(settings->music_volume));
    sfText_setString(texts[7], my_nbr_to_str(settings->sound_volume));
    update_text_placement(texts);
}

static void display_settings_menu(void *args)
{
    myrpg_t *myrpg = args;
    settings_visual_t *settings_visual = myrpg->settings->visual_elements;

    sfRenderWindow_drawSprite(SETTINGS->window,
        settings_visual->background, NULL);
    for (int i = 0; settings_visual->buttons[i]; i++) {
        sfRenderWindow_drawSprite(SETTINGS->window,
            settings_visual->buttons[i]->image_sprite, NULL);
    }
    for (int i = 0; settings_visual->texts[i]; i++) {
        sfRenderWindow_drawText(SETTINGS->window,
            settings_visual->texts[i], NULL);
    }
    update_settings_text(settings_visual->texts, SETTINGS);
    return;
}

void display_settings(void *args)
{
    myrpg_t *myrpg = args;

    EVENTS->previous_display_function(myrpg);
    display_settings_menu(myrpg);
}
