/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** init the lootables
*/

int *init_common_table(int *table)
{
    table[0] = 2;
    table[1] = 3;
    table[2] = 8;
    table[3] = 12;
    table[4] = 16;
    table[5] = 20;
    return table;
}

int *init_rare_table(int *table)
{
    table[0] = 1;
    table[1] = 9;
    table[2] = 13;
    table[3] = 17;
    table[4] = 21;
    return table;
}

int *init_epic_table(int *table)
{
    table[0] = 5;
    table[1] = 10;
    table[2] = 14;
    table[3] = 18;
    table[4] = 22;
    return table;
}

int *init_legendary_table(int *table)
{
    table[0] = 0;
    table[1] = 7;
    table[2] = 11;
    table[3] = 15;
    table[4] = 19;
    table[5] = 23;
    return table;
}

int **init_all_lootables(int **table)
{
    table[0] = init_common_table(table[0]);
    table[1] = init_rare_table(table[1]);
    table[2] = init_epic_table(table[2]);
    table[3] = init_legendary_table(table[3]);
    return table;
}
