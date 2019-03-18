/*
** EPITECH PROJECT, 2018
** project
** File description:
** Prototypes of all functions in the program
*/

#include <math.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#define PROJECT_NAME        ("My Defender")
#define DEFAULT_FRAMERATE   (120)

#define RESOLUTION_X        (1920)
#define RESOLUTION_Y        (1080)
#define RESOLUTION_GAME_X   (1393)
#define RESOLUTION_GAME_Y   (1080)
#define BITS_PIXELS         (64)

#define STATUS_MENU         (0)
#define STATUS_PLAY         (1)
#define M_STATUS_MAIN       (0)
#define M_STATUS_SETTINGS   (1)

#define _MUSIC_SCROLL       ("data/sounds/scroll.wav")
#define _MUSIC_CLICK        ("data/sounds/click.wav")
#define _MUSIC_ERROR        ("data/sounds/error.wav")

#define _MENU_BACKGROUND    ("data/menu/menu_background.png")
#define _MENU_ICONS_1       ("data/menu/icons.png")
#define _MENU_ICONS_2       ("data/menu/icons_2.png")
#define _MENU_SKYEFFECTS    ("data/menu/sky_effects.png")
#define _MENU_BTN_1         ("data/menu/btn_left.png")
#define _MENU_BTN_2         ("data/menu/btn_right.png")
#define _MENU_SKY_1         ("data/menu/sky_1.png")
#define _MENU_SKY_2         ("data/menu/sky_2.png")
#define _MENU_FONT          ("data/menu/oetztype.ttf")

#define _GAME_ICONS         ("data/game/icons.png")
#define _GAME_BUTTONS       ("data/game/ui_buttons.png")
#define _GAME_BUTTONS_2     ("data/game/ui_buttons_without_box.png")
#define _GAME_CHAR          ("data/game/characters.png")
#define _GAME_UI            ("data/game/ui.png")
#define _GAME_MAP_1         ("data/map/map_1.png")
#define _GAME_MAP_1_FILE    ("data/map/map_1.txt")

#define MAX_BLOONS          (500)
#define MAX_ALLIES          (500)
#define MAX_POINTS_FILE     (100)

#define COUNT_TYPE_BLOONS   (5)

#define BLOONS_RED          (0)
#define BLOONS_BLUE         (1)
#define BLOONS_PINK         (2)
#define BLOONS_GREEN        (3)
#define BLOONS_BLACK        (4)

#define ALLIES_MONKEY       (0)
#define ALLIES_BOOMRANG     (1)
#define ALLIES_WIZARD       (2)

#define true                (1)
#define false               (0)

#define sfRW_drawSprite(a, b, c) sfRenderWindow_drawSprite(a, b, c)
#define sfRW_drawText(a, b, c) sfRenderWindow_drawText(a, b, c)
#define sfRW_drawCircle(a, b, c) sfRenderWindow_drawCircleShape(a, b, c)
#define sfRW_drawRectangle(a, b, c) sfRenderWindow_drawRectangleShape(a, b, c)
#define sfMouse_getPositionRW(a) sfMouse_getPositionRenderWindow(a)

struct core_s {
    char *project_name;
    sfVideoMode mode;
    sfRenderWindow* window;

    // Events
    sfEvent event;

    // Sounds
    sfMusic *m_scroll;
    sfMusic *m_click;
    sfMusic *m_error;

    // Utils
    int framerate;
    int actual_status;
    int sound_volume;
};
typedef struct core_s core_t;

struct menu_s {
    int actual_status;

    // Background
    sfTexture *t_background[2];
    sfSprite *s_background[2];

    sfTexture *t_sky[2];
    sfSprite *s_sky[2];

    // Buttons textures
    sfTexture *t_button[2];
    sfTexture *t_icons[2];

    // Buttons sprites for menu
    sfSprite *s_button[3];
    sfText *text_button[3];
    sfSprite *s_icons[3];

    // Sprites for settings
    sfSprite *s_set_icon[3];
    sfSprite *s_set_circle[3];

    // Fonts
    sfFont *font;

    // Utils
    sfClock *clock;
};
typedef struct menu_s menu_t;

struct game_s {
    // Textures
    sfTexture *t_ui;
    sfTexture *t_characters;
    sfTexture *t_icons;
    sfTexture *t_map[1];

    // Sprites
    sfSprite *s_ui;
    sfSprite *s_icons;
    sfSprite *s_map[1];
    sfSprite *s_mouse;
    sfCircleShape *s_mouse_circle;

    // Buttons
    sfTexture *t_buttons[2];
    sfSprite *s_button[3];
    sfText *text_price[3];
    char *price[3];

    // Menu (pause & gameover)
    sfRectangleShape *background;
    sfText *text;
    sfSprite *s_menu_circle[2];
    sfSprite *s_menu_icons[2];

    // Clock
    sfClock *c_generate_bloons;

    // Map
    int **map;
    int special_mouse;

    // Player Stats
    sfText *text_level;
    sfText *text_money;

    int is_resume;
    int is_gameover;

    int level;
    int money;
    int health;

    int hit_bloons;
    int bloons_needed[COUNT_TYPE_BLOONS];
};
typedef struct game_s game_t;

struct bloons_s {
    int is_valid;
    int i_pos;
    int type;
    sfVector2f pos;
    float speed;
    int count_movements;

    sfSprite *sprite;
    sfClock *clock;
};
typedef struct bloons_s bloons_t;

struct allies_s {
    int is_valid;

    int type;
    float range;
    sfVector2f pos;

    int bloons_hitted;

