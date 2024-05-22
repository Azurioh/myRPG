/*
** EPITECH PROJECT, 2024
** myrpg.h
** File description:
** All protos, include and struct for the project
*/

#ifndef MYRPG_H
    #define MYRPG_H
    #define PLAYER myrpg->player
    #define GAME_INFO myrpg->game_info
    #define SETTINGS myrpg->settings
    #define EVENTS myrpg->events
    #define BUTTONS myrpg->buttons
    #define SCALING myrpg->settings->scaling
    #define WINDOW SETTINGS->window
    #define PLAYER_INTERFACE myrpg->player->interface
    #define INVENTORY myrpg->player->inventory
    #define QUESTS myrpg->quests
    #define HUD myrpg->hud

    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <time.h>
    #include <sys/stat.h>

    #include "player.h"
    #include "game.h"
    #include "button.h"
    #include "events.h"
    #include "generation.h"
    #include "settings.h"
    #include "hud.h"
    #include "inventory.h"
    #include "move.h"
    #include "portal.h"
    #include "npc.h"
    #include "item.h"
    #include "quest.h"

typedef struct myrpg_s {
    int game_open;
    player_t *player;
    item_t **items;
    game_t *game_info;
    event_t *events;
    sfSprite *background;
    sfMusic *music;
    quest_list_t *quests;
    bool music_started;
    button_t **buttons;
    portal_t *portal;
    settings_t *settings;
    hud_t *hud;
    npc_t *npc;
    int can_interact;
    int is_inventory;
    bool save_loaded;
} myrpg_t;

int start_game(void);
int loop(myrpg_t *myrpg);
inventory_t *init_inventory(myrpg_t *myrpg);
void free_myrpg(myrpg_t *myrpg);
void free_image(image_t *image);
sfVector2f get_mouse_position(sfRenderWindow *window);

void move(myrpg_t *myrpg);
void move_down_view(game_t *game_info, myrpg_t *myrpg);
void move_up_view(game_t *game_info, myrpg_t *myrpg);
void move_left_view(game_t *game_info, myrpg_t *myrpg);
void move_right_view(game_t *game_info, myrpg_t *myrpg);
void move_menu(game_menu_t *game_menu, sfVector2f offset);
void display_inventory(myrpg_t *myrpg);


// PORTAL
int teleport(portal_t *portal, int i, myrpg_t *myrpg);
void check_portal(myrpg_t *myrpg);
void set_all_after_tp(myrpg_t *myrpg, sfVector2f movement);
void draw_rectangle(myrpg_t *myrpg);

// NPC
void spawn_npc(myrpg_t *myrpg);
npc_t *init_npc(void);
void display_hud(myrpg_t *myrpg);

sfText *init_text(char *txt, sfVector2f position, unsigned int size,
    sfColor color);
button_t **init_action_buttons(myrpg_t *myrpg);

button_t **load_settings_buttons(settings_t *settings);
sfText **load_settings_texts(settings_t *settings);
void init_stats(myrpg_t *myrpg, inventory_t *inventory);
void display_stats(myrpg_t *myrpg);

void manage_button_event(button_t **buttons, myrpg_t *myrpg);
void animate_button(button_t *button);
void change_current_item(button_t *button, void *args);
void erase_text(myrpg_t *myrpg);

char *my_nbr_to_str(int nb);
char *my_strcat(char *dest, char const *str);
int includes_in_str(char const *str, char to_find);
char **my_str_to_word_array(char const *str, char const *step);
int my_arraylen(char **array);
char *str_fusion(char *str1, char *str2);
float get_time(sfClock *clock);
sfVector2f get_resize(myrpg_t *myrpg);
void free_all_texts(sfText **texts);
void free_array(char **array);

void start_to_edit_controls(myrpg_t *myrpg);
void load_control_elements(myrpg_t *myrpg);
void update_controls(myrpg_t *myrpg);

void load_settings_save(myrpg_t *myrpg, char **options);
void save_game(myrpg_t *myrpg);
bool load_game_save(myrpg_t *myrpg);
void load_player_save(myrpg_t *myrpg, char **options);
void remove_save(myrpg_t *myrpg);
void save_settings(myrpg_t *myrpg);
void save_player(myrpg_t *myrpg);
bool player_save(myrpg_t *myrpg);
void save_inventory(myrpg_t *myrpg);
void load_inventory_save(myrpg_t *myrpg, char **options);
bool inventory_save(myrpg_t *myrpg);
bool quests_save(myrpg_t *myrpg);
#endif
