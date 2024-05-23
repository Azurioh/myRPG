/*
** EPITECH PROJECT, 2024
** free_arrays
** File description:
** Function to free an array
*/

#include "../../include/myrpg.h"

void free_array(char **array)
{
    if (!array) {
        return;
    }
    for (int i = 0; array[i]; i++) {
        free(array[i]);
    }
    free(array);
    return;
}
