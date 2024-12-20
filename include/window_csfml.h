/*
** EPITECH PROJECT, 2024
** macro
** File description:
** csfml
*/

#include <stdbool.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>

#ifndef CSFMLWIND
    #define CSFMLWIND
    #define DUCK_SPEED 3
    #define PLAYER_SPEED 0.1
    #define WD_WIDTH 1200
    #define WD_HEIGTH 800
    #define OUT_WD -500

typedef struct image_s {
    sfTexture *texture;
    sfSprite *sprite;
} image_t;

typedef struct sound_effect_s {
    sfMusic *music;
    sfSound *shoot;
    sfSoundBuffer *shoot_buff;
} sound_effect_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    image_t bg;
    image_t ammo;
    image_t win;
    sound_effect_t sound;
} window_t;

typedef struct moving_sprite_s {
    image_t img;
    sfVector2f position;
    sfIntRect area;
    bool go_rigth;
} moving_sprite_t;

typedef struct all_sprite_t {
    moving_sprite_t player;
    moving_sprite_t visor;
    moving_sprite_t explosion;
    moving_sprite_t smoke;
    moving_sprite_t bot1;
    moving_sprite_t bot2;
    moving_sprite_t bot3;
    moving_sprite_t bot4;
    moving_sprite_t bot5;
    moving_sprite_t bot6;
    moving_sprite_t bot7;
    moving_sprite_t bot8;
} all_sprite_t;


void my_putchar(char c);
int my_putstr(char const *str);
int display_help(void);
image_t init_image(char *img_path);
window_t init_window(unsigned int width, unsigned int heigth,
    unsigned int bps, char *bg_file);
moving_sprite_t init_mv_sprite(char *img_path, int x, int y, sfIntRect area);
all_sprite_t init_all_sprite(moving_sprite_t player, ...);
void destroy_all(window_t *wd, all_sprite_t *all_s, ...);
void animate_duck(sfClock *clock, sfIntRect *area,
    moving_sprite_t *duck, window_t wd);
void display_explosion(window_t *wd, moving_sprite_t *explosion,
    sfIntRect *area);
void change_direction(moving_sprite_t *player, char direction);
void player_movement(moving_sprite_t *player, sfClock *clock);
void handle_event(window_t wd, moving_sprite_t *visor,
    sfEvent event, int *nb_shoot);
bool handle_shoot(window_t *wd, sfEvent event,
    all_sprite_t *all_s, sfClock *clock);
void check_duck_alive(window_t wd, sfClock *explode_clock,
    all_sprite_t *all_s, bool is_alive);
sfVector2f change_vector(float x, float y);
int game_loop(window_t wd, all_sprite_t *all_s, int nb_shoot);
void animate_bots(sfClock *clock, all_sprite_t *all_s, window_t wd);
void draw_mv_sprite(window_t wd, moving_sprite_t mv_sprite);
void draw_duck(window_t wd, all_sprite_t all_s);
void draw_sprite(window_t wd, all_sprite_t all_s, int nb_shoot);
int rand_coord(int min, int max);
void animate_all_duck(window_t wd, all_sprite_t *all_s,
    sfClock *clock, sfClock *clock_bot);
void move_all_bot(all_sprite_t *all_s, sfClock *clock);
void draw_win(window_t *wd, image_t *win, char winner);
void check_game_over(window_t wd, bool is_alive, int *nb_shoot);

    #define ON_TOP(sprite) ((sprite->position.y - 1) < (75) ? 1 : 0)
    #define ON_BOTTOM(sprite) ((sprite->position.y + 111) > (725) ? 1 : 0)
    #define ON_LEDGE_R(sprite) ((sprite->position.x + 111) > (1200) ? 1 : 0)
    #define ON_LEDGE_L(sprite) ((sprite->position.x - 111) < (0) ? 1 : 0)

#endif
