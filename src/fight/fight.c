/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Fight program for the game
*/

#include "../../include/myrpg.h"
#include "../../include/fight.h"
#include "../../include/generation.h"
#include "SFML/Window/Event.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <unistd.h>

static void setup_attacks(myrpg_t *myrpg, fight_t *fight_infos,
    game_t *game_info)
{
    sfVector2f play_pos = sfSprite_getPosition(game_info->player);

    (void) play_pos;
    (void) myrpg;
    fight_infos->buttons = setup_attack_buttons(myrpg);
    fight_infos->buttons[4] = NULL;
}

static int get_damage(myrpg_t *myrpg)
{
    int dmg = myrpg->player->attack + myrpg->player->axe_attack;

    return dmg;
}

static fight_t *check_str_infos(char *str, fight_t *fight, myrpg_t *myrpg)
{
    if (str[0] == 'a') {
        fight->enemy_hp -= (get_damage(myrpg) * check_damage_axe_lvl(myrpg))
        * fight->angryness;
    }
    if (str[0] == 'b') {
        fight->enemy_hp -= (get_damage(myrpg) * check_damage_launch_lvl(myrpg))
        * fight->angryness;
    }
    if (str[0] == 'c') {
        fight->toskra_hp += 20.00 * check_health_lvl(myrpg);
    }
    if (str[0] == 'd') {
        fight->angryness += 1;
    }
    return fight;
}

fight_t *manage_attack_button_event(button_t **buttons, myrpg_t *myrpg,
    fight_t *fight)
{
    if (!buttons || (EVENTS->event.type != sfEvtMouseButtonPressed
        && EVENTS->event.type != sfEvtMouseMoved)) {
        return fight;
    }
    for (int i = 0; buttons[i]; i++) {
        if (EVENTS->event.type == sfEvtMouseButtonPressed &&
            buttons[i]->is_clicked(buttons[i], SETTINGS->window) == sfTrue) {
            fight = check_str_infos(buttons[i]->button_name, fight, myrpg);
            fight->turn = ENEMY;
            return fight;
        }
        if (EVENTS->event.type == sfEvtMouseMoved) {
            buttons[i]->is_hover(buttons[i], SETTINGS->window);
        }
        animate_attack_button(buttons[i]);
    }
    return fight;
}

fight_t *display_attack(sfRenderWindow *window, myrpg_t *myrpg)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(window, myrpg->fight_infos->buttons[i]
        ->image_sprite, NULL);
    }
    if (myrpg->fight_infos->turn != TOSKRA) {
        myrpg->fight_infos = enemy_attack(myrpg->fight_infos, myrpg);
        myrpg->player->life = myrpg->fight_infos->toskra_hp;
    }
    return myrpg->fight_infos;
}

void check_fight(myrpg_t *myrpg, fight_t *fight_infos, game_t *game_info)
{
    int id = myrpg->fight_infos->enemy_id;

    (void) myrpg;
    if (fight_infos->in_fight != 1) {
        fight_infos->in_fight = 1;
        fight_infos->toskra_hp = myrpg->player->life;
        fight_infos->enemy_hp = myrpg->mobs[id]->life;
        fight_infos->loaded = 0;
        fight_infos->pos = sfSprite_getPosition(game_info->player);
    }
}

static void make_fight(myrpg_t *myrpg)
{
    myrpg->fight_infos->loaded = 1;
    myrpg->fight_infos->in_fight = 1;
    myrpg->fight_infos->angryness = 1;
    myrpg->fight_infos->enemy_infos = init_enemy(myrpg);
    myrpg->fight_infos->turn = TOSKRA;
    sfRenderWindow_clear(WINDOW, sfBlack);
    sfSprite_setTexture(myrpg->game_info->map,
        sfTexture_createFromFile(FIGHT_MAP, NULL), sfFalse);
    sfSprite_setScale(myrpg->game_info->map, (sfVector2f){0.7, 0.7});
    sfSprite_setPosition(myrpg->game_info->player, (sfVector2f){10, 10});
    sfView_setCenter(myrpg->game_info->map_view,
        (sfVector2f){960 * 0.65, 540 * 0.65});
    tp_all(myrpg, myrpg->fight_infos->enemy_id, 0);
    setup_attacks(myrpg, myrpg->fight_infos, myrpg->game_info);
}

static void unmake_fight(myrpg_t *myrpg)
{
    int id = myrpg->fight_infos->enemy_id;
    int loot_val = get_loot(myrpg, myrpg->mobs[id]);

    srand(time(NULL));
    if (myrpg->fight_infos->toskra_hp > 0)
        update_player_experience(myrpg->player, myrpg->mobs[id]->xp_loot);
    if (rand() % 25 == 3)
        add_item_in_inv(myrpg->player->inventory, loot_val);
    add_item_in_inv(myrpg->player->inventory, loot_val);
    sfRenderWindow_clear(WINDOW, sfBlack);
    myrpg->mobs[id]->can_collide = 0;
    put_all_back(myrpg, id);
    sfRenderWindow_display(WINDOW);
    myrpg->player->life = myrpg->fight_infos->toskra_hp;
}

void fight(myrpg_t *myrpg)
{
    check_fight(myrpg, myrpg->fight_infos, myrpg->game_info);
    if (myrpg->fight_infos->in_fight == 1) {
        if (myrpg->fight_infos->loaded == 0)
            make_fight(myrpg);
        myrpg->fight_infos = display_attack(WINDOW, myrpg);
        if (myrpg->fight_infos->toskra_hp <= 0 ||
            myrpg->fight_infos->enemy_hp <= 0) {
            unmake_fight(myrpg);
            myrpg->fight_infos->in_fight = 0;
            myrpg->fight_infos->loaded = 0;
            fight_quests(myrpg);
        }
    }
}
