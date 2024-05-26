/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** File to animate the attack of the mobs and players
*/

#include "../../include/myrpg.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>

static void disp_all(myrpg_t *myrpg, int pos)
{
    sfRenderWindow_drawSprite(WINDOW, myrpg->game_info->map, NULL);
    sfRenderWindow_drawSprite(WINDOW, GAME_INFO->player, NULL);
    sfRenderWindow_drawSprite(WINDOW, myrpg->mobs[pos]->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, myrpg->hud->profile->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, myrpg->hud->exp->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, myrpg->hud->life->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW,
        myrpg->fight_infos->enemy_infos->enemy_bottle, NULL);
    sfRenderWindow_drawSprite(WINDOW,
        myrpg->fight_infos->enemy_infos->enemy_life, NULL);
    sfRenderWindow_drawText(WINDOW,
        myrpg->fight_infos->enemy_infos->string, NULL);
    sfRenderWindow_drawText(WINDOW, myrpg->hud->name, NULL);
}

void animate_play(myrpg_t *myrpg, int pos)
{
    for (int i = 0; i < 15; i ++) {
        sfRenderWindow_clear(WINDOW, sfBlack);
        sfSprite_move(GAME_INFO->player, (sfVector2f){30, 0});
        disp_all(myrpg, pos);
        sfRenderWindow_display(WINDOW);
    }
    for (int i = 0; i < 15; i ++) {
        sfRenderWindow_clear(WINDOW, sfBlack);
        sfSprite_move(GAME_INFO->player, (sfVector2f){-30, 0});
        disp_all(myrpg, pos);
        sfRenderWindow_display(WINDOW);
    }
}

void animate_mob(myrpg_t *myrpg, int pos)
{
    for (int i = 0; i < 15; i ++) {
        sfRenderWindow_clear(WINDOW, sfBlack);
        sfSprite_move(myrpg->mobs[pos]->sprite, (sfVector2f){-30, 0});
        disp_all(myrpg, pos);
        sfRenderWindow_display(WINDOW);
    }
    for (int i = 0; i < 15; i ++) {
        sfRenderWindow_clear(WINDOW, sfBlack);
        sfSprite_move(myrpg->mobs[pos]->sprite, (sfVector2f){30, 0});
        disp_all(myrpg, pos);
        sfRenderWindow_display(WINDOW);
    }
}

void animate_attack(myrpg_t *myrpg, int player, int mob_pos)
{
    (void) mob_pos;
    if (player == 1) {
        animate_play(myrpg, mob_pos);
    } else {
        animate_mob(myrpg, mob_pos);
    }
}
