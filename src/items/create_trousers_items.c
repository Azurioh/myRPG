/*
** EPITECH PROJECT, 2024
** create_trousers_items
** File description:
** create all trouserss
*/
#include "../../include/myrpg.h"

item_t *create_trousers_item(char *path, char *name, int strength,
    char *description)
{
    item_t *item = malloc(sizeof(item_t));
    static int id = 16;

    item->name = my_strdup(name);
    item->description = my_strdup(description);
    item->type = TROUSERS;
    item->strength = strength;
    item->texture = sfTexture_createFromFile(path, NULL);
    item->item_id = id;
    id += 1;
    return item;
}

void create_trousers_items(item_t **items, int *index)
{
    items[*index] = create_trousers_item(
        "./assets/inventory/trousers/leather_trousers.png",
        "Pantalon en cuir", 10, "Pantalon en cuir classique.\nDEF: 10");
    items[*index + 1] = create_trousers_item(
        "./assets/inventory/trousers/iron_trousers.png",
        "Pantalon en fer", 20, "Pantalon en fer résistant.\nDEF: 20");
    items[*index + 2] = create_trousers_item(
        "./assets/inventory/trousers/steel_trousers.png",
        "Pantalon en acier", 40, "Pantalon en acier très solide.\nDEF: 40");
    items[*index + 3] = create_trousers_item(
        "./assets/inventory/trousers/dragon_trousers.png",
        "Pantalon du dragon", 60,
        "Pantalon fabriqué en écaille de dragon.\nDEF: 60");
    *index += 4;
    return;
}
