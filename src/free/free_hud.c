/*
** EPITECH PROJECT, 2024
** free_myrpg
** File description:
** Free the myrpg struct
*/

#include "../../include/myrpg.h"

void free_hud(hud_t *hud)
{
    if (!hud) {
        return;
    }
    sfFont_destroy(hud->font);
    free_image(hud->inventory);
    free_image(hud->profile);
    free_image(hud->life);
    free_image(hud->exp);
    free_image(hud->skill);
    sfSprite_destroy(hud->quest_bg);
    sfText_destroy(hud->quest_name);
    sfText_destroy(hud->quest_desc);
    sfText_destroy(hud->skill_text);
    sfText_destroy(hud->action);
    sfText_destroy(hud->name);
    sfText_destroy(hud->act_text);
    free(hud);
    return;
}
