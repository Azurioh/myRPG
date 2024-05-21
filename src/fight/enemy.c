/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Enemy algorithm to make it fight the player
*/

#include "../../include/fight.h"
#include "../../include/myrpg.h"

enemy_t *init_enemy(void)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    enemy->did_attack = 0;
    enemy->rage = 1;
    enemy->rage_turns = 2;
    enemy->heal_turns = 0;
    return enemy;
}

static fight_t *attack(fight_t *fight)
{
    printf("ATTACKED\n");
    fight->toskra_hp -= 20 * fight->enemy_infos->rage;
    fight->enemy_infos->did_attack = 1;
    return fight;
}

static fight_t *rage(fight_t *fight)
{
    printf("RAGED\n");
    fight->enemy_infos->rage += 1;
    fight->enemy_infos->rage_turns = 3;
    fight->enemy_infos->did_attack = 1;
    return fight;
}

static fight_t *heal(fight_t *fight)
{
    printf("HEALED\n");
    fight->enemy_hp += 20;
    fight->enemy_infos->heal_turns = 3;
    fight->enemy_infos->did_attack = 1;
    return fight;
}

fight_t *make_ennemy_attack(fight_t *fight)
{
    if (fight->enemy_hp < 60 && fight->enemy_infos->heal_turns <= 0 &&
        fight->enemy_infos->did_attack != 1) {
        heal(fight);
    }
    if (fight->toskra_hp > 60 && fight->enemy_infos->rage_turns <= 0 &&
        fight->enemy_infos->did_attack != 1) {
        rage(fight);
    }
    if (fight->enemy_infos->did_attack != 1) {
        attack(fight);
    }
    fight->enemy_infos->did_attack = 0;
    fight->enemy_infos->rage_turns -= 1;
    fight->enemy_infos->heal_turns -= 1;
    return fight;
}

fight_t *enemy_attack(fight_t *fight)
{
    if (fight->turn == ENEMY) {
        fight = make_ennemy_attack(fight);
        fight->turn = TOSKRA;
    }
    return fight;
}
