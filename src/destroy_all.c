/*
** EPITECH PROJECT, 2024
** destroy_all
** File description:
** destroy all arg
*/

#include "../include/window_csfml.h"
#include <stdio.h>
#include <stdarg.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

void destroy_img(image_t *img)
{
    sfTexture *texture = img->texture;
    sfSprite *sprite = img->sprite;

    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void destroy_mv_sprite(moving_sprite_t *mv_sprite)
{
    destroy_img(&mv_sprite->img);
}

void destroy_bot(sfSprite *bot)
{
    sfSprite_destroy(bot);
}

void destroy_all_sprite(all_sprite_t *all_s)
{
    destroy_mv_sprite(&all_s->player);
    destroy_mv_sprite(&all_s->visor);
    destroy_bot(all_s->bot1.img.sprite);
    destroy_bot(all_s->bot2.img.sprite);
    destroy_bot(all_s->bot3.img.sprite);
    destroy_bot(all_s->bot4.img.sprite);
    destroy_bot(all_s->bot5.img.sprite);
    destroy_bot(all_s->bot6.img.sprite);
    destroy_bot(all_s->bot7.img.sprite);
    destroy_bot(all_s->bot8.img.sprite);
}

void destroy_all(window_t *wd, all_sprite_t *all_s, ...)
{
    va_list ap;

    va_start(ap, all_s);
    sfRenderWindow_destroy(wd->window);
    destroy_img(&wd->bg);
    destroy_img(&wd->ammo);
    destroy_img(&wd->win);
    sfMusic_destroy(wd->sound.music);
    sfSoundBuffer_destroy(wd->sound.shoot_buff);
    sfSound_destroy(wd->sound.shoot);
    destroy_all_sprite(all_s);
    sfClock_destroy(va_arg(ap, sfClock *));
    sfClock_destroy(va_arg(ap, sfClock *));
    sfClock_destroy(va_arg(ap, sfClock *));
    sfClock_destroy(va_arg(ap, sfClock *));
    va_end(ap);
}
