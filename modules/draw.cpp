#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <enemy.h>

ALLEGRO_BITMAP *statek, *tlo, *pocisk, *tarcza, *tarczaX, *enemy_missle, *dead_ship, *ayyylien, *ayyylienX, *game_over, *statek_un;
ALLEGRO_BITMAP *menu_back, *new_game_g, *load_game_g, *exit_g, *border, *mission_end, *end_screen, *tlo2, *tlo3, *high_scores_g, *high_scores_back;
ALLEGRO_BITMAP *yyh, *yyhX;
ALLEGRO_FONT *font8;
int back_y[2]={-600, -1800};

void load_graph()
{
    statek = al_load_bitmap("graph/statek/podst.png");
    statek_un = al_load_bitmap("graph/statek/untouchable.png");
    dead_ship = al_load_bitmap("graph/statek/wybuch.png");
    tlo = al_load_bitmap("graph/tlo/Testowanie3.png");
    tlo2 = al_load_bitmap("graph/tlo/Testowanie4.png");
    tlo3 = al_load_bitmap("graph/tlo/Testowanie5.png");
    pocisk = al_load_bitmap("graph/statek/pocisk.png");
    tarcza = al_load_bitmap("graph/przeciwnicy/tarcza.png");
    tarczaX = al_load_bitmap("graph/przeciwnicy/tarcza-X.png");
    ayyylien = al_load_bitmap("graph/przeciwnicy/kosmita.png");
    ayyylienX = al_load_bitmap("graph/przeciwnicy/kosmita-X.png");
    yyh = al_load_bitmap("graph/przeciwnicy/yhhhhh.png");
    yyhX = al_load_bitmap("graph/przeciwnicy/yhhhhhX.png");
    enemy_missle = al_load_bitmap("graph/przeciwnicy/amunicja/pocisk.png");
    game_over = al_load_bitmap("graph/menu/game_over.png");
    menu_back = al_load_bitmap("graph/menu/tlo.png");
    new_game_g = al_load_bitmap("graph/menu/nowa_gra.png");
    load_game_g = al_load_bitmap("graph/menu/wczytaj_gre.png");
    high_scores_g = al_load_bitmap("graph/menu/najlepsze_wyniki.png");
    high_scores_back = al_load_bitmap("graph/menu/wyniki.png");
    exit_g = al_load_bitmap("graph/menu/wyjdz.png");
    border = al_load_bitmap("graph/menu/ramka2.png");
    mission_end = al_load_bitmap("graph/menu/misja_zakonczona.png");
    end_screen = al_load_bitmap("graph/menu/koniec_gry.png");
    font8 = al_create_builtin_font();
}

void move_background()
{
    for (int i = 0 ; i < 2 ; i++)
            {
                back_y[i] += 1;
                if (back_y[i] == 600) back_y[i] = -1800;
            }
}

void draw_enemies(ALLEGRO_BITMAP *enemy, ALLEGRO_BITMAP *dead_enemy, int how_many)
{
    for (int i = 0; i < how_many; i++)
    {
        if (enemy_exists[i] == true) al_draw_bitmap (enemy, enemy_x[i], enemy_y[i], 0);
        if (enemy_is_dead[i] == true) al_draw_bitmap (dead_enemy, enemy_x[i], enemy_y[i], 0);
    }
}

void draw_missles(ALLEGRO_BITMAP *missle, int how_many)
{
    for (int i = 0; i < how_many; i++)
    {
        if (enemy_missles[i] == true)
            al_draw_bitmap (missle, enemy_missle_x[i], enemy_missle_y[i], 0);
    }
}

void draw_level(ALLEGRO_BITMAP *enemy_1, ALLEGRO_BITMAP *enemy_1X, ALLEGRO_BITMAP *enemy_2, ALLEGRO_BITMAP *enemy_2X, ALLEGRO_BITMAP *background, int how_many)
{
        al_draw_bitmap (background,0,back_y[0],0);
        al_draw_bitmap (background,0,back_y[1],0);
        for (int i = 0 ; i<3 ; i++)
            if (projectile[i] == true) al_draw_bitmap (pocisk, shot_x[i], shot_y[i], 0);
        if (patterns[0] == true)
        {
            draw_enemies(enemy_1, enemy_1X, how_many);
            draw_missles(enemy_missle, how_many);
        }
        if (patterns[1] == true)
        {
            draw_enemies(enemy_2, enemy_2X, how_many);
            draw_missles(enemy_missle, how_many);
        }
        if (patterns[2] == true)
        {
            draw_enemies(enemy_1, enemy_1X, how_many);
            draw_missles(enemy_missle, how_many);
        }
        if ((player_dead == false)&&(untouchable == false))
            al_draw_bitmap (statek,player_x,player_y,0);
        if (untouchable == true)
            al_draw_bitmap (statek_un,player_x,player_y,0);
        al_draw_textf(font8,al_map_rgb(255,255,0), 10, 10, 0,"LIVES: %d, x=%3d , y=%3d", lives, player_x, player_y);
        al_draw_textf(font8,al_map_rgb(255,255,0), 700, 10, 0,"SCORE=%6d", score);
}


