/*
** EPITECH PROJECT, 2024
** init_quests.c
** File description:
** Function to init the differents quests
*/

#include "../../include/myrpg.h"

static quest_t *init_quest(char *name, char *description, int nb_required)
{
    quest_t *quest = malloc(sizeof(quest_t));

    quest->name = strdup(name);
    quest->description = strdup(description);
    quest->is_unlocked = false;
    quest->is_validate = false;
    quest->nb = 0;
    quest->nb_required = nb_required;
    return quest;
}

static void fill_tutorial_quests(quest_t **quests)
{
    quests[0] = init_quest("Ton arme, tu recuperera.",
        "Equipe la hache de ton pere", 1);
    quests[0]->is_unlocked = true;
    quests[1] = init_quest("Tes competences, tu developperas.",
        "Ameliore une competence", 1);
    quests[2] = init_quest("L'ennemi, tu vaincras.",
        "Combat ton premier ennemi", 1);
    quests[3] = init_quest("La boisson, tu buveras.",
        "Utilise la potion dans ton inventaire", 1);
    quests[4] = init_quest("Les niveaux, tu grimpras.",
        "Atteint le niveau 2", 1);
}

static void fill_medium_quests(quest_t **quests)
{
    quests[5] = init_quest("Le combat, tu maitriseras.",
        "Combat 5 ennemis", 5);
    quests[6] = init_quest("L'habit, fera le moine.",
        "Porte un equipement complet", 1);
    quests[7] = init_quest("Un pouvoir, tu perfectionneras.",
        "Augmente une competence au niveau maximum", 1);
    quests[8] = init_quest("Tes adversaires, tu domineras.",
        "Combat 8 ennemis", 8);
}

static void fill_quests(quest_t **quests)
{
    fill_tutorial_quests(quests);
    fill_medium_quests(quests);
    quests[9] = init_quest("Le boss, tu domineras.",
        "Affronte le boss final de la forêt", 1);
    quests[10] = init_quest("Le jeu, tu finiras.",
        "GG tu as fini le jeu, amuse toi maintenant !", 1);
    quests[11] = NULL;
}

static quest_t **init_quests(void)
{
    quest_t **quests = malloc(sizeof(quests) * 12);

    fill_quests(quests);
    return quests;
}

quest_list_t *create_quest_list(void)
{
    quest_list_t *quests = malloc(sizeof(quest_list_t));

    quests->actual_quest = 0;
    quests->quests = init_quests();
    return quests;
}
