/*
** EPITECH PROJECT, 2024
** hud
** File description:
** hud
*/

#ifndef HUD_H
    #define HUD_H
    #include <SFML/Graphics.h>
    #include "game.h"
    #include "generation.h"

typedef struct hud_s {
    sfFont *font;
    image_t *inventory;
    image_t *profile;
    image_t *life;
    image_t *exp;
    image_t *skill;
    sfText *skill_text;
    sfText *action;
    sfText *name;
    sfText *act_text;
} hud_t;

hud_t *init_hud(char *name, game_t *game_info);
char *my_revstr(char *str);
char *nbr_to_str(int nb);
void free_hud(hud_t *myrpg);

#endif /* !HUD_H */
