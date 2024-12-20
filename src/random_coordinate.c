/*
** EPITECH PROJECT, 2024
** random coordinate
** File description:
** create random coordinate
*/

#include <stdlib.h>
#include <time.h>

int rand_coord(int min, int max)
{
    int coord;

    coord = (rand() % (max - min)) + min;
    return coord;
}
