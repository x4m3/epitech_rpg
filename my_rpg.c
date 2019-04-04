/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

int main(void)
{
    env_t env;

    env.core_s.project_name = PROJECT_NAME;
    env.core_s.framerate = DEFAULT_FRAMERATE;
    env.core_s.mode = (sfVideoMode) {RESOLUTION_X, RESOLUTION_Y, BITS_PIXELS};

    env.core_s.actual_status = STATUS_MENU;
    //env.menu_s.actual_status = M_STATUS_MAIN;

    int seed = (int) malloc(1);
    srand((int) &seed);

    reset_var(&env);

    char *texture = "assets/game_ui/btn/about.png";
    create_button(&env, (sfVector3f) {150, 200, 1.0}, texture, "char");
    create_button(&env, (sfVector3f) {500, 500, 1.0}, texture, "coucou");
    create_button(&env, (sfVector3f) {700, 900, 2.0}, texture, "salut");
    create_button(&env, (sfVector3f) {1000, 500, 1.0}, texture, "baaaa");

    printf("%d\n", get_button_by_text(&env, "char"));
    printf("%d\n", get_button_by_text(&env, "coucou"));
    printf("%d\n", get_button_by_text(&env, "salut"));
    printf("%d\n", get_button_by_text(&env, "baaaa"));
    printf("%d\n", get_button_by_text(&env, "hre"));
    set_window(&env);
    game_state(&env);
    destroy(&env);
    return (0);
}