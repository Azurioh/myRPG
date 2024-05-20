/*
** EPITECH PROJECT, 2024
** create_heal_items
** File description:
** create all the items to heal
*/
#include "../../include/myrpg.h"

item_t *create_heal_item(char *path, char *name, int strength, char *description)
{
    item_t *item = malloc(sizeof(item_t));
    static int id = 0;

    item->name = my_strdup(name);
    item->description = my_strdup(description);
    item->type = HEAL;
    item->strength = strength;
    item->texture = sfTexture_createFromFile(path, NULL);
    item->item_id = id;
    id += 1;
    return item;
}

void create_heal_items(item_t **items, int *index)
{
    items[*index] = create_heal_item(
        "./assets/inventory/heal/gourde_du_brave.png",
        "Gourde du Brave", 100, "Regénère 100 HP.");
    items[*index + 1] = create_heal_item(
        "./assets/inventory/heal/grosse_popo.png",
        "Grosse Popo", 100, "Regénère 50 HP.");
    items[*index + 2] = create_heal_item(
        "./assets/inventory/heal/petite_popo.png",
        "Petite Popo", 100, "Regénère 25 HP.");
    *index += 3;
    return;
}
