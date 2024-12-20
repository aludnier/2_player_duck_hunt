/*
** EPITECH PROJECT, 2024
** window
** File description:
** create window
*/

#include "../include/window_csfml.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

sfVector2f change_vector(float x, float y)
{
    sfVector2f v = {x, y};

    return v;
}

void reset_window(window_t wd)
{
    sfColor black = {0, 0, 0, 0};

    sfRenderWindow_display(wd.window);
    sfRenderWindow_clear(wd.window, black);
}

void event_loop(window_t wd, all_sprite_t *all_s,
    sfClock *clock, ...)
{
    sfEvent event;
    int *nb_shoot = NULL;
    va_list ap;
    bool *is_alive = NULL;

    va_start(ap, clock);
    nb_shoot = va_arg(ap, int *);
    is_alive = va_arg(ap, bool *);
    while (sfRenderWindow_pollEvent(wd.window, &event)){
        handle_event(wd, &all_s->visor, event, nb_shoot);
        *is_alive = handle_shoot(&wd, event, all_s, clock);
    }
    va_end(ap);
}

int game_loop(window_t wd, all_sprite_t *all_s, int nb_shoot)
{
    bool is_alive = true;
    sfClock *clock = sfClock_create();
    sfClock *clock_mov = sfClock_create();
    sfClock *explode_clock = sfClock_create();
    sfClock *clock_bot = sfClock_create();
    sfClock *clock_bot_mov = sfClock_create();

    sfMusic_play(wd.sound.music);
    while (sfRenderWindow_isOpen(wd.window)){
        animate_all_duck(wd, all_s, clock, clock_bot);
        player_movement(&all_s->player, clock_mov);
        move_all_bot(all_s, clock_bot_mov);
        event_loop(wd, all_s, explode_clock, &nb_shoot, &is_alive);
        draw_sprite(wd, *all_s, nb_shoot);
        check_duck_alive(wd, explode_clock, all_s, is_alive);
        check_game_over(wd, is_alive, &nb_shoot);
        reset_window(wd);
    }
    destroy_all(&wd, all_s, clock, clock_mov, explode_clock, clock_bot);
    return 0;
}
