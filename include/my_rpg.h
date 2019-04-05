/*
** EPITECH PROJECT, 2018
** project
** File description:
** Prototypes of all functions in the program
*/

#pragma once

#include <math.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#define true                (1)
#define false               (0)
#define bool                (int)

#define PROJECT_NAME        ("My Defender")
#define DEFAULT_FRAMERATE   (120)

#define RESOLUTION_X        (1920)
#define RESOLUTION_Y        (1080)
#define BITS_PIXELS         (64)

#define MENU_SETTINGS       ("assets/.../")

#define STATUS_MENU         (0)
#define M_STATUS_MAIN       (0)
#define M_STATUS_SETTINGS   (1)

#define MAX_BUTTONS         (50)

#define BUTTON_HOWTO        ("assets/game_ui/btn/about.png")
#define BUTTON_SETTINGS     ("assets/game_ui/btn/settings.png")
#define BUTTON_PLAY         ("assets/game_ui/btn/play.png")

struct core_s {
    char *project_name;
    sfVideoMode mode;
    sfRenderWindow* window;

    // Events
    sfEvent event;

    // Utils
    int framerate;
    int actual_status;
};
typedef struct core_s core_t;

struct buttons_s {
    int is_valid;

    char *text;
    sfVector2f pos;
    float scale;

    sfTexture *texture;
    sfSprite *sprite;
};
typedef struct buttons_s buttons_t;

struct menu_s {
    int actual_status;
};
typedef struct menu_s menu_t;

struct character_s
{
    int life;
    int mana;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
};
typedef struct character_s character_t;

struct env_s {
    core_t core_s;
    menu_t menu_s;
    buttons_t buttons_s[MAX_BUTTONS];
    character_t character_s;
};
typedef struct env_s env_t;

typedef enum pos
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    OFF
}pos_t;

// src/menu/init.c
void game_menu(env_t *env);

// src/window/buttons/animation.c
void check_buttons(env_t *env);
void reset_effects(env_t *env, int exception);

// src/window/buttons/display.c
void display_buttons(env_t *env);

// src/window/buttons/event.c
void check_buttons_click(env_t *env);
void on_button_hitted(env_t *env, int button_id);
int is_over_button(env_t *env);
int get_button_by_text(env_t *env, char *text);
int get_free_slot_buttons(env_t *env);

// src/window/buttons/init.c
int create_button(env_t *env, sfVector3f pos, char *texture, char *text);
void destroy_button(env_t *env, int button_id);

// src/window/events.c
void events(env_t *env);

// src/window/game.c
void game_state(env_t *env);

// src/window/init.c
void set_window(env_t *env);
void destroy(env_t *env);
void reset_var(env_t *env);