/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** free all the mobs structs
*/

#include "../../include/mobs.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>

void free_int_array(int **array)
{
    for (int i = 0; array[i]; i++) {
        free(array[i]);
    }
    free(array);
}

void free_mobs(mobs_t **mobs)
{
    if (!mobs)
        return;
    for (int i = 0; mobs[i]; i++) {
    sfClock_destroy(mobs[i]->clock);
    sfRectangleShape_destroy(mobs[i]->hitbox);
    sfSprite_destroy(mobs[i]->sprite);
    sfCircleShape_destroy(mobs[i]->detection);
    sfClock_destroy(mobs[i]->clock_move);
    free_int_array(mobs[i]->item_loot);
    free(mobs[i]);
    }
}
