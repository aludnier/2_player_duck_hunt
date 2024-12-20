/*
** EPITECH PROJECT, 2024
** draw_sprite
** File description:
** draw diff sprite
*/

#include "../include/window_csfml.h"
#include <stdbool.h>
#include <stdio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

void draw_mv_sprite(window_t wd, moving_sprite_t mv_sprite)
{
    sfSprite_setPosition(mv_sprite.img.sprite, mv_sprite.position);
    sfRenderWindow_drawSprite(wd.window, mv_sprite.img.sprite, NULL);
}

void draw_duck(window_t wd, all_sprite_t all_s)
{
    draw_mv_sprite(wd, all_s.bot1);
    draw_mv_sprite(wd, all_s.bot2);
    draw_mv_sprite(wd, all_s.bot3);
    draw_mv_sprite(wd, all_s.bot4);
    draw_mv_sprite(wd, all_s.bot5);
    draw_mv_sprite(wd, all_s.bot6);
    draw_mv_sprite(wd, all_s.bot7);
    draw_mv_sprite(wd, all_s.bot8);
}

void resize_ammo(image_t *ammo, int nb_shoot)
{
    sfIntRect ammo_area = {0, 0, 53 * nb_shoot, 60};

    sfSprite_setTextureRect(ammo->sprite, ammo_area);
}

void draw_sprite(window_t wd, all_sprite_t all_s, int nb_shoot)
{
    sfRenderWindow_drawSprite(wd.window, wd.bg.sprite, NULL);
    resize_ammo(&wd.ammo, nb_shoot);
    sfRenderWindow_drawSprite(wd.window, wd.ammo.sprite, NULL);
    draw_duck(wd, all_s);
    draw_mv_sprite(wd, all_s.player);
    if (all_s.visor.position.x + 45 > 0 && all_s.visor.position.y + 45 > 0){
        if (all_s.visor.position.x + 55 <= 1200 &&
            all_s.visor.position.y + 55 <= 800)
            draw_mv_sprite(wd, all_s.visor);
    }
}

void draw_win(window_t *wd, image_t *win, char winner)
{
    sfIntRect win_area = {0, 0, 356, 60};
    sfVector2f pos = {470, 0};

    if (winner == 'd'){
        win_area.top = 60;
    } else if (winner == 'h'){
        win_area.top = 0;
    }
    sfSprite_setPosition(win->sprite, pos);
    sfSprite_setTextureRect(win->sprite, win_area);
    sfRenderWindow_drawSprite(wd->window, win->sprite, NULL);
}
