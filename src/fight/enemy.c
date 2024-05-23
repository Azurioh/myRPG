/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Enemy algorithm to make it fight the player
*/

#include "../../include/fight.h"
#include "../../include/myrpg.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

enemy_t *init_enemy(myrpg_t *myrpg)
{
    int id = myrpg->fight_infos->enemy_id;
    enemy_t *enemy = malloc(sizeof(enemy_t));
    sfTexture *life = sfTexture_createFromFile
        ("assets/hud/profile_png.png", NULL);
    sfTexture *life_bar = sfTexture_createFromFile
        ("assets/hud/life.png", NULL);

    enemy->enemy_bottle = sfSprite_create();
    enemy->enemy_life = sfSprite_create();
    sfSprite_setTexture(enemy->enemy_bottle, life, sfFalse);
    sfSprite_setTexture(enemy->enemy_life, life_bar, sfFalse);
    enemy->did_attack = 0;
    enemy->rage = 1;
    enemy->rage_turns = 2;
    enemy->heal_turns = 0;
    enemy->attack = myrpg->mobs[id]->damages;
    return enemy;
}

static fight_t *attack(fight_t *fight)
{
    fight->toskra_hp -= fight->enemy_infos->attack * fight->enemy_infos->rage;
    fight->enemy_infos->did_attack = 1;
    return fight;
}

static fight_t *rage(fight_t *fight)
{
    fight->enemy_infos->rage += 1;
    fight->enemy_infos->rage_turns = 3;
    fight->enemy_infos->did_attack = 1;
    return fight;
}

static fight_t *heal(fight_t *fight)
{
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
