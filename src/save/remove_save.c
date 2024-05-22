/*
** EPITECH PROJECT, 2024
** remove_save
** File description:
** Function to remove the save
*/

#include "../../include/myrpg.h"

void remove_save(myrpg_t *myrpg)
{
    char *saves_path[] = { ".player", NULL };
    int fd;

    for (int i = 0; saves_path[i]; i++) {
        fd = open(saves_path[i], O_WRONLY);
        if (fd == -1)
            continue;
        write(fd, "", 1);
        close(fd);
    }
    PLAYER = init_player();
}
