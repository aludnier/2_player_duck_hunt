/*
** EPITECH PROJECT, 2024
** description
** File description:
** describe the command
*/

#include "../include/window_csfml.h"

int display_help(void)
{
    my_putstr("2 player my_hunter created with CSFML\n");
    my_putstr("Try to find and shoot the player among ducks\n\n");
    my_putstr("INTERACTION :\n  duck player movement:\n");
    my_putstr("\tz : up\n\ts : down\n\tq : left\n\td : rigth\n\n  ");
    my_putstr("Hunter player:\n\tmouve mouse to aim\n\tleft click : shoot\n");
    return 0;
}
