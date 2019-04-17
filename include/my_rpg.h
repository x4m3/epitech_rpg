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

#define PROJECT_NAME        ("Wardo Shark")
#define DEFAULT_FRAMERATE   (100)

#define RESOLUTION_X        (1920)
#define RESOLUTION_Y        (1080)
#define BITS_PIXELS         (64)

#define STATUS_MENU         (0)
#define M_STATUS_MAIN       (0)
#define M_STATUS_SETTINGS   (1)
#define M_STATUS_HOWTO      (2)

#define STATUS_PLAY         (3)
#define G_STATUS_PLAY       (0)

#define MAX_BUTTONS         (50)

#define MAP_MAX_LINES       (200)

#define HELP_FILE           ("data/help.txt")

#define FONT_OETZ           ("assets/oetztype.ttf")

#define GAME_ASSETS_MAP     ("assets/64x64_map_tile.png")
#define GAME_CHARACTER      ("assets/character_sprite.png")

#define MENU_LOGO           ("assets/game_ui/menu/logo.png")
#define MENU_BACKGROUND     ("assets/background.png")

#define BUTTON_HOWTO        ("assets/game_ui/btn/about.png")
#define BUTTON_SETTINGS     ("assets/game_ui/btn/settings.png")
#define BUTTON_PLAY         ("assets/game_ui/btn/play.png")
#define BUTTON_ON           ("assets/game_ui/settings/96.png")
#define BUTTON_OFF          ("assets/game_ui/settings/95.png")
#define BUTTON_CLOSE        ("assets/game_ui/settings/close_2.png")
#define BUTTON_EXIT         ("assets/game_ui/btn/close.png")

#define M_SETTINGS_ICON     ("assets/game_ui/settings/92.png")
#define M_SETTINGS_BOX0     ("assets/game_ui/settings/bg.png")
#define M_SETTINGS_BOX1     ("assets/game_ui/settings/table.png")

#define M_HOWTO_ICON        ("assets/game_ui/how_to/icon.png")


#define ROTATION_DOWN       (0)
#define ROTATION_LEFT       (1)
#define ROTATION_RIGHT      (2)
#define ROTATION_UP         (3)

#define _SOUNDS_EFFECTS      (1)
#define _SOUNDS_CLICK        ("assets/sounds/click.wav")

struct core_s {
    char *project_name;
    sfVideoMode mode;
    sfRenderWindow* window;

    // Events
    sfEvent event;

    // Settings
    sfMusic *m_effects[_SOUNDS_EFFECTS];
    sfMusic *m_music;

    // Utils
    int framerate;
    int actual_status;

    // Fonts
    sfFont *f_oetz;

    // Delta time
    sfClock *clock;
    float delta_time;
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

struct game_s {
    int actual_status;

    // Character
    sfTexture *t_character;
    sfSprite *s_character;
    sfVector2f p_character;
    int rotation;
    int tmp_animation;

    // View
    sfView *view;
    sfVector2f p_view;

    // Map
    sfTexture *t_map;
    sfSprite ***s_map;
    sfVideoMode map_size;
};
typedef struct game_s game_t;

struct menu_s {
    int actual_status;

    // Logo
    sfTexture *t_logo;
    sfSprite *s_logo;

    // Background
    sfTexture *t_background;
    sfSprite *s_background;

    // Settings
    sfTexture *t_icon;
    sfTexture *t_box[2];
    sfSprite *s_icon;
    sfSprite *s_box[2];
    sfText *txt_sets[2];
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
    game_t game_s;
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

// src/game/draw/character.c
void game_draw_character(env_t *env);

// src/game/draw/game_ui.c
void game_draw_ui(env_t *env);

// src/game/draw/view.c
void game_draw_view(env_t *env);

// src/game/character.c
void set_character_rotation(env_t *env, int rotation);
void set_character_animation(env_t *env);

// src/game/events.c
void game_events(env_t *env);

// src/game/game.c
void init_game(env_t *env);
void game_play_draw(env_t *env);

// src/game/init.c
void game_play(env_t *env);

// src/map/init.c
int open_map(env_t *env, int argc, char *argv[]);

// src/menu/draw/how_to.c
void draw_menu_howto(env_t *env);

// src/menu/draw/menu_ui.c
void init_menu_ui(env_t *env);

// src/menu/draw/settings.c
void draw_menu_settings(env_t *env);

// src/menu/events.c
void on_menu_button_hitted(env_t *env, int button_id);

// src/menu/how_to.c
void init_menu_howto(env_t *env);
void game_menu_draw_howto(env_t *env);

// src/menu/init.c
void game_menu(env_t *env);

// src/menu/main.c
void init_menu(env_t *env);
void game_menu_draw(env_t *env);

// src/menu/settings.c
void init_menu_settings(env_t *env);
void game_menu_draw_settings(env_t *env);

// src/utils/help/display.c
void display_help(char *argv[]);

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
void destroy_all_buttons(env_t *env);

// src/window/events.c
void events(env_t *env);

// src/window/fonts.c
void init_fonts(env_t *env);

// src/window/game.c
void game_state(env_t *env);

// src/window/init.c
void set_window(env_t *env);
void destroy(env_t *env);
void reset_var(env_t *env);

// src/window/sounds.c
void init_sounds(env_t *env);
void set_sounds_music(env_t *env);
void set_sounds_effects(env_t *env);
float get_sounds_music(env_t *env);
float get_sounds_effects(env_t *env);