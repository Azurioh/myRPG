/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** moving the hud objects
*/

#include "../../include/myrpg.h"
#include "../../include/move.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>

void move_hud(hud_t *hud, int x_move, int y_move)
{
    sfVector2f offset = {x_move, y_move};

    sfSprite_move(hud->exp->sprite, offset);
    sfSprite_move(hud->life->sprite, offset);
    sfSprite_move(hud->skill->sprite, offset);
    sfSprite_move(hud->profile->sprite, offset);
    sfSprite_move(hud->inventory->sprite, offset);
    sfText_move(hud->name, offset);
    sfText_move(hud->action, offset);
    sfText_move(hud->act_text, offset);
    sfText_move(hud->skill_text, offset);
}
