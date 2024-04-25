/*
** EPITECH PROJECT, 2024
** init_hud
** File description:
** load all the sprite for the hud
*/

#include "../../include/myrpg.h"

void change_percentage(sfSprite *sprite, int percentage)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 104 * percentage / 100;
    rect.height = 12;
    sfSprite_setTextureRect(sprite, rect);
}

char *name_and_level(myrpg_t *myrpg)
{
    char *player = strdup("");

    strcat(player, myrpg->player->name);
    strcat(player, " Lvl.");
    strcat(player, nbr_to_str(myrpg->player->level));
    return player;
}

char *upgrade_text(myrpg_t *myrpg)
{
    char *upgrade = strdup("Nombre d'ameliorations disponibles : ");

    strcat(upgrade, nbr_to_str(myrpg->player->nb_skills_to_upgrade));
    return upgrade;
}

void display_profile(myrpg_t *myrpg)
{
    sfRenderWindow *window = myrpg->game_info->window;

    sfRenderWindow_drawSprite(window, myrpg->hud->profile->sprite, NULL);
    sfRenderWindow_drawSprite(window, myrpg->hud->life->sprite, NULL);
    sfRenderWindow_drawSprite(window, myrpg->hud->exp->sprite, NULL);
    sfRenderWindow_drawText(window, myrpg->hud->name, NULL);
}

void display_hud(myrpg_t *myrpg)
{
    sfRenderWindow *window = myrpg->game_info->window;

    myrpg->player->experience = 50;
    myrpg->player->life = 8;
    myrpg->player->level = 6;
    myrpg->can_interact = 1;
    myrpg->player->nb_skills_to_upgrade = 12;
    change_percentage(myrpg->hud->life->sprite, myrpg->player->life);
    change_percentage(myrpg->hud->exp->sprite, myrpg->player->experience);
    sfText_setString(myrpg->hud->name, name_and_level(myrpg));
    display_profile(myrpg);
    sfRenderWindow_drawSprite(window, myrpg->hud->inventory->sprite, NULL);
    sfRenderWindow_drawText(window, myrpg->hud->act_text, NULL);
    if (myrpg->player->nb_skills_to_upgrade > 0) {
        sfText_setString(myrpg->hud->skill_text, upgrade_text(myrpg));
        sfRenderWindow_drawSprite(window, myrpg->hud->skill->sprite, NULL);
        sfRenderWindow_drawText(window, myrpg->hud->skill_text, NULL);
    }
    if (myrpg->can_interact == 1)
        sfRenderWindow_drawText(window, myrpg->hud->action, NULL);
}
