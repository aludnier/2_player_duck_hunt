/*
** EPITECH PROJECT, 2024
** check_player_alive
** File description:
** check if player is alive
*/

#include "../include/window_csfml.h"
#include <stdbool.h>
#include <stdio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

void set_explosion(window_t wd, moving_sprite_t *explosion, sfClock *clock)
{
    sfSprite_setPosition(explosion->img.sprite,
        explosion->position);
    display_explosion(&wd, explosion, &explosion->area);
    sfRenderWindow_drawSprite(
        wd.window, explosion->img.sprite, NULL);
    sfClock_restart(clock);
}

void display_smoke(window_t wd, sfClock *explode_clock,
    all_sprite_t *all_s, bool is_alive)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && is_alive){
        if (sfClock_getElapsedTime(explode_clock).microseconds >= 25000){
            set_explosion(wd, &all_s->smoke, explode_clock);
        }
        sfRenderWindow_drawSprite(
            wd.window, all_s->smoke.img.sprite, NULL);
    }
}

void check_duck_alive(window_t wd, sfClock *explode_clock,
    all_sprite_t *all_s, bool is_alive)
{
    sfEvent event;

    all_s->smoke.position = change_vector(
            all_s->visor.position.x, all_s->visor.position.y);
    all_s->explosion.position = change_vector(
            all_s->visor.position.x, all_s->visor.position.y);
    if (!is_alive && all_s->explosion.area.left < 1110){
        if (sfClock_getElapsedTime(explode_clock).microseconds >= 40000){
            set_explosion(wd, &all_s->explosion, explode_clock);
        }
        sfRenderWindow_drawSprite(
            wd.window, all_s->explosion.img.sprite, NULL);
    }
    display_smoke(wd, explode_clock, all_s, is_alive);
    if (all_s->smoke.area.left > 1110){
        all_s->smoke.area.left = 0;
    }
}
