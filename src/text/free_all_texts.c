/*
** EPITECH PROJECT, 2024
** free_all_texts
** File description:
** Function to free array of sfText
*/

#include "../../include/myrpg.h"

void free_all_texts(sfText **texts)
{
    if (!texts) {
        return;
    }
    for (int i = 0; texts[i]; i++) {
        sfText_destroy(texts[i]);
    }
    free(texts);
}
