/*
** EPITECH PROJECT, 2024
** unload.c
** File description:
** Function to unload npc talk
*/

#include "../../../include/myrpg.h"

void unload_npc_talk(void *args)
{
    myrpg_t *myrpg = args;

    EVENTS->load_function = EVENTS->previous_load_function;
    EVENTS->unload_function = EVENTS->previous_unload_function;
    EVENTS->event_function = EVENTS->previous_event_function;
    EVENTS->display_function = EVENTS->previous_display_function;
    EVENTS->previous_display_function = NULL;
    EVENTS->previous_unload_function = NULL;
    EVENTS->previous_event_function = NULL;
    EVENTS->previous_load_function = NULL;
    EVENTS->load_function(myrpg);
    myrpg->can_interact = 1;
}
