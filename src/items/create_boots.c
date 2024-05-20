/*
** EPITECH PROJECT, 2024
** create_boots_items
** File description:
** create all bootss
*/
#include "../../include/myrpg.h"

item_t *create_boots_item(char *path, char *name, int strength,
    char *description)
{
    item_t *item = malloc(sizeof(item_t));
    static int id = 20;

    item->name = my_strdup(name);
    item->description = my_strdup(description);
    item->type = BOOTS;
    item->strength = strength;
    item->texture = sfTexture_createFromFile(path, NULL);
    item->item_id = id;
    id += 1;
    return item;
}

void create_boots_items(item_t **items, int *index)
{
    items[*index] = create_boots_item(
        "./assets/inventory/boots/leather_boots.png",
        "Bottes en cuir", 10, "Bottes en cuir classique.\nDEF: 10");
    items[*index + 1] = create_boots_item(
        "./assets/inventory/boots/iron_boots.png",
        "Bottes en fer", 20, "Bottes en fer résistant.\nDEF: 20");
    items[*index + 2] = create_boots_item(
        "./assets/inventory/boots/steel_boots.png",
        "Bottes en acier", 40, "Bottes en acier très solide.\nDEF: 40");
    items[*index + 3] = create_boots_item(
        "./assets/inventory/boots/dragon_boots.png",
        "Bottes du dragon", 60,
        "Bottes fabriqué en écaille de dragon.\nDEF: 60");
    *index += 4;
    return;
}
