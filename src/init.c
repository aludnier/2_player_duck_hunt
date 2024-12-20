/*
** EPITECH PROJECT, 2024
** init
** File description:
** init struct CSFML
*/

#include "../include/window_csfml.h"
#include <stdbool.h>
#include <stdio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <stdarg.h>

image_t init_image(char *img_path)
{
    image_t img;
    sfTexture *texture = sfTexture_createFromFile(img_path, NULL);
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    img.sprite = sprite;
    img.texture = texture;
    return img;
}

window_t init_window(unsigned int width, unsigned int heigth,
    unsigned int bps, char *bg_file)
{
    window_t wd;
    sfVideoMode v_mode = {width, heigth, bps};
    image_t bg = init_image(bg_file);
    image_t ammo = init_image("img/ammo.png");
    image_t win = init_image("img/WIN.png");
    sfMusic *music = sfMusic_createFromFile("sound_effect/music.ogg");
    sfSound *shoot = sfSound_create();
    sfSoundBuffer *shoot_buff =
        sfSoundBuffer_createFromFile("sound_effect/shoot.wav");

    wd.window = sfRenderWindow_create(v_mode, "Hunter", sfDefaultStyle, NULL);
    wd.bg = bg;
    wd.ammo = ammo;
    wd.win = win;
    wd.sound.music = music;
    sfSound_setBuffer(shoot, shoot_buff);
    wd.sound.shoot = shoot;
    wd.sound.shoot_buff = shoot_buff;
    sfRenderWindow_setMouseCursorVisible(wd.window, false);
    return wd;
}

moving_sprite_t init_mv_sprite(char *img_path, int x, int y, sfIntRect area)
{
    sfVector2f pos = {x, y};
    moving_sprite_t mv_sprite = {
        init_image(img_path), pos, area, true};

    return mv_sprite;
}

moving_sprite_t cp_moving_sprite(moving_sprite_t *sprite, int x, int y)
{
    moving_sprite_t copy;

    copy.img.texture = sprite->img.texture;
    copy.img.sprite = sfSprite_copy(sprite->img.sprite);
    copy.position = change_vector(x, y);
    copy.area = sprite->area;
    copy.go_rigth = sprite->go_rigth;
    return copy;
}

static void add_to_sprite(all_sprite_t *all_sprite,
    moving_sprite_t *player)
{
    all_sprite->bot1 = cp_moving_sprite(player,
        rand_coord(100, 990), rand_coord(100, 590));
    all_sprite->bot2 = cp_moving_sprite(player,
        rand_coord(100, 990), rand_coord(100, 590));
    all_sprite->bot3 = cp_moving_sprite(player,
        rand_coord(100, 990), rand_coord(100, 590));
    all_sprite->bot4 = cp_moving_sprite(player,
        rand_coord(100, 990), rand_coord(100, 590));
    all_sprite->bot5 = cp_moving_sprite(player,
        rand_coord(100, 990), rand_coord(100, 590));
    all_sprite->bot6 = cp_moving_sprite(player,
        rand_coord(100, 990), rand_coord(100, 590));
    all_sprite->bot6 = cp_moving_sprite(player,
        rand_coord(100, 990), rand_coord(100, 590));
    all_sprite->bot7 = cp_moving_sprite(player,
        rand_coord(100, 990), rand_coord(100, 590));
    all_sprite->bot8 = cp_moving_sprite(player,
        rand_coord(100, 990), rand_coord(100, 590));
}

all_sprite_t init_all_sprite(moving_sprite_t player, ...)
{
    va_list ap;
    all_sprite_t all_sprite;

    all_sprite.player = player;
    va_start(ap, player);
    all_sprite.visor = va_arg(ap, moving_sprite_t);
    all_sprite.explosion = va_arg(ap, moving_sprite_t);
    all_sprite.smoke = va_arg(ap, moving_sprite_t);
    add_to_sprite(&all_sprite, &player);
    va_end(ap);
    return all_sprite;
}
