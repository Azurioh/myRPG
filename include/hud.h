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
    image_t *level;
    image_t *skill_to_up;
    sfText *name;
} hud_t;

hud_t *init_hud(void);

#endif /* !HUD_H */
