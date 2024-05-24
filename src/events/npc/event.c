/*
** EPITECH PROJECT, 2024
** event.c
** File description:
** Function to manage event when npc talk
*/

#include "../../../include/myrpg.h"

static void npc_events(void *args)
{
    myrpg_t *myrpg = args;

    if (EVENTS->event.type == sfEvtKeyPressed) {
        NPC->read++;
        if (!NPC->all_texts[NPC->read]) {
            EVENTS->unload_function(myrpg);
        } else {
            sfText_setString(NPC->visual->text, NPC->all_texts[NPC->read]);
        }
    }
}

void display_npc(void *args)
{
    myrpg_t *myrpg = args;

    EVENTS->previous_load_function = EVENTS->load_function;
    EVENTS->previous_unload_function = EVENTS->unload_function;
    EVENTS->previous_event_function = EVENTS->event_function;
    EVENTS->previous_display_function = EVENTS->display_function;
    EVENTS->load_function = &load_npc_talks;
    EVENTS->unload_function = &unload_npc_talk;
    EVENTS->event_function = &npc_events;
    EVENTS->display_function = &display_npc_talk;
    EVENTS->load_function(myrpg);
}
