/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_str_to_word_array
*/

#include "../../include/myrpg.h"

int get_nb_words(char const *str, char const *step)
{
    int spaced = 0;
    int nb_words = 0;

    if (!str) {
        return 0;
    }
    for (int i = 0; i < (int)strlen(str); i++) {
        if (includes_in_str(step, str[i]) && spaced == 0) {
            nb_words++;
            spaced = 1;
        }
        if (!includes_in_str(step, str[i]) && spaced == 1) {
            spaced = 0;
        }
    }
    if (spaced == 0) {
        nb_words++;
    }
    return nb_words;
}

char *extract_word(char const *str, char const *step, int *i)
{
    char *new_str;
    int nb_letters = 0;
    int end_index = 0;

    if (!step) {
        *i += (int)strlen(str);
        new_str = my_strdup(str);
        return new_str;
    }
    for (int j = *i; !includes_in_str(step, str[j]); j++) {
        nb_letters++;
    }
    new_str = malloc(sizeof(char) * (nb_letters + 1));
    end_index = *i + nb_letters;
    for (int j = 0; *i < end_index; *i += 1) {
        new_str[j] = str[*i];
        j++;
    }
    new_str[nb_letters] = '\0';
    return new_str;
}

char **my_str_to_word_array(char const *str, char const *step)
{
    char **word_array;
    int nb_words = 0;

    if (!str || str[0] == '\0')
        return NULL;
    word_array = malloc(sizeof(char *) * (get_nb_words(str, step) + 1));
    if (!word_array) {
        dprintf(2, "my_str_to_word_array: Memory allocation error\n");
        return NULL;
    }
    for (int i = 0; i < (int)strlen(str); i++) {
        if (includes_in_str(step, str[i]) == 0) {
            word_array[nb_words] = extract_word(str, step, &i);
            nb_words++;
        }
    }
    word_array[nb_words] = NULL;
    return word_array;
}
