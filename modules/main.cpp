#include <allegro.h>
#include <allegro_font.h>
#include <allegro_image.h>
#include <allegro_audio.h>
#include <allegro_acodec.h>
#include <cmath>
#include "../headers/engine.h"
#include "../headers/enemy.h"
#include "../headers/levels.h"
#include "../headers/file.h"
#include "../headers/draw.h"
#include "../headers/musique.h"
#include "../headers/window_manager.h"

int main()
{
    ALLEGRO_DISPLAY *screen = init();
    double time = 0, 
        pattern_time[2], 
        time2, 
        menu_time = al_get_time();
    bool exit;
    game_state state = main_menu;

    while(!((al_key_down(&keyboard, ALLEGRO_KEY_ESCAPE))||(exit == true)))
    {
        switch (state)
        {
        case main_menu:
            menu_loop(&menu_time, &exit, &state);
            break;
        case game:
            game_loop(&time, pattern_time, &time2);
            break;
        }

    }

    destroy_all(musique_level_1, ship, background, screen);
    return 0;
}
