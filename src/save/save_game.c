/*
** EPITECH PROJECT, 2024
** save_game
** File description:
** Function to save the game in a file
*/

#include "../../include/myrpg.h"

static void save_settings(myrpg_t *myrpg)
{
    int fd = open(".settings", O_CREAT | O_WRONLY, 0666);

    if (fd == -1) {
        printf("Can't save settings...\n");
        return;
    }
    dprintf(fd, "%f\n%d\n%d\n%d\n%d\n%d\n", SETTINGS->scaling,
        SETTINGS->actual_window_size, SETTINGS->actual_framerate,
        SETTINGS->sound_volume, SETTINGS->music_volume, SETTINGS->fullscreen);
    close(fd);
}

static void save_player(myrpg_t *myrpg)
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
    dprintf(fd, "%d\n%d\n%d\n%f\n%f\n", player->experience, player->level,
        player->nb_skills_to_upgrade, player->pos.x, player->pos.y);
    close(fd);
}

void save_game(myrpg_t *myrpg)
{
    save_settings(myrpg);
    save_player(myrpg);
}
