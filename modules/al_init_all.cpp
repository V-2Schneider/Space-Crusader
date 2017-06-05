#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

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

void destroy_all(ALLEGRO_SAMPLE *music, ALLEGRO_BITMAP *statek, ALLEGRO_BITMAP *tlo, ALLEGRO_DISPLAY *okno)
{
    al_destroy_sample(music);
    al_destroy_bitmap(statek);
    al_destroy_bitmap(tlo);
    al_destroy_display(okno);
}
