#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <al_init_all.h>
#include <draw.h>
#include <cmath>
#include <engine.h>
#include <enemy.h>
#include <levels.h>
#include <file.h>

int main()
{
    al_init_all();
    ALLEGRO_DISPLAY *screen = al_create_display(screen_l, screen_w);
    al_set_window_title( screen,"Space Crusader");
    load_graph();
    load_musique();
    al_set_target_bitmap(al_get_backbuffer(screen));
    double czas = 0, pattern_time[2], znowu_czas, menu_time = al_get_time();
    clear_patterns();
    bool exit;
    while(!((al_key_down(&klawiatura, ALLEGRO_KEY_ESCAPE))||(exit == true)))
    {
        switch (menu_state)
        {
        case 1:
            menu_loop(&menu_time, &exit);
            break;
        case 2:
            game_loop(&czas, pattern_time, &znowu_czas);
            break;
        }

    }

    destroy_all(musique_level_1, statek, tlo, screen);
    return 0;
}
