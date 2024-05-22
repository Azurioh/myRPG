/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_strdup
*/
#include <stdlib.h>
#include <string.h>

char *my_strdup(char const *str)
{
    char *new_str;

    if (!str) {
        new_str = malloc(sizeof(char));
        new_str[0] = '\0';
        return new_str;
    }
    new_str = malloc(sizeof(char) * (strlen(str) + 1));
    for (long unsigned int i = 0; i <= strlen(str); i++) {
        new_str[i] = str[i];
    }
    return new_str;
}
