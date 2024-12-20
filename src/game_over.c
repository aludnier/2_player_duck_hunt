/*
** EPITECH PROJECT, 2024
** game_over.c
** File description:
** check for game over
*/

#include "../include/window_csfml.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

void alive_end_game(bool is_alive, int *nb_shoot)
{
    if (is_alive)
        *nb_shoot = -1;
    else
        *nb_shoot = -2;
}

void display_winner(window_t wd, int *nb_shoot)
{
    if (*nb_shoot == -1)
        draw_win(&wd, &wd.win, 'd');
    if (*nb_shoot == -2)
        draw_win(&wd, &wd.win, 'h');
}

void check_game_over(window_t wd, bool is_alive, int *nb_shoot)
{
    if (*nb_shoot == 0){
        alive_end_game(is_alive, nb_shoot);
    } else if (!is_alive && *nb_shoot > 0){
        *nb_shoot = -2;
    }
    display_winner(wd, nb_shoot);
}
