/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** init_npc
*/

#include "../../include/npc.h"
#include "../../include/generation.h"
#include "../../include/myrpg.h"
#include "SFML/Graphics/Font.h"
#include "SFML/Graphics/RectangleShape.h"
#include "SFML/Graphics/Text.h"
#include "SFML/Graphics/Types.h"


sfSprite *init_npc_sprite(npc_info_t *info)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(NPC_PATH, NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, (sfVector2f){info->pos.x, info->pos.y});
    return sprite;
}

static void create_npc_collision_npc(npc_t *npc)
{
    sfVector2f scale = {100, 100};

    for (int i = 0; i < 6; i++) {
        npc->npc_info[i]->rect = sfRectangleShape_create();
        sfRectangleShape_setSize(npc->npc_info[i]->rect, scale);
        sfRectangleShape_setPosition(npc->npc_info[i]->rect,
            npc->npc_info[i]->pos);
        sfRectangleShape_setFillColor(npc->npc_info[i]->rect, sfBlack);
    }
}

static npc_info_t **fill_struct_npc(void)
{
    npc_info_t **npc_info = malloc(sizeof(npc_info_t *) * 7);

    if (!npc_info)
        return NULL;
    for (int i = 0; i < 6; i++) {
        npc_info[i] = malloc(sizeof(npc_info_t));
    }
    npc_info[0]->pos = (sfVector2f) {914, 1976};
    npc_info[1]->pos = (sfVector2f) {4736, 4910};
    npc_info[2]->pos = (sfVector2f) {3981, 5405};
    npc_info[3]->pos = (sfVector2f) {2940, 5954};
    npc_info[4]->pos = (sfVector2f) {3203, 3647};
    npc_info[5]->pos = (sfVector2f) {5712, 5736};
    npc_info[6] = NULL;
    for (int i = 0; i < 6; i++) {
        npc_info[i]->id = i;
    }
    return npc_info;
}

static npc_visual_t *init_npc_visual(myrpg_t *myrpg)
{
    npc_visual_t *visual = malloc(sizeof(npc_visual_t));
    sfFont *font = sfFont_createFromFile(FONT);
    sfVector2f resize = get_resize(myrpg);

    resize.x += 200;
    resize.y += 200;
    visual->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(visual->rect, (sfVector2f){1920, 500});
    sfRectangleShape_setFillColor(visual->rect, sfWhite);
    visual->text = sfText_create();
    sfText_setFont(visual->text, font);
    sfText_setColor(visual->text, sfBlack);
    sfText_setCharacterSize(visual->text, 50);
    return visual;
}

npc_t *init_npc(myrpg_t *myrpg)
{
    npc_t *npc = malloc(sizeof(npc_t));

    npc->npc_info = fill_struct_npc();
    for (int i = 0; npc->npc_info[i] != NULL; i++) {
        npc->npc_info[i]->sprite = init_npc_sprite(npc->npc_info[i]);
    }
    npc->all_texts = init_texts_npc();
    npc->visual = init_npc_visual(myrpg);
    create_npc_collision_npc(npc);
    return npc;
}
