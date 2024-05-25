/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** init the lootables
*/

static int *init_heal_table(int *table)
{
    table[0] = 1;
    table[1] = 2;
    table[2] = 0;
    table[3] = 3;
    return table;
}

static int *init_common_table(int *table)
{
    table[0] = 4;
    table[1] = 9;
    table[2] = 13;
    table[3] = 17;
    table[4] = 21;
    return table;
}

static int *init_rare_table(int *table)
{
    table[0] = 5;
    table[1] = 10;
    table[2] = 14;
    table[3] = 18;
    table[4] = 22;
    return table;
}

static int *init_epic_table(int *table)
{
    table[0] = 6;
    table[1] = 11;
    table[2] = 15;
    table[3] = 19;
    table[4] = 23;
    return table;
}

static int *init_legendary_table(int *table)
{
    table[0] = 7;
    table[1] = 12;
    table[2] = 16;
    table[3] = 20;
    table[4] = 24;
    return table;
}

int **init_all_lootables(int **table)
{
    table[0] = init_heal_table(table[0]);
    table[1] = init_common_table(table[1]);
    table[2] = init_rare_table(table[2]);
    table[3] = init_epic_table(table[3]);
    table[4] = init_legendary_table(table[4]);
    return table;
}
