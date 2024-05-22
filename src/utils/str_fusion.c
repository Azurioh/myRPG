/*
** EPITECH PROJECT, 2023
** str_fusion
** File description:
** fusion two string in one
*/
#include <stdlib.h>
#include <string.h>
#include "../../include/myrpg.h"

char *str_fusion(char *str1, char *str2)
{
    int len = (int)strlen(str1) + (int)strlen(str2);
    char *str = malloc(sizeof(char) * (len + 1));
    int index;

    for (index = 0; index < (int)strlen(str1); index++) {
        str[index] = str1[index];
    }
    for (int i = 0; i < (int)strlen(str2); i++) {
        str[index] = str2[i];
        index++;
    }
    str[len] = '\0';
    return str;
}
