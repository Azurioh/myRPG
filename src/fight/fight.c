/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Fight program for the game
*/

#include "../../include/myrpg.h"
#include "../../include/fight.h"
#include "../../include/generation.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Sleep.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>
#include <unistd.h>

static void setup_attacks(myrpg_t *myrpg, fight_t *fight_infos,
    game_t *game_info)
{
    sfVector2f play_pos = sfSprite_getPosition(game_info->player);

    (void) play_pos;
    (void) myrpg;
    fight_infos->buttons = setup_attack_buttons(myrpg);
}

static fight_t *check_str_infos(char *str, fight_t *fight)
{
    if (str[0] == 'a') {
        fight->enemy_hp -= 20 * fight->angryness;
        puts(str);
        printf("%d\n", atoi(str));
    }
    if (str[0] == 'b') {
        fight->enemy_hp -= 20 * fight->angryness;
        puts(str);
    }
    if (str[0] == 'c') {
        fight->toskra_hp += 20;
        puts(str);
    }
    if (str[0] == 'd') {
        fight->angryness += 2;
        puts(str);
    }
    return fight;
}

fight_t *manage_attack_button_event(button_attack_t **buttons, myrpg_t *myrpg,
    fight_t *fight)
{
    char *str;

    if (!buttons) {
        return fight;
    }
    for (int i = 0; buttons[i]; i++) {
        if (EVENTS->event.type == sfEvtMouseButtonPressed
            && buttons[i]->is_clicked(buttons[i], SETTINGS->window) == sfTrue
            && buttons[i]->action) {
            str = buttons[i]->action(fight);
            fight = check_str_infos(str, fight);
            return fight;
        }
        if (EVENTS->event.type == sfEvtMouseMoved) {
            buttons[i]->is_hover(buttons[i], SETTINGS->window);
        }
        // animate_button(buttons[i]);
    }
    return fight;
}

fight_t *display_attack(sfRenderWindow *window, myrpg_t *myrpg)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(window, myrpg->fight_infos->buttons[i]
        ->image_sprite, NULL);
    }
    myrpg->fight_infos = manage_attack_button_event(myrpg->fight_infos->buttons
    , myrpg, myrpg->fight_infos);
    return myrpg->fight_infos;
}

void check_fight(myrpg_t *myrpg, fight_t *fight_infos, game_t *game_info)
{
    (void) myrpg;
    if (sfKeyboard_isKeyPressed(sfKeyA) && fight_infos->in_fight != 1) {
        fight_infos->in_fight = 1;
        fight_infos->toskra_hp = 100;
        fight_infos->enemy_hp = 100;
        fight_infos->loaded = 0;
        fight_infos->pos = sfSprite_getPosition(game_info->player);
    }
}

static void make_fight(myrpg_t *myrpg)
{
    myrpg->fight_infos->loaded = 1;
    myrpg->fight_infos->in_fight = 1;
    myrpg->fight_infos->angryness = 1;
    sfRenderWindow_clear(WINDOW, sfBlack);
    sfSprite_setTexture(myrpg->game_info->map,
        sfTexture_createFromFile(FIGHT_MAP, NULL), sfFalse);
    sfSprite_setPosition(myrpg->game_info->player, (sfVector2f){10, 10});
    sfView_setCenter(myrpg->game_info->map_view,
        (sfVector2f){960 * 0.65, 540 * 0.65});
    setup_attacks(myrpg, myrpg->fight_infos, myrpg->game_info);
}

static void unmake_fight(myrpg_t *myrpg)
{
    sfRenderWindow_clear(WINDOW, sfBlack);
    sfSprite_setTexture(myrpg->game_info->map,
        sfTexture_createFromFile(MAP_PATH, NULL), sfFalse);
    sfSprite_setPosition(myrpg->game_info->player, myrpg->fight_infos->pos);
    sfView_setCenter(myrpg->game_info->map_view, myrpg->fight_infos->pos);
    sfRenderWindow_display(WINDOW);
    printf("Toskra hp = %d\n", myrpg->fight_infos->toskra_hp);
    myrpg->fight_infos->in_fight = 0;
    myrpg->fight_infos->loaded = 0;
}

void fight(myrpg_t *myrpg)
{
    check_fight(myrpg, myrpg->fight_infos, myrpg->game_info);
    if (myrpg->fight_infos->in_fight == 1) {
        if (myrpg->fight_infos->loaded == 0)
            make_fight(myrpg);
        myrpg->fight_infos = display_attack(WINDOW, myrpg);
        if (myrpg->fight_infos->toskra_hp <= 0 ||
            myrpg->fight_infos->enemy_hp <= 0)
            unmake_fight(myrpg);
    }
}
