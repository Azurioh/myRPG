/*
** EPITECH PROJECT, 2024
** my_nbr_to_str.c
** File description:
** Convert a integer to a string
*/

#include <stdlib.h>

static int my_pow(int nb, int p)
{
    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    } else if (p == 1) {
        return nb;
    } else {
        return nb * my_pow(nb, p - 1);
    }
}

static int my_int_len(int nb)
{
    int i = 0;

    if (nb < 0) {
        i++;
    }
    if (nb == 0) {
        return 1;
    }
    while (nb != 0) {
        nb /= 10;
        i++;
    }
    return i;
}

char *my_nbr_to_str(int nb)
{
    char *str;
    int divise = my_pow(10, my_int_len(nb) - 1);
    int i = 0;

    str = malloc(sizeof(char) * my_int_len(nb) + 1);
    while (divise > 0) {
        str[i] = '0' + (nb / divise);
        nb -= (nb / divise) * divise;
        divise /= 10;
        i++;
    }
    str[i] = '\0';
    return str;
}
