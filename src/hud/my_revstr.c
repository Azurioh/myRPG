/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** reverse a string*
*/

#include "../../include/myrpg.h"

void swap(char *a, char *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

char *my_revstr(char *str)
{
    int mid;
    int i = 0;
    int j = strlen(str) - 1;

    mid = strlen(str) / 2;
    while (i < mid) {
        swap(&str[i], &str[j]);
        i++;
        j--;
    }
    return (str);
}
