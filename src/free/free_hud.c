/*
** EPITECH PROJECT, 2024
** free_myrpg
** File description:
** Free the myrpg struct
*/

#include "../../include/myrpg.h"

void free_hud(hud_t *hud)
{
    if (hud == NULL) {
        return;
    }
    sfText_destroy(hud->act_text);
    sfText_destroy(hud->action);
    free_image(hud->exp);
    sfFont_destroy(hud->font);
    free_image(hud->inventory);
    free_image(hud->life);
    sfText_destroy(hud->name);
    free_image(hud->profile);
    free_image(hud->skill);
    sfText_destroy(hud->skill_text);
    return;
}
