#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

ALLEGRO_SAMPLE *musique_level_1;

void load_musique()
{
    musique_level_1 = al_load_sample("musique/Distant2.ogg");
}

void play_musique(ALLEGRO_SAMPLE *music)
{
    al_play_sample(music, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
}
