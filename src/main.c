/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main function to start the program
*/

#include "../include/myrpg.h"

int display_help(void)
{
    printf("Welcome to Toskra's quest !\n");
    printf("To move use 'ZQSD' key or change key configuration in settings\n");
    printf("You can use 'E' to open inventory and ESC to open settings\n");
    printf("The goal of this game is to find your family ");
    printf("that has been kidnapped\n");
    return 0;
}

int main(int argc, char **argv)
{
    if (argc >= 2) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            return display_help();
        } else {
            printf("Wrong parameters try: ./my_rpg --help\n");
            return 84;
        }
    } else
        return start_game();
}
