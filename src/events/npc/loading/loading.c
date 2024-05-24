/*
** EPITECH PROJECT, 2024
** loading.c
** File description:
** Function to load the npc talk
*/

#include "../../../../include/myrpg.h"


void load_npc_talks(void *args)
{
    myrpg_t *myrpg = args;
    int index_valid[] = {0, 3, 7, 11, 15, 19};

    srand(time(NULL));
    NPC->read = index_valid[rand() % 6];
    sfText_setString(NPC->visual->text, NPC->all_texts[NPC->read]);
}
