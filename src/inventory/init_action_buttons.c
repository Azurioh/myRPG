/*
** EPITECH PROJECT, 2024
** init_action_buttons
** File description:
** init action buttons
*/
#include "../../include/myrpg.h"

button_t **init_action_buttons(myrpg_t *myrpg)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    buttons[0] = init_button("use",
        (sfVector2f){resize.x + 728, resize.y + 440},
        "./assets/inventory/use.png", &use_item);
    buttons[0]->initial_scaling = 1.7;
    sfSprite_setScale(buttons[0]->image_sprite,
                (sfVector2f){1.7, 1.7});
    buttons[1] = init_button("drop",
        (sfVector2f){resize.x + 728, resize.y + 480},
        "./assets/inventory/drop.png", &drop_item);
    buttons[1]->initial_scaling = 1.7;
    sfSprite_setScale(buttons[1]->image_sprite,
                (sfVector2f){1.7, 1.7});
    buttons[2] = NULL;
    return buttons;
}
