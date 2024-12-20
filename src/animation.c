/*
** EPITECH PROJECT, 2024
** animation.c
** File description:
** animate diff sprite
*/

#include "../include/window_csfml.h"
#include <stdbool.h>
#include <stdio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

void display_explosion(window_t *wd, moving_sprite_t *explosion,
    sfIntRect *area)
{
    if (area->left < 1110){
        area->left += 160;
        sfSprite_setTextureRect(explosion->img.sprite, *area);
    }
}

static void set_sprite_bots(all_sprite_t *all_s)
{
    sfSprite_setTextureRect(all_s->bot1.img.sprite, all_s->bot1.area);
    sfSprite_setTextureRect(all_s->bot2.img.sprite, all_s->bot1.area);
    sfSprite_setTextureRect(all_s->bot3.img.sprite, all_s->bot1.area);
    sfSprite_setTextureRect(all_s->bot4.img.sprite, all_s->bot1.area);
    sfSprite_setTextureRect(all_s->bot5.img.sprite, all_s->bot1.area);
    sfSprite_setTextureRect(all_s->bot6.img.sprite, all_s->bot1.area);
    sfSprite_setTextureRect(all_s->bot7.img.sprite, all_s->bot1.area);
    sfSprite_setTextureRect(all_s->bot8.img.sprite, all_s->bot1.area);
}

static void set_area_bots(all_sprite_t *all_s)
{
    all_s->bot1.area.left += 110;
    all_s->bot2.area.left += 110;
    all_s->bot3.area.left += 110;
    all_s->bot4.area.left += 110;
    all_s->bot5.area.left += 110;
    all_s->bot6.area.left += 110;
    all_s->bot7.area.left += 110;
    all_s->bot8.area.left += 110;
    if (all_s->bot1.area.left > 300){
        all_s->bot1.area.left = 0;
        all_s->bot2.area.left = 0;
        all_s->bot3.area.left = 0;
        all_s->bot4.area.left = 0;
        all_s->bot5.area.left = 0;
        all_s->bot6.area.left = 0;
        all_s->bot7.area.left = 0;
        all_s->bot8.area.left = 0;
    }
}

void animate_bots(sfClock *clock, all_sprite_t *all_s, window_t wd)
{
    if (sfClock_getElapsedTime(clock).microseconds > 100000){
        set_area_bots(all_s);
        set_sprite_bots(all_s);
        sfClock_restart(clock);
    }
}

void animate_duck(sfClock *clock, sfIntRect *area,
    moving_sprite_t *duck, window_t wd)
{
    if (sfClock_getElapsedTime(clock).microseconds > 100000){
        area->left += 110;
        if (area->left > 300){
            area->left = 0;
        }
        sfSprite_setTextureRect(duck->img.sprite, *area);
        sfClock_restart(clock);
    }
}

void animate_all_duck(window_t wd, all_sprite_t *all_s,
    sfClock *clock, sfClock *clock_bot)
{
    animate_duck(clock, &all_s->player.area, &all_s->player, wd);
    animate_bots(clock_bot, all_s, wd);
}
