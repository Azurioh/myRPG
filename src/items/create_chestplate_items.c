/*
** EPITECH PROJECT, 2024
** create_chestplate_items
** File description:
** create all chestplates
*/
#include "../../include/myrpg.h"

item_t *create_chestplate_item(char *path, char *name, int strength, char *description)
{
    item_t *item = malloc(sizeof(item_t));
    static int id = 12;

    item->name = my_strdup(name);
    item->description = my_strdup(description);
    item->type = CHESTPLATE;
    item->strength = strength;
    item->texture = sfTexture_createFromFile(path, NULL);
    item->item_id = id;
    id += 1;
    return item;
}

void create_chestplate_items(item_t **items, int *index)
{
    items[*index] = create_chestplate_item(
        "./assets/inventory/chestplate/leather_chestplate.png",
        "Plastron en cuir", 10, "Plastron en cuir classique.\nDEF: 10");
    items[*index + 1] = create_chestplate_item(
        "./assets/inventory/chestplate/iron_chestplate.png",
        "Plastron en fer", 20, "Plastron en fer résistant.\nDEF: 20");
    items[*index + 2] = create_chestplate_item(
        "./assets/inventory/chestplate/steel_chestplate.png",
        "Plastron en acier", 40, "Plastron en acier très solide.\nDEF: 40");
    items[*index + 3] = create_chestplate_item(
        "./assets/inventory/chestplate/dragon_chestplate.png",
        "Plastron du dragon", 60, 
        "Plastron fabriqué en écaille de dragon.\nDEF: 60");
    *index += 4;
    return;
}
