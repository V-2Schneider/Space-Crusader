#include <allegro.h>
#include <allegro_font.h>
#include <allegro_image.h>
#include <allegro_audio.h>
#include <allegro_acodec.h>

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

void destroy_all(ALLEGRO_SAMPLE *music, ALLEGRO_BITMAP *ship, ALLEGRO_BITMAP *background, ALLEGRO_DISPLAY *windows)
{
    al_destroy_sample(music);
    al_destroy_bitmap(ship);
    al_destroy_bitmap(background);
    al_destroy_display(windows);
}
