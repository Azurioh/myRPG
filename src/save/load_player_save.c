/*
** EPITECH PROJECT, 2024
** load_player_save
** File description:
** Function to load the player
*/

#include "../../include/myrpg.h"

void load_player_save(myrpg_t *myrpg, char **options)
{
    player_t *player = init_player();

    player->experience = atoi(options[0]);
    player->level = atoi(options[1]);
    player->nb_skills_to_upgrade = atoi(options[2]);
    player->pos = (sfVector2f){atoi(options[3]), atoi(options[4])};
    PLAYER = player;
}
