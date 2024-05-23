/*
** EPITECH PROJECT, 2024
** display.c
** File description:
** The function to display the game elements
*/

#include "../../../include/myrpg.h"
#include "SFML/Graphics/Color.h"

static void make_move(myrpg_t *myrpg)
{
    if (sfKeyboard_isKeyPressed(GAME_INFO->keybinds->move_down))
        move_down_view(myrpg->game_info, myrpg);
    if (sfKeyboard_isKeyPressed(GAME_INFO->keybinds->move_up))
        move_up_view(myrpg->game_info, myrpg);
    if (sfKeyboard_isKeyPressed(GAME_INFO->keybinds->move_right))
        move_right_view(myrpg->game_info, myrpg);
    if (sfKeyboard_isKeyPressed(GAME_INFO->keybinds->move_left))
        move_left_view(myrpg->game_info, myrpg);
}

static void update_skills_buttons(myrpg_t *myrpg)
{
    for (int i = 0; i < 3; i++) {
        if (PLAYER->nb_skills_to_upgrade == 0
            || PLAYER->skills[i]->is_max_level == 1) {
            GAME_INFO->game_menu->buttons[i]->clickable = sfFalse;
            sfSprite_setColor(GAME_INFO->game_menu->buttons[i]->image_sprite,
                sfColor_fromRGBA(200, 200, 200, 255));
        } else {
            GAME_INFO->game_menu->buttons[i]->clickable = sfTrue;
            sfSprite_setColor(GAME_INFO->game_menu->buttons[i]->image_sprite,
                sfColor_fromRGBA(255, 255, 255, 255));
        }
    }
}

static void update_skills_elements(myrpg_t *myrpg)
{
    char *str1 = nbr_to_str(PLAYER->skills[0]->level);
    char *str2 = nbr_to_str(PLAYER->skills[1]->level);
    char *str3 = nbr_to_str(PLAYER->skills[2]->level);
    char *array[] = { str1, str2, str3, NULL };

    for (int i = 0; array[i]; i++) {
        array[i] = my_strcat(array[i], "/");
        array[i] = my_strcat(array[i],
            nbr_to_str(PLAYER->skills[i]->max_level));
    }
    for (int i = 1; i < 4; i++)
        sfText_setString(GAME_INFO->game_menu->texts[i], array[i - 1]);
    update_skills_buttons(myrpg);
}

static void display_menu(myrpg_t *myrpg)
{
    if (GAME_INFO->show_menu == 1)
        update_dynamic_texts(GAME_INFO, GAME_INFO->game_menu->texts);
    if (GAME_INFO->show_menu == 2)
        update_skills_elements(myrpg);
    sfRenderWindow_drawSprite(SETTINGS->window,
        GAME_INFO->game_menu->background[0], NULL);
    sfRenderWindow_drawSprite(SETTINGS->window,
        GAME_INFO->game_menu->background[1], NULL);
    for (int i = 0; GAME_INFO->game_menu->buttons[i]; i++) {
        sfRenderWindow_drawSprite(SETTINGS->window,
            GAME_INFO->game_menu->buttons[i]->image_sprite, NULL);
    }
    for (int i = 0; GAME_INFO->game_menu->texts[i]; i++) {
        sfRenderWindow_drawText(SETTINGS->window,
            GAME_INFO->game_menu->texts[i], NULL);
    }
}

void display_game(void *args)
{
    myrpg_t *myrpg = args;

    sfRenderWindow_setView(WINDOW, GAME_INFO->map_view);
    sfRenderWindow_drawSprite(WINDOW, GAME_INFO->map, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue)
        sfRenderWindow_drawSprite(WINDOW, GAME_INFO->undermap_sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, GAME_INFO->player, NULL);
    display_hud(myrpg);
    if (myrpg->is_inventory == 1)
        display_inventory(myrpg);
    if (GAME_INFO->show_menu >= 1)
        display_menu(myrpg);
    if (myrpg->is_inventory == 0 && GAME_INFO->show_menu == 0) {
        spawn_npc(myrpg);
        can_speak(myrpg, myrpg->npc);
        make_move(myrpg);
        move(myrpg);
    }
    sfClock_restart(PLAYER_INTERFACE->clock);
}
