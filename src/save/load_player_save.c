/*
** EPITECH PROJECT, 2024
** load_player_save
** File description:
** Function to load the player
*/

#include "../../include/myrpg.h"

static void move_actual_player(myrpg_t *myrpg, sfVector2f pos_wanted)
{
    sfVector2f mov_vector = {
        pos_wanted.x - PLAYER->pos.x, pos_wanted.y - PLAYER->pos.y };

    sfView_move(GAME_INFO->map_view, mov_vector);
    sfSprite_move(GAME_INFO->player, mov_vector);
    move_hud(myrpg->hud, mov_vector);
    move_inventory(PLAYER->inventory, mov_vector);
    move_menu(GAME_INFO->game_menu, mov_vector);
}

static void load_skills(myrpg_t *myrpg, char **options)
{
    for (int i = 0; i < 3; i++) {
        PLAYER->skills[i]->level = atoi(options[6 + i]);
        if (PLAYER->skills[i]->level != 0)
            PLAYER->skills[i]->unlocked = 1;
        if (PLAYER->skills[i]->level == PLAYER->skills[i]->max_level)
            PLAYER->skills[i]->is_max_level = 1;
    }
}

void load_player_save(myrpg_t *myrpg, char **options)
{
    player_t *player = PLAYER;
    sfVector2f new_pos = { atof(options[4]), atof(options[5]) };

    if (!PLAYER) {
        player = init_player();
    } else
        move_actual_player(myrpg, new_pos);
    player->life = atoi(options[0]);
    player->experience = atoi(options[1]);
    player->level = atoi(options[2]);
    player->max_xp = 50 + player->level * 30;
    player->max_hp = 100 + (10 * (player->level - 1));
    player->attack = 5 * player->level;
    player->armor = 5 + (2 * (player->level - 1));
    player->nb_skills_to_upgrade = atoi(options[3]);
    player->pos = new_pos;
    player->skills = init_player_skills();
    player->sprinting = false;
    PLAYER = player;
    load_skills(myrpg, options);
}
