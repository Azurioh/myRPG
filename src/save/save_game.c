/*
** EPITECH PROJECT, 2024
** save_game
** File description:
** Function to save the game in a file
*/

#include "../../include/myrpg.h"
#include <stdlib.h>

void save_settings(myrpg_t *myrpg)
{
    int fd = open(".settings", O_CREAT | O_WRONLY, 0666);
    keybinds_t *keybinds = GAME_INFO->keybinds;

    if (fd == -1) {
        printf("Can't save settings...\n");
        return;
    }
    dprintf(fd, "%f\n%d\n%d\n%d\n%d\n%d\n", SETTINGS->scaling,
        SETTINGS->actual_window_size, SETTINGS->actual_framerate,
        SETTINGS->sound_volume, SETTINGS->music_volume, SETTINGS->fullscreen);
    dprintf(fd, "%d\n%d\n%d\n%d\n%d\n%d", keybinds->move_up,
        keybinds->move_down, keybinds->move_left, keybinds->move_right,
        keybinds->open_inventory, keybinds->interact);
    close(fd);
}

void save_player(myrpg_t *myrpg)
{
    int fd;
    player_t *player = myrpg->player;

    if (!player) {
        return;
    }
    fd = open(".player", O_CREAT | O_WRONLY, 0666);
    if (fd == -1) {
        printf("Can't save player...\n");
        return;
    }
    dprintf(fd, "%d\n%d\n%d\n%d\n%f\n%f", player->life, player->experience,
        player->level, player->nb_skills_to_upgrade, player->pos.x,
        player->pos.y);
    close(fd);
}

void save_inventory(myrpg_t *myrpg)
{
    int fd;

    if (!INVENTORY)
        return;
    fd = open(".inventory", O_CREAT | O_WRONLY, 0666);
    if (fd == -1) {
        printf("Can't save inventory...\n");
        return;
    }
    for (int i = 0; i < 15; i++)
        dprintf(fd, "%d\n", INVENTORY->id[i]);
    for (int i = 0; i < 5; i++) {
        if (INVENTORY->equipped[i])
            dprintf(fd, "%d", INVENTORY->equipped[i]->item_id);
        else
            dprintf(fd, "-1");
        if (i < 4)
            dprintf(fd, "\n");
    }
    close(fd);
}

void save_quests(myrpg_t *myrpg)
{
    int fd;

    if (!INVENTORY)
        return;
    fd = open(".quests", O_CREAT | O_WRONLY, 0666);
    if (fd == -1) {
        printf("Can't save the quest progression...\n");
        return;
    }
    dprintf(fd, "%d\n%d", QUESTS->actual_quest,
        QUESTS->quests[QUESTS->actual_quest]->nb);
    close(fd);
}

void save_game(myrpg_t *myrpg)
{
    save_settings(myrpg);
    save_player(myrpg);
    save_inventory(myrpg);
    save_quests(myrpg);
}
