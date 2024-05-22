/*
** EPITECH PROJECT, 2024
** menu_keybinds.c
** File description:
** Function to load the text of the keybinds menu
*/

#include "../../include/myrpg.h"
#include "SFML/Graphics/Color.h"
#include "SFML/Window/Keyboard.h"

static void load_static_keybind_texts(sfText **texts, sfVector2f resize)
{
    sfColor color = sfColor_fromRGBA(200, 200, 200, 255);

    texts[0] = init_text("Avancer :",
        (sfVector2f){ resize.x + 90, resize.y + 230 }, 30, color);
    texts[1] = init_text("Reculer :",
        (sfVector2f){ resize.x + 90, resize.y + 270 }, 30, color);
    texts[2] = init_text("Gauche :",
        (sfVector2f){ resize.x + 90, resize.y + 310 }, 30, color);
    texts[3] = init_text("Droite :",
        (sfVector2f){ resize.x + 90, resize.y + 350 }, 30, color);
    texts[4] = init_text("Inventaire :",
        (sfVector2f){ resize.x + 90, resize.y + 390 }, 30, color);
    texts[5] = init_text("Interagir :",
        (sfVector2f){ resize.x + 90, resize.y + 430 }, 30, color);
}

static void load_dynamic_keybind_texts(sfText **texts, sfVector2f resize)
{
    texts[6] = init_text("",
        (sfVector2f){ resize.x + 235, resize.y + 230 }, 30, sfWhite);
    texts[7] = init_text("",
        (sfVector2f){ resize.x + 230, resize.y + 270 }, 30, sfWhite);
    texts[8] = init_text("",
        (sfVector2f){ resize.x + 220, resize.y + 310 }, 30, sfWhite);
    texts[9] = init_text("",
        (sfVector2f){ resize.x + 205, resize.y + 350 }, 30, sfWhite);
    texts[10] = init_text("",
        (sfVector2f){ resize.x + 260, resize.y + 390 }, 30, sfWhite);
    texts[11] = init_text("",
        (sfVector2f){ resize.x + 224, resize.y + 430 }, 30, sfWhite);
}

void update_dynamic_texts(game_t *game_info, sfText **texts)
{
    char *key = malloc(sizeof(char) * 2);

    key[0] = game_info->keybinds->move_up + 'A';
    key[1] = '\0';
    sfText_setString(texts[6], key);
    key[0] = game_info->keybinds->move_down + 'A';
    sfText_setString(texts[7], key);
    key[0] = game_info->keybinds->move_left + 'A';
    sfText_setString(texts[8], key);
    key[0] = game_info->keybinds->move_right + 'A';
    sfText_setString(texts[9], key);
    key[0] = game_info->keybinds->open_inventory + 'A';
    sfText_setString(texts[10], key);
    key[0] = game_info->keybinds->interact + 'A';
    sfText_setString(texts[11], key);
    free(key);
}

sfText **load_texts_elements(game_t *game_info, sfVector2f resize)
{
    sfText **texts = malloc(sizeof(sfText *) * 13);

    load_static_keybind_texts(texts, resize);
    load_dynamic_keybind_texts(texts, resize);
    texts[12] = NULL;
    for (int i = 0; i < 12; i++) {
        sfText_setOrigin(texts[i], (sfVector2f){0, 0});
    }
    update_dynamic_texts(game_info, texts);
    return texts;
}
