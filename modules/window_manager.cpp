#define WINDOW_LENGTH 800
#define WINDOW_WIDTH 600

#include "../headers/window_manager.h"

ALLEGRO_DISPLAY* create_window(){
    return al_create_display(WINDOW_LENGTH, WINDOW_WIDTH);
}

ALLEGRO_DISPLAY* init(){
    al_init_all();
    ALLEGRO_DISPLAY* screen = create_window();
    al_set_window_title(screen,"Space Crusader");
    return screen;
}

void destroy_all(ALLEGRO_SAMPLE *music, ALLEGRO_BITMAP *ship, ALLEGRO_BITMAP *background, ALLEGRO_DISPLAY* screen)
{
    al_destroy_sample(music);
    al_destroy_bitmap(ship);
    al_destroy_bitmap(background);
    al_destroy_display(screen);
}

void al_init_all()
{
    al_init();
    al_install_keyboard();
    al_init_font_addon();
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);
}