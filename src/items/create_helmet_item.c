/*
** EPITECH PROJECT, 2024
** create_helmet_items
** File description:
** create all helmets
*/
#include "../../include/myrpg.h"

item_t *create_helmet_item(char *path, char *name, int strength, char *description)
{
    item_t *item = malloc(sizeof(item_t));
    static int id = 8;

    item->name = my_strdup(name);
    item->description = my_strdup(description);
    item->type = HELMET;
    item->strength = strength;
    item->texture = sfTexture_createFromFile(path, NULL);
    item->item_id = id;
    id += 1;
    return item;
}

void create_helmet_items(item_t **items, int *index)
{
    items[*index] = create_helmet_item(
        "./assets/inventory/helmet/leather_helmet.png",
        "Casque en cuir", 10, "Casque en cuir classique.\nDEF: 10");
    items[*index + 1] = create_helmet_item(
        "./assets/inventory/helmet/iron_helmet.png",
        "Casque en fer", 20, "Casque en fer résistant.\nDEF: 20");
    items[*index + 2] = create_helmet_item(
        "./assets/inventory/helmet/steel_helmet.png",
        "Casque en acier", 40, "Casque en acier très solide.\nDEF: 40");
    items[*index + 3] = create_helmet_item(
        "./assets/inventory/helmet/dragon_helmet.png",
        "Casque du dragon", 60, 
        "Casque fabriqué en écaille de dragon.\nDEF: 60");
    *index += 4;
    return;
}
