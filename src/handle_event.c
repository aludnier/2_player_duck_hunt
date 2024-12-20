/*
** EPITECH PROJECT, 2024
** handle event
** File description:
** handle diff event
*/

#include "../include/window_csfml.h"
#include <stdbool.h>
#include <stdio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

void handle_event(window_t wd, moving_sprite_t *visor,
    sfEvent event, int *nb_shoot)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wd.window);
    if (event.type == sfEvtMouseMoved){
        visor->position.x = sfMouse_getPositionRenderWindow(wd.window).x - 50;
        visor->position.y = sfMouse_getPositionRenderWindow(wd.window).y - 50;
    }
    if (event.type == sfEvtMouseButtonPressed){
        if (sfMouse_isButtonPressed(sfMouseLeft) && *nb_shoot > 0){
            sfSound_setVolume(wd.sound.shoot, 50);
            sfSound_play(wd.sound.shoot);
            *nb_shoot -= 1;
        }
    }
}

bool is_between(int left, int nb, int rigth)
{
    if (nb > left && nb < rigth)
        return true;
    return false;
}

bool is_on_hitbox(moving_sprite_t player, int mx, int my)
{
    int x_player = player.position.x;
    int y_player = player.position.y;

    if (player.go_rigth){
        if (is_between(x_player, mx, x_player + 110) &&
            is_between(y_player, my, y_player + 110))
            return true;
    } else {
        if (is_between(x_player - 110, mx, x_player) &&
            is_between(y_player, my, y_player + 110))
            return true;
    }
    return false;
}

static void check_bot_hitbox(all_sprite_t *all_s, int Mouse_x,
    int Mouse_y)
{
    if (is_on_hitbox(all_s->bot1, Mouse_x, Mouse_y))
        all_s->bot1.position.x = OUT_WD;
    if (is_on_hitbox(all_s->bot2, Mouse_x, Mouse_y))
        all_s->bot2.position.x = OUT_WD;
    if (is_on_hitbox(all_s->bot3, Mouse_x, Mouse_y))
        all_s->bot3.position.x = OUT_WD;
    if (is_on_hitbox(all_s->bot4, Mouse_x, Mouse_y))
        all_s->bot4.position.x = OUT_WD;
    if (is_on_hitbox(all_s->bot5, Mouse_x, Mouse_y))
        all_s->bot5.position.x = OUT_WD;
    if (is_on_hitbox(all_s->bot6, Mouse_x, Mouse_y))
        all_s->bot6.position.x = OUT_WD;
    if (is_on_hitbox(all_s->bot7, Mouse_x, Mouse_y))
        all_s->bot7.position.x = OUT_WD;
    if (is_on_hitbox(all_s->bot8, Mouse_x, Mouse_y))
        all_s->bot8.position.x = OUT_WD;
}

bool check_hitbox(all_sprite_t *all_s, sfClock *clock)
{
    int Mouse_x = all_s->visor.position.x + 50;
    int Mouse_y = all_s->visor.position.y + 50;

    if (is_on_hitbox(all_s->player, Mouse_x, Mouse_y)){
        all_s->player.position.x = OUT_WD;
    } else {
        check_bot_hitbox(all_s, Mouse_x, Mouse_y);
    }
}

bool handle_shoot(window_t *wd, sfEvent event,
    all_sprite_t *all_s, sfClock *clock)
{
    if (event.type == sfEvtMouseButtonPressed){
        if (sfMouse_isButtonPressed(sfMouseLeft)){
            check_hitbox(all_s, clock);
        }
    }
    if (all_s->player.position.x == OUT_WD)
        return false;
    return true;
}
