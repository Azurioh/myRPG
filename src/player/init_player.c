/*
** EPITECH PROJECT, 2024
** init_player.c
** File description:
** Function to init the player struct
*/

#include "../../include/myrpg.h"
#include "SFML/Graphics/Sprite.h"
#include "SFML/Graphics/Texture.h"
#include "SFML/System/Clock.h"

sfSprite *init_player_sprite(player_interface_t *player_interface)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/player_sprite.png",
        &player_interface->rect);

    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}

static sfIntRect init_player_rect(void)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 50;
    rect.height = 50;
    return rect;
}

static player_interface_t *init_player_interface(void)
{
    player_interface_t *player_interface = malloc(sizeof(player_interface_t));

    if (!player_interface) {
        return NULL;
    }
    player_interface->rect = init_player_rect();
    player_interface->sprite = init_player_sprite(player_interface);
    player_interface->scale = (sfVector2f){1, 1};
    player_interface->clock = sfClock_create();
    player_interface->animation_time = 0.2;
    player_interface->movement = (sfVector2f){0, 0};
    player_interface->speed = 5;
    return player_interface;
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->name = strdup("Toskra");
    player->life = 100;
    player->is_alive = 1;
    player->nb_dead = 0;
    player->experience = 0;
    player->level = 0;
    player->nb_skills_to_upgrade = 0;
    player->skills = init_player_skills();
    player->interface = init_player_interface();
    return player;
}
