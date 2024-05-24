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

enum turn {
    TOSKRA = 0,
    ENEMY,
};

typedef struct enemy_s {
    sfText *string;
    int rage_turns;
    sfSprite *enemy_bottle;
    sfSprite *enemy_life;
    int heal_turns;
    int did_attack;
    int rage;
    int attack;
    int attack_turns;
} enemy_t;

typedef struct fight_s {
    button_t **buttons;
    enemy_t *enemy_infos;
    int enemy_id;
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
int check_attack_collision(button_t *button, sfRenderWindow *window);

#endif
