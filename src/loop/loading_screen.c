/*
** EPITECH PROJECT, 2024
** loading_screen.c
** File description:
** Loading screen function
*/

#include "../../include/myrpg.h"

static void place_loading_bars(myrpg_t *myrpg)
{
    sfVector2f size =
        sfRectangleShape_getSize(myrpg->loading_screen->loading_bars[1]);

    sfRectangleShape_setOrigin(myrpg->loading_screen->loading_bars[0],
        (sfVector2f){ size.x / 2, size.y / 2 });
    sfRectangleShape_setOrigin(myrpg->loading_screen->loading_bars[1],
        (sfVector2f){ size.x / 2, size.y / 2 });
    sfRectangleShape_setPosition(myrpg->loading_screen->loading_bars[0],
        (sfVector2f){960 * SCALING, 540 * SCALING});
    sfRectangleShape_setPosition(myrpg->loading_screen->loading_bars[1],
        (sfVector2f){960 * SCALING, 540 * SCALING});
}

void init_loading_screen_text(myrpg_t *myrpg)
{
    sfFloatRect size;
    sfFont *font = sfFont_createFromFile(FONT);

    sfText_setString(myrpg->loading_screen->text, "Chargement de la map");
    sfText_setCharacterSize(myrpg->loading_screen->text, 50 * SCALING);
    sfText_setFont(myrpg->loading_screen->text, font);
    size = sfText_getGlobalBounds(myrpg->loading_screen->text);
    sfText_setOrigin(myrpg->loading_screen->text,
        (sfVector2f){ size.width / 2, size.height / 2 });
    sfText_setPosition(myrpg->loading_screen->text,
        (sfVector2f){ 960 * SCALING, 540 * SCALING });
    sfText_setColor(myrpg->loading_screen->text, sfBlack);
}

static loading_screen_t *init_loading_screen(myrpg_t *myrpg)
{
    loading_screen_t *info = malloc(sizeof(loading_screen_t));
    sfVideoMode w_size =
        SETTINGS->window_size_list[SETTINGS->actual_window_size];

    info->background = sfRectangleShape_create();
    info->loading_bars = malloc(sizeof(sfRectangleShape *) * 2);
    info->loading_bars[0] = sfRectangleShape_create();
    info->loading_bars[1] = sfRectangleShape_create();
    sfRectangleShape_setSize(info->background,
        (sfVector2f){w_size.width, w_size.height});
    sfRectangleShape_setFillColor(info->background, sfBlack);
    sfRectangleShape_setSize(info->loading_bars[0],
        (sfVector2f){ 0 * SETTINGS->scaling, 200 * SETTINGS->scaling});
    sfRectangleShape_setSize(info->loading_bars[1],
        (sfVector2f){ 1000 * SETTINGS->scaling, 200 * SETTINGS->scaling});
    sfRectangleShape_setFillColor(info->loading_bars[0], sfRed);
    sfRectangleShape_setFillColor(info->loading_bars[1], sfWhite);
    info->text = sfText_create();
    return info;
}

static bool animate_loading_bar(myrpg_t *myrpg)
{
    sfVector2f bar_size =
        sfRectangleShape_getSize(myrpg->loading_screen->loading_bars[0]);
    sfTime time;

    if (bar_size.x < ((1000 * SCALING / 6) *
        myrpg->loading_screen->loading_status)) {
        time = sfClock_getElapsedTime(myrpg->loading_screen->animation_clock);
        if (time.microseconds >= 5 * 1000) {
            bar_size.x += 7;
            sfRectangleShape_setSize(myrpg->loading_screen->loading_bars[0],
                bar_size);
            sfClock_restart(myrpg->loading_screen->animation_clock);
        }
        return true;
    } else {
        return false;
    }
}

static void display_loading_screen(myrpg_t *myrpg)
{
    sfFloatRect size = sfText_getGlobalBounds(myrpg->loading_screen->text);

    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawRectangleShape(WINDOW,
        myrpg->loading_screen->background, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW,
        myrpg->loading_screen->loading_bars[1], NULL);
    sfRenderWindow_drawRectangleShape(WINDOW,
        myrpg->loading_screen->loading_bars[0], NULL);
    sfText_setOrigin(myrpg->loading_screen->text,
        (sfVector2f){ size.width / 2, size.height / 2 });
    sfText_setPosition(myrpg->loading_screen->text,
        (sfVector2f){ 960 * SCALING, 530 * SCALING });
    sfRenderWindow_drawText(WINDOW, myrpg->loading_screen->text, NULL);
    sfRenderWindow_display(WINDOW);
}

void init_texture_maps(myrpg_t *myrpg)
{
    myrpg->maps = malloc(sizeof(sfTexture *) * 4);
    myrpg->maps[0] = sfTexture_createFromFile(MAP_PATH, NULL);
    myrpg->maps[1] = sfTexture_createFromFile(FIGHT_MAP, NULL);
    myrpg->maps[2] = sfTexture_createFromFile(UNDERMAP_PATH, NULL);
    myrpg->maps[3] = sfTexture_createFromFile(UPPERMAP_PATH, NULL);
}

static void load_elements(myrpg_t *myrpg)
{
    if (myrpg->loading_screen->loading_status == 1) {
        sfText_setString(myrpg->loading_screen->text, "Chargement des items");
        myrpg->items = init_items();
    }
    if (myrpg->loading_screen->loading_status == 2) {
        sfText_setString(myrpg->loading_screen->text,
            "Chargement des monstres");
        myrpg->mobs = init_mobs();
    }
    if (myrpg->loading_screen->loading_status == 3) {
        sfText_setString(myrpg->loading_screen->text,
            "Chargement des portails");
        myrpg->portal = portal_map();
    }
    if (myrpg->loading_screen->loading_status == 4) {
        sfText_setString(myrpg->loading_screen->text,
            "Chargement de la page d'accueil");
        load_main_menu(myrpg);
    }
}

void loading_screen_events(myrpg_t *myrpg)
{
    while (sfRenderWindow_pollEvent(WINDOW, &EVENTS->event)) {
        if (EVENTS->event.type == sfEvtClosed) {
            sfRenderWindow_destroy(WINDOW);
            exit(0);
        }
    }
}

void loading_screen(myrpg_t *myrpg)
{
    myrpg->loading_screen = init_loading_screen(myrpg);
    place_loading_bars(myrpg);
    init_loading_screen_text(myrpg);
    myrpg->loading_screen->loading_status = 0;
    myrpg->loading_screen->animation_clock = sfClock_create();
    while (myrpg->loading_screen->loading_status != 6) {
        loading_screen_events(myrpg);
        display_loading_screen(myrpg);
        if (myrpg->loading_screen->loading_status == 0)
            init_texture_maps(myrpg);
        load_elements(myrpg);
        myrpg->loading_screen->loading_status++;
        while (animate_loading_bar(myrpg) == true)
            display_loading_screen(myrpg);
    }
    loop(myrpg);
}
