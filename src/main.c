/*
** EPITECH PROJECT, 2024
** main
** File description:
** my_hunter
*/

#include "../include/window_csfml.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

void re_scale(window_t *wd, all_sprite_t *all_s)
{
    sfVector2f wd_scale = {1.5, 1.5};
    sfVector2f scale = {0.5, 0.5};

    sfSprite_scale(wd->bg.sprite, wd_scale);
    sfSprite_scale(all_s->explosion.img.sprite, scale);
    sfSprite_scale(all_s->smoke.img.sprite, scale);
}

int lunch_game(void)
{
    window_t wd = init_window(WD_WIDTH, WD_HEIGTH, 32, "img/bg.png");
    sfIntRect e_area = {100, 0, 160, 223};
    sfIntRect smoke_area = {0, 0, 160, 223};
    sfIntRect area = {0, 0, 110, 110};
    sfIntRect v_area = {0, 0, 100, 100};
    moving_sprite_t visor = init_mv_sprite("img/visor.png", OUT_WD, 0, v_area);
    moving_sprite_t player = init_mv_sprite("img/duck.png",
        rand_coord(100, 990), rand_coord(100, 590), area);
    moving_sprite_t explode = init_mv_sprite("img/explode.png", 0, 0, e_area);
    moving_sprite_t smoke = init_mv_sprite("img/smoke.png", 0, 0, smoke_area);
    sfVector2f wd_scale = {1.5, 1.5};
    sfVector2f scale = {0.5, 0.5};
    all_sprite_t all_sprite;

    sfSprite_scale(player.img.sprite, scale);
    all_sprite = init_all_sprite(player, visor, explode, smoke);
    re_scale(&wd, &all_sprite);
    sfRenderWindow_setFramerateLimit(wd.window, 500);
    return game_loop(wd, &all_sprite, 3);
}

int main(int ac, char **av)
{
    if (ac == 1){
        srand(time(NULL));
        return lunch_game();
    } else if (ac == 2 && av[1][1] == 'h') {
        return display_help();
    }
    return 84;
}
