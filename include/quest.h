/*
** EPITECH PROJECT, 2024
** quest.h
** File description:
** All structs and protos for the quests
*/

#ifndef QUEST_H
    #define QUEST_H
    #include <stdbool.h>

typedef struct quest_s {
    bool is_validate;
    bool is_unlocked;
    int nb;
    int nb_required;
    char *name;
    char *description;
} quest_t;

typedef struct quest_list_s {
    int actual_quest;
    quest_t **quests;
} quest_list_t;

quest_list_t *create_quest_list(void);
void update_quest(quest_list_t *quest_list);
#endif
