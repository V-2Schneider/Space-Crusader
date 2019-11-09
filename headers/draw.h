#ifndef draw_h
#define draw_h
#include <allegro5/allegro_font.h>

extern ALLEGRO_BITMAP *statek, *tlo, *pocisk, *tarcza, *tarczaX, *enemy_missle, *dead_ship, *ayyylien, *ayyylienX, *game_over, *statek_un;
extern ALLEGRO_BITMAP *menu_back, *new_game_g, *load_game_g, *exit_g, *border, *mission_end, *end_screen, *tlo2, *tlo3, *high_scores_g, *high_scores_back;
extern ALLEGRO_BITMAP *yyh, *yyhX;;
extern ALLEGRO_FONT *font8;
extern int back_y[2];

void load_graph();
void move_background();
void draw_enemies(ALLEGRO_BITMAP *enemy, ALLEGRO_BITMAP *dead_enemy, int how_many);
void draw_missles(ALLEGRO_BITMAP *missle, int how_many);
void draw_level(ALLEGRO_BITMAP *enemy_1, ALLEGRO_BITMAP *enemy_1X, ALLEGRO_BITMAP *enemy_2, ALLEGRO_BITMAP *enemy_2X, ALLEGRO_BITMAP *background, int how_many);

#endif

