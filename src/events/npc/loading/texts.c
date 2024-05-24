/*
** EPITECH PROJECT, 2024
** texts.c
** File description:
** Function to load the texts of npc talk
*/

#include "../../../../include/myrpg.h"

static void load_special_texts(char **texts)
{
    texts[0] = strdup("Il y a trop de loup ici...");
    texts[1] = strdup("Faut arreter de jouer au loup garou");
    texts[2] = NULL;
    texts[3] = strdup("Comment allez-vous ?");
    texts[4] = strdup("Nan en vrai je m'en fous x)");
    texts[5] = strdup("(Me frappe pas stp)");
    texts[6] = NULL;
    texts[7] = strdup("Tu es trop fort !");
    texts[8] = strdup("J'aimerai être aussi fort que toi...");
    texts[9] = strdup("Soulever des gros troncs ca doit etre cool");
    texts[10] = NULL;
    texts[11] = strdup("J'ai perdu mon frigo !");
    texts[12] = strdup("Un certain Fabien a mis en place le -42");
    texts[13] = strdup("Ca fais 3 jours que j'ai pas pu manger...");
    texts[14] = NULL;
    texts[15] = strdup("Ralala... Il me manque Gabin...");
    texts[16] = strdup("J'espere pouvoir le revoir un jour...");
    texts[17] = strdup("Oh bonjour ! Moi c'est Clara.");
    texts[18] = NULL;
    texts[19] = strdup("Je n'ai pas envie de te parler.");
}

char **init_texts_npc(void)
{
    char **texts = malloc(sizeof(char *) * 21);

    load_special_texts(texts);
    texts[20] = NULL;
    return texts;
}
