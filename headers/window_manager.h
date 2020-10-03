#ifndef window_manager_h
#define window_manager_h

#include <allegro.h>
#include <allegro_font.h>
#include <allegro_image.h>
#include <allegro_audio.h>
#include <allegro_acodec.h>

ALLEGRO_DISPLAY* create_window();
ALLEGRO_DISPLAY* init();
void destroy_all(ALLEGRO_BITMAP *statek, ALLEGRO_BITMAP *tlo, ALLEGRO_DISPLAY* screen);
void al_init_all();

#endif