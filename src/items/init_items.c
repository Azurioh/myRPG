/*
** EPITECH PROJECT, 2024
** init_items
** File description:
** init all the items
*/
#include "../../include/myrpg.h"
#include <string.h>

item_t **init_items(void)
{
    item_t **items = malloc(sizeof(item_t *) * 26);
    int index = 0;

    create_heal_items(items, &index);
    create_weapon_items(items, &index);
    index += 5;
    create_helmet_items(items, &index);
    create_chestplate_items(items, &index);
    create_trousers_items(items, &index);
    create_boots_items(items, &index);
    items[25] = NULL;
    return items;
}
