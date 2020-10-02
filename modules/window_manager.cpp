#define WINDOW_LENGTH 800
#define WINDOW_WIDTH 600

#include "../headers/window_manager.h"


ALLEGRO_DISPLAY* create_window(){
    return al_create_display(WINDOW_LENGTH, WINDOW_WIDTH);
}

ALLEGRO_DISPLAY* init(){
    al_init_all();
    ALLEGRO_DISPLAY* screen = create_window();
    al_set_window_title( screen,"Space Crusader");
    return screen;
}