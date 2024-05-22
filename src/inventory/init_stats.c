/*
** EPITECH PROJECT, 2024
** init_stats
** File description:
** init stats
*/
#include "../../include/myrpg.h"

sfSprite *init_stats_sprite(sfVector2f resize)
{
    sfTexture *texture =
        sfTexture_createFromFile("./assets/inventory/stats.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, (sfVector2f){resize.x + 780, resize.y + 250});
    sfSprite_setScale(sprite, (sfVector2f){2.5, 2.5});
    return sprite;
}

sfText **init_stats_text(myrpg_t *myrpg, sfVector2f resize)
{
    sfText **texts = malloc(sizeof(sfText *) * 5);
    player_t *player = myrpg->player;
    sfFont *font = sfFont_createFromFile("./assets/alagard.ttf");

    texts[0] = create_text(str_fusion("Vie : ", nbr_to_str(player->life)), 17,
        (sfVector2f){resize.x + 810, resize.y + 270}, font);
    texts[1] = create_text(str_fusion("Exp. : ",
        nbr_to_str(player->experience)), 17,
        (sfVector2f){resize.x + 810, resize.y + 300}, font);
    texts[2] = create_text(str_fusion("Armure : ",
        nbr_to_str(player->armor + player->item_armor)), 17,
        (sfVector2f){resize.x + 810, resize.y + 330}, font);
    texts[3] = create_text(str_fusion("Attaque : ",
        nbr_to_str(player->attack + player->axe_attack)), 17,
        (sfVector2f){resize.x + 810, resize.y + 360}, font);
    texts[4] = NULL;
    return texts;
}

void init_stats(myrpg_t *myrpg, inventory_t *inventory)
{
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    inventory->stats_sprite = init_stats_sprite(resize);
    inventory->player_stats = init_stats_text(myrpg, resize);
    return;
}
