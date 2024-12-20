/*
** EPITECH PROJECT, 2024
** movement.c
** File description:
** handle mov in window
*/

#include "../include/window_csfml.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

void change_direction(moving_sprite_t *player, char direction)
{
    sfVector2f scale = {-1, 1};

    if (player->go_rigth && direction == 'l'){
        player->go_rigth = false;
        player->position.x += 110;
        sfSprite_scale(player->img.sprite, scale);
    }
    if (!player->go_rigth && direction == 'r'){
        player->go_rigth = true;
        player->position.x -= 110;
        sfSprite_scale(player->img.sprite, scale);
    }
}

static void mov_vertically(moving_sprite_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) && player->position.y + 110
        <= WD_HEIGTH - 75){
            player->position.y += PLAYER_SPEED;
        }
        if (sfKeyboard_isKeyPressed(sfKeyZ) && player->position.y - 1 >= 75){
            player->position.y -= PLAYER_SPEED;
        }
}

static void mov_horizontally(moving_sprite_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyD) && player->position.x + 111
        <= WD_WIDTH){
        player->position.x += PLAYER_SPEED;
        change_direction(player, 'r');
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && player->position.x - 1 >= 110){
        player->position.x -= PLAYER_SPEED;
        change_direction(player, 'l');
    }
}

void player_movement(moving_sprite_t *player, sfClock *clock)
{
    sfVector2f scale = {0, 0};

    if (sfClock_getElapsedTime(clock).microseconds >= 1000
            && player->position.x > -42){
        mov_vertically(player);
        mov_horizontally(player);
        sfClock_restart(clock);
    }
}

static void mov_down(moving_sprite_t *bot, char **direction, int index)
{
    if (direction[index] == "down" && !ON_BOTTOM(bot)){
        bot->position.y += DUCK_SPEED;
    }
    if (direction[index] == "down_r"){
        if (!ON_BOTTOM(bot))
            bot->position.y += DUCK_SPEED;
        if (!ON_LEDGE_R(bot))
            bot->position.x += DUCK_SPEED;
        change_direction(bot, 'r');
    }
    if (direction[index] == "down_l"){
        if (!ON_BOTTOM(bot))
            bot->position.y += DUCK_SPEED;
        if (!ON_LEDGE_L(bot))
            bot->position.x -= DUCK_SPEED;
        change_direction(bot, 'l');
    }
}

static void mov_up(moving_sprite_t *bot, char **direction, int index)
{
    if (direction[index] == "up" && !ON_TOP(bot)){
        bot->position.y -= DUCK_SPEED;
    }
    if (direction[index] == "up_r"){
        if (!ON_TOP(bot))
            bot->position.y -= DUCK_SPEED;
        if (!ON_LEDGE_R(bot)){
            bot->position.x += DUCK_SPEED;
            change_direction(bot, 'r');
        }
    }
    if (direction[index] == "up_l"){
        if (!ON_TOP(bot))
            bot->position.y -= DUCK_SPEED;
        if (!ON_LEDGE_L(bot)){
            bot->position.x -= DUCK_SPEED;
            change_direction(bot, 'l');
        }
    }
}

void bot_movement(moving_sprite_t *bot)
{
    int index = rand() % 12;
    char *direction[] =
    {"rigth", "left", "nothing",
    "up", "down", "nothing",
    "up_r", "up_l", "nothing",
    "down_r", "down_l", "nothing"};

    if (direction[index] == "rigth" && !ON_LEDGE_R(bot)){
        bot->position.x += DUCK_SPEED;
        change_direction(bot, 'r');
    }
    if (direction[index] == "left" && !ON_LEDGE_L(bot)){
        bot->position.x -= DUCK_SPEED;
        change_direction(bot, 'l');
    }
    mov_up(bot, direction, index);
    mov_down(bot, direction, index);
}

void move_all_bot(all_sprite_t *all_s, sfClock *clock)
{
    if (sfClock_getElapsedTime(clock).microseconds >= 59000){
        bot_movement(&all_s->bot1);
        bot_movement(&all_s->bot2);
        bot_movement(&all_s->bot3);
        bot_movement(&all_s->bot4);
        bot_movement(&all_s->bot5);
        bot_movement(&all_s->bot6);
        bot_movement(&all_s->bot7);
        bot_movement(&all_s->bot8);
        sfClock_restart(clock);
    }
}
