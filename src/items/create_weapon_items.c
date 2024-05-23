/*
** EPITECH PROJECT, 2024
** create_weapon_items
** File description:
** create all the items to do damage
*/
#include "../../include/myrpg.h"

item_t *create_weapon_item(char *path, char *name, int strength,
    char *description)
{
    item_t *item = malloc(sizeof(item_t));
    static int id = 4;

    item->name = my_strdup(name);
    item->description = my_strdup(description);
    item->type = WEAPON;
    item->strength = strength;
    item->texture = sfTexture_createFromFile(path, NULL);
    item->item_id = id;
    id += 1;
    return item;
}

void create_weapon_items(item_t **items, int *index)
{
    items[*index] = create_weapon_item(
        "./assets/inventory/weapon/basic_axe.png",
        "Hache ordinaire", 10, "ATK: 10");
    items[*index + 1] = create_weapon_item(
        "./assets/inventory/weapon/steel_axe.png",
        "Hache du Papa", 20, "ATK: 20");
    items[*index + 2] = create_weapon_item(
        "./assets/inventory/weapon/fire_axe.png",
        "Hache de Feu", 40, "ATK: 40");
    items[*index + 3] = create_weapon_item(
        "./assets/inventory/weapon/guardian_axe.png",
        "Hache du Dragon", 80, "ATK: 80");
    items[*index + 4] = create_weapon_item(
        "./assets/inventory/weapon/diamond_axe.png",
        "Hache en diamant", 10000, "ATK: 10000");
}
