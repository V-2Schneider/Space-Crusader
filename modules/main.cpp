#include <allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "../headers/al_init_all.h"
#include <cmath>
#include "../headers/engine.h"
#include "../headers/enemy.h"
#include "../headers/levels.h"
#include "../headers/file.h"
#include "../headers/draw.h"
#include "../headers/musique.h"

int main()
{
    al_init_all();
    ALLEGRO_DISPLAY *screen = al_create_display(screen_l, screen_w);
    al_set_window_title( screen,"Space Crusader");
    load_graph();
    load_musique();
    al_set_target_bitmap(al_get_backbuffer(screen));
    double time = 0, pattern_time[2], time2, menu_time = al_get_time();
    clear_patterns();
    bool exit;
    while(!((al_key_down(&keyboard, ALLEGRO_KEY_ESCAPE))||(exit == true)))
    {
        switch (menu_state)
        {
        case 1:
            menu_loop(&menu_time, &exit);
            break;
        case 2:
            game_loop(&time, pattern_time, &time2);
            break;
        }

    }

    destroy_all(musique_level_1, ship, background, screen);
    return 0;
}