    sfSprite *sprite;
    sfCircleShape* circle;
    sfClock *clock;
    sfClock *c_hit;
};
typedef struct allies_s allies_t;

struct env_s {
    core_t core_s;
    menu_t menu_s;
    game_t game_s;
    bloons_t bloons_s[MAX_BLOONS];
    allies_t allies_s[MAX_ALLIES];
};
typedef struct env_s env_t;

typedef struct
{
    int x;
    int y;
    int r;
} sfCirclePos;

// main.c

// src/window/events.c
void events(env_t *env);

// src/window/game.c
void game_state(env_t *env);

// src/window/init.c
void set_window(env_t *env);
void destroy(env_t *env);

// src/window/sounds.c
void init_sounds(env_t *env);
void set_sound_effects(env_t *env);

// src/utils/init_game.c
void reset_var(env_t *env);

// src/menu/draw/background.c
void init_menu_background(env_t *env);
void init_menu_background_2(env_t *env);
void init_menu_background_3(env_t *env);

// src/menu/draw/buttons.c
void init_menu_buttons(env_t *env);
void init_menu_buttons_2(env_t *env);

// src/menu/draw/icons.c
void init_menu_icons(env_t *env);
void init_menu_icons_2(env_t *env);

// src/menu/draw/settings.c
void init_menu_settings(env_t *env);
void init_menu_settings_2(env_t *env);
void init_menu_settings_3(env_t *env);

// src/menu/buttons.c
void check_buttons(env_t *env);
void reset_effects(env_t *env, int exception);
void reset_effects_settings(env_t *env, int exception);
int is_over_button(env_t *env);

// src/menu/events.c
void menu_events(env_t *env);
void on_button_hitted(env_t *env, int button_id, int actual_status);

// src/menu/init.c
void init_menu(env_t *env);
void game_menu(env_t *env);
void game_menu_draw(env_t *env);
void game_menu_draw_main(env_t *env);
void game_menu_draw_settings(env_t *env);

// src/menu/movements.c
void menu_movements(env_t *env);

// src/game/allies/collision.c
int check_collision(env_t *env, int bloons_id, int allies_id);
int collision_circle(sfVector2i point, sfCirclePos circle);

// src/game/allies/init.c
int create_allies(env_t *env, int type, sfVector2f pos);
int get_free_slot_allies(env_t *env);
void delete_allies(env_t *env, int allies_id);

// src/game/allies/move.c
void move_allies(env_t *env);
float get_angle(sfVector2f allies_pos, sfVector2f bloons_pos);

// src/game/allies/set.c
void set_allies(env_t *env, int id);
void draw_allies(env_t *env, int id);
void draw_allies_2(env_t *env, int id, sfIntRect rect_allies);

// src/game/bloons/core.c
int get_bloons_further(env_t *env, int allies_id);

// src/game/bloons/init.c
int create_bloons(env_t *env, int type);
void draw_bloons(env_t *env, int tmp);
int get_free_slot_bloons(env_t *env);
void delete_bloons(env_t *env, int bloons_id);

// src/game/bloons/move.c
void bloons_move(env_t *env);
void bloons_set_position(env_t *env, int id);
void check_index_pos(env_t *env, int id);
int in_range(int value, int min, int max);

// src/game/bloons/set.c
void set_type_bloons(env_t *env, int bloons_id, int type);
sfColor get_color_type_bloons(int type);

// src/game/draw/init.c.c
void game_draw_init(env_t *env);

// src/game/draw/buttons.c
void game_draw_buttons(env_t *env);
void game_draw_buttons_1(env_t *env);
void game_draw_buttons_2(env_t *env);

// src/game/draw/mouse.c
void game_draw_mouse(env_t *env);

// src/game/draw/text.c
void draw_game_text(env_t *env);

// src/game/draw/menu.c
void pause_draw(env_t *env);
void pause_draw_text(env_t *env);
void pause_draw_background(env_t *env);
void pause_draw_circle(env_t *env);
void pause_draw_icons(env_t *env);

// src/game/draw/ui.c
void game_draw_ui(env_t *env);

// src/game/menu/init.c
void display_menu(env_t *env, char *name);

// src/game/menu/buttons.c
void check_g_menu_buttons(env_t *env);
void reset_btn_g_menu_effects(env_t *env, int exception);
int is_over_g_menu_button(env_t *env);

// src/game/buttons.c
void check_game_buttons(env_t *env);
void reset_btn_game_effects(env_t *env, int exception);
int is_over_game_button(env_t *env);
void refresh_special_mouse(env_t *env);

// src/game/events.c
void game_events(env_t *env);
void on_game_button_hitted(env_t *env, int button_id);
void on_g_menu_button_hitted(env_t *env, int button_id);
void on_game_allies_drop(env_t *env);

// src/game/gameplay.c
void generate_level_bloons(env_t *env, int max_bloons);
void generate_bloons(env_t *env);
int get_type_free_bloons(env_t *env);
int check_is_free_bloons(env_t *env);

// src/game/hit.c
void check_hit(env_t *env);
void check_hit_allies(env_t *env, int allies_id);
void bloons_hit(env_t *env, int bloons_id, int allies_id);

// src/game/init.c
void init_game(env_t *env);
void init_game_stats(env_t *env);
void init_map(env_t *env);

// src/game/play.c
void game_play(env_t *env);
void game_play_draw(env_t *env);
void game_play_draw_ui(env_t *env);
void draw_allies_circle(env_t *env, int allies_id);

// src/game/stats.c
int get_money(env_t *env);
void set_money(env_t *env, int value);
int get_level(env_t *env);
void set_level(env_t *env, int value);