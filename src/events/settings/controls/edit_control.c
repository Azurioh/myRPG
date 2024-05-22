/*
** EPITECH PROJECT, 2024
** edit_control.c
** File description:
** Function to update the controls
*/

#include "../../../../include/myrpg.h"

static bool check_if_key_already_used(myrpg_t *myrpg, int key_choose)
{
    for (int i = 0; GAME_INFO->keybinds->keybind_edit[i] != -1; i++) {
        if (GAME_INFO->keybinds->keybind_edit[i] == key_choose) {
            return true;
        }
    }
    return false;
}

static void set_new_keybind(myrpg_t *myrpg, int key_choose)
{
    int i = 0;

    if (check_if_key_already_used(myrpg, key_choose) == true) {
        sfText_setString(SETTINGS->visual_elements->texts[3],
            "Deja utilisee");
        return;
    }
    for (; GAME_INFO->keybinds->keybind_edit[i] != -1; i++) {
    }
    GAME_INFO->keybinds->keybind_edit[i] = key_choose;
    GAME_INFO->keybinds->keybind_edit[i + 1] = -1;
    sfText_setString(SETTINGS->visual_elements->texts[2],
        GAME_INFO->keybinds->actions[i + 1]);
    sfText_setString(SETTINGS->visual_elements->texts[3], "");
    if (i == 5) {
        update_controls(myrpg);
    }
}

static void manage_keybinds(void *args)
{
    myrpg_t *myrpg = args;

    if (EVENTS->event.type == sfEvtKeyPressed) {
        if (EVENTS->event.key.code == sfKeyEscape
            || EVENTS->event.key.code > sfKeyZ) {
            return;
        }
        set_new_keybind(myrpg, EVENTS->event.key.code);
    }
}

static char **get_list_of_keybinds(void)
{
    char **actions = malloc(sizeof(char *) * 7);

    actions[0] = my_strdup("Avancer");
    actions[1] = my_strdup("Reculer");
    actions[2] = my_strdup("Gauche");
    actions[3] = my_strdup("Droite");
    actions[4] = my_strdup("Inventaire");
    actions[5] = my_strdup("Utiliser");
    actions[6] = NULL;
    return actions;
}

static void load_edit_controls(myrpg_t *myrpg)
{
    GAME_INFO->keybinds->editing_keybinds = sfTrue;
    GAME_INFO->keybinds->keybind_edit = malloc(sizeof(int) * 7);
    GAME_INFO->keybinds->keybind_edit[0] = -1;
    GAME_INFO->keybinds->actions = get_list_of_keybinds();
    EVENTS->event_function = &manage_keybinds;
    load_control_elements(myrpg);
}

void start_to_edit_controls(myrpg_t *myrpg)
{
    for (int i = 0; SETTINGS->visual_elements->buttons[i]; i++)
        free_button(SETTINGS->visual_elements->buttons[i]);
    for (int i = 0; SETTINGS->visual_elements->texts[i]; i++)
        sfText_destroy(SETTINGS->visual_elements->texts[i]);
    free(SETTINGS->visual_elements->buttons);
    free(SETTINGS->visual_elements->texts);
    SETTINGS->visual_elements->buttons = NULL;
    SETTINGS->visual_elements->texts = NULL;
    load_edit_controls(myrpg);
}
