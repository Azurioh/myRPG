/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** Concatenate two strings
*/

#include <string.h>
#include <stdlib.h>
#include <stddef.h>

char *my_strcat(char *dest, char const *str)
{
    char *new_str;
    int j = 0;

    if (!dest)
        return NULL;
    new_str = malloc(sizeof(char) * (strlen(dest) + strlen(str) + 1));
    if (!new_str) {
        return NULL;
    }
    for (; j < (int)strlen(dest); j++)
        new_str[j] = dest[j];
    for (int i = 0; i < (int)strlen(str); i++) {
        new_str[j] = str[i];
        j++;
    }
    new_str[j] = '\0';
    free(dest);
    return new_str;
}
