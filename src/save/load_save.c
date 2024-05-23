/*
** EPITECH PROJECT, 2024
** load_save
** File description:
** Function to load the save of the game
*/

#include "../../include/myrpg.h"

static char *read_fd(int fd, char *pathname)
{
    struct stat s;
    char *buffer;

    stat(pathname, &s);
    if (!s.st_size) {
        return NULL;
    }
    buffer = malloc(sizeof(char) * (s.st_size + 1));
    read(fd, buffer, s.st_size);
    buffer[s.st_size] = 0;
    return buffer;
}

static bool settings_save(myrpg_t *myrpg)
{
    int fd = open("save/.settings", O_RDONLY);
    char *buffer;
    char **options;

    if (fd == -1)
        return false;
    buffer = read_fd(fd, "save/.settings");
    if (!buffer) {
        close(fd);
        return false;
    }
    options = my_str_to_word_array(buffer, "\n");
    free(buffer);
    if (!options || my_arraylen(options) != 14) {
        close(fd);
        return false;
    }
    load_settings_save(myrpg, options);
    free_array(options);
    return true;
}

bool player_save(myrpg_t *myrpg)
{
    int fd = open("save/.player", O_RDONLY);
    char *buffer;
    char **options;

    if (fd == -1)
        return false;
    buffer = read_fd(fd, "save/.player");
    if (!buffer) {
        close(fd);
        return false;
    }
    options = my_str_to_word_array(buffer, "\n");
    free(buffer);
    if (!options || my_arraylen(options) != 9) {
        close(fd);
        return false;
    }
    load_player_save(myrpg, options);
    free_array(options);
    return true;
}

bool inventory_save(myrpg_t *myrpg)
{
    int fd = open("save/.inventory", O_RDONLY);
    char *buffer;
    char **options;

    if (fd == -1)
        return false;
    buffer = read_fd(fd, "save/.inventory");
    if (!buffer) {
        close(fd);
        return false;
    }
    options = my_str_to_word_array(buffer, "\n");
    free(buffer);
    if (!options || my_arraylen(options) != 20) {
        return false;
    }
    load_inventory_save(myrpg, options);
    free_array(options);
    return true;
}

bool quests_save(myrpg_t *myrpg)
{
    int fd = open("save/.quests", O_RDONLY);
    char *buffer;
    char **options;

    if (fd == -1)
        return false;
    buffer = read_fd(fd, "save/.quests");
    if (!buffer) {
        close(fd);
        return false;
    }
    options = my_str_to_word_array(buffer, "\n");
    free(buffer);
    if (!options || my_arraylen(options) != 2) {
        close(fd);
        return false;
    }
    load_quest_save(myrpg, options);
    free_array(options);
    return true;
}

bool load_game_save(myrpg_t *myrpg)
{
    if (settings_save(myrpg) == true) {
        myrpg->save_loaded = true;
    } else {
        return false;
    }
    if (player_save(myrpg) == false) {
        myrpg->save_loaded = false;
        return false;
    }
    return true;
}
