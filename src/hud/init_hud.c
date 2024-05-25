/*
** EPITECH PROJECT, 2024
** init_hud
** File description:
** load all the sprite for the hud
*/

#include "../../include/myrpg.h"
#include "SFML/Graphics/Text.h"
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Window.h>

void init_hud_text(hud_t *hud, sfVector2f resize, game_t *g_info, char *name)
{
    char *key = malloc(sizeof(char) * 2);

    key[0] = g_info->keybinds->interact + 'A';
    key[1] = '\0';
    hud->font = sfFont_createFromFile("assets/font/alagard.ttf");
    hud->action = create_text(key, 48,
        (sfVector2f){resize.x + 1050, resize.y + 450}, hud->font);
    key[0] = g_info->keybinds->open_inventory + 'A';
    hud->name = create_text(name, 22, (sfVector2f){resize.x + 90,
                                resize.y + 3}, hud->font);
    hud->act_text = create_text(key, 48,
        (sfVector2f){resize.x + 1195, resize.y + 410}, hud->font);
    hud->skill_text = create_text("Nombre d'ameliorations disponibles :",
        18, (sfVector2f){resize.x + 850, resize.y + 31}, hud->font);
}

static void init_quest_hud(hud_t *hud, sfVector2f resize)
{
    hud->quest_bg = generate_sprite_with_file(
        "assets/hud/notification.png", 0.7);
    sfSprite_setPosition(hud->quest_bg,
        (sfVector2f){resize.x + 325, resize.y + 10});
    hud->quest_name = init_text("Titre",
        (sfVector2f){resize.x + 390, resize.y + 20}, 20, sfWhite);
    hud->quest_desc = init_text("Description",
        (sfVector2f){resize.x + 390, resize.y + 45}, 15, sfWhite);
    sfText_setOrigin(hud->quest_name, (sfVector2f){0, 0});
    sfText_setOrigin(hud->quest_desc, (sfVector2f){0, 0});
    sfText_setOutlineColor(hud->quest_name, sfBlack);
    sfText_setOutlineThickness(hud->quest_name, 2.0);
    sfText_setOutlineThickness(hud->quest_desc, 1.5);
}

hud_t *init_hud(char *name, game_t *game_info)
{
    hud_t *hud = malloc(sizeof(hud_t));
    sfVector2f center = sfView_getCenter(game_info->map_view);
    sfVector2f size = sfView_getSize(game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    hud->profile = create_imagefile("assets/hud/profile.png", resize.x + 4,
                                resize.y + 4, 1.2);
    hud->exp = create_imagefile("assets/hud/level.png", resize.x + 90,
                                resize.y + 60, 1.2);
    hud->life = create_imagefile("assets/hud/life.png", resize.x + 90,
                                resize.y + 36, 1.2);
    hud->inventory = create_imagefile("assets/hud/bag.png", resize.x + 1180,
                                resize.y + 350, 1.2);
    hud->skill = create_imagefile("assets/hud/notification.png",
                                resize.x + 800, resize.y + 15, 0.6);
    init_hud_text(hud, resize, game_info, name);
    init_quest_hud(hud, resize);
    return hud;
}
