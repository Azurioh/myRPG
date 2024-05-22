/*
** EPITECH PROJECT, 2024
** erase_text
** File description:
** Function to erase the text in inventory when using a button
*/

#include "../../include/myrpg.h"

void erase_text(myrpg_t *myrpg)
{
    sfText_setString(INVENTORY->name, "");
    sfText_setString(INVENTORY->description, "");
}
