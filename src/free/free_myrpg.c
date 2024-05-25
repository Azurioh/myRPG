/*
** EPITECH PROJECT, 2024
** free_myrpg
** File description:
** Free the myrpg struct
*/

#include "../../include/myrpg.h"
#include <SFML/Graphics/RectangleShape.h>

void free_myrpg(myrpg_t *myrpg)
{
    if (!myrpg) {
        return;
    }
    free_player(myrpg->player);
    free_items(myrpg->items);
    free_game(myrpg->game_info);
    free(myrpg->events);
    if (myrpg->background)
        sfSprite_destroy(myrpg->background);
    sfMusic_destroy(myrpg->music);
    free_quests(myrpg->quests);
    if (myrpg->buttons)
        free_all_buttons(myrpg->buttons);
    free_portals(myrpg->portal);
    free_settings(myrpg->settings);
    free_hud(myrpg->hud);
    free_npc(myrpg->npc);
    sfRectangleShape_destroy(myrpg->hitbox);
    free(myrpg);
}
