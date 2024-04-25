/*
** EPITECH PROJECT, 2024
** hud
** File description:
** hud
*/

#ifndef HUD_H
    #define HUD_H
    #include <SFML/Graphics.h>


typedef struct image_s {
    sfTexture *texture;
    sfSprite *sprite;
} image_t;

typedef struct hud_s {
    image_t *inventory;
    image_t *profile;
    image_t *life;
    image_t *exp;
    image_t *skill_to_up;
    sfFont *font;
    sfText *action;
    sfText *name;
    sfText *act_text;
} hud_t;

hud_t *init_hud(char *name);
char *my_revstr(char *str);
char *nbr_to_str(int nb);

#endif /* !HUD_H */
