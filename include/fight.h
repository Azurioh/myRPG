/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** fight .h file
*/

#ifndef FIGHT_H
    #define FIGHT_H
    #include "game.h"
    #include "button.h"
    #include <SFML/System/Vector2.h>

enum turn {
    TOSKRA = 0,
    ENEMY,
};

typedef struct button_attack_s {
    char *button_name;
    sfVector2f position;
    sfRectangleShape *hitbox;
    sfSprite *image_sprite;
    float initial_scaling;
    sfBool actually_hover;
    sfBool actually_clicked;
    sfBool (*is_clicked)(struct button_attack_s *, sfRenderWindow *);
    sfBool (*is_hover)(struct button_attack_s *, sfRenderWindow *);
    sfClock *animation_clock;
    char *(*action)(void *args);
} button_attack_t;

typedef struct enemy_s {
    int rage_turns;
    int heal_turns;
    int did_attack;
    int rage;
    int attack_turns;
} enemy_t;

typedef struct fight_s {
    button_attack_t **buttons;
    enemy_t *enemy_infos;
    int in_fight;
    enum turn turn;
    sfVector2f pos;
    int enemy_hp;
    int toskra_hp;
    int loaded;
    int angryness;
} fight_t;

fight_t *init_fight(void);
char *axe_throw(void *fight);
char *another_attack(void *fight);
char *drink_hydromel(void *fight);
char *angry_guy(void *fight);
int check_attack_collision(button_attack_t *button, sfRenderWindow *window);
fight_t *enemy_attack(fight_t *fight);
enemy_t *init_enemy(void);

#endif
