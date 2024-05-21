/*
** EPITECH PROJECT, 2024
** item
** File description:
** item
*/

#ifndef ITEM_H
    #define ITEM_H
    #include <SFML/Graphics.h>

enum item_type {
    HEAL = 0,
    HELMET,
    CHESTPLATE,
    TROUSERS,
    BOOTS,
    WEAPON
};

typedef struct item_s {
    enum item_type type;
    int item_id;
    char *name;
    sfTexture *texture;
    int strength;
    char *description;
} item_t;

item_t **init_items(void);
void create_heal_items(item_t **items, int *index);
void create_weapon_items(item_t **items, int *index);
void create_helmet_items(item_t **items, int *index);
void create_chestplate_items(item_t **items, int *index);
void create_trousers_items(item_t **items, int *index);
void create_boots_items(item_t **items, int *index);
#endif /* !ITEM_H */
