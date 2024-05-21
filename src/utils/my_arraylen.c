/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_arraylen
*/

#include <stddef.h>

int my_arraylen(char **array)
{
    int i = 0;

    if (array == NULL) {
        return 0;
    }
    while (array[i] != NULL) {
        i++;
    }
    return i;
}
