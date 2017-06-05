#include <allegro5/allegro.h>
#include <levels.h>
#include <enemy.h>
#include <engine.h>
#include <draw.h>
#include <file.h>

int menu_state = 1, pattern = 1;
int menu_selection = 1, menu_y, continue_menu = 1, level_number = 0, how_many;
bool level_1_done = false, saved;

void level_1(double *czas, double pattern_time[2], double *znowu_czas)
{
    if (*czas == 0)
    {
        *czas = al_get_time();
        pattern_time[0] = al_get_time();
        pattern_time[1] = al_get_time();
        *znowu_czas = al_get_time();
        level_number = 1;
        saved = false;
    }
    if (lives != 0)
    {
        if ( al_get_time() > *czas + 0.01)
        {
            gameplay_fly();
            projectiles();
            respawn();
            switch (pattern)
            {
            case 1:
                how_many = 5;
                pattern_1(how_many, &pattern_time[0], 1);
                check_hitbox(how_many, 25);
                check_life(how_many);
                break;

            case 2:
                how_many = 6;
                patterns[0] = false;
                pattern_2(how_many, &pattern_time[1], 2);
                check_hitbox(how_many, 40);
                check_life(how_many);
                break;

            case 3:
                how_many = 5;
                patterns[1] = false;
                pattern_3(how_many, &pattern_time[0], 3);
                check_hitbox(how_many, 30);
                check_life(how_many);
                break;

            }
            if (*znowu_czas + 6.0 < al_get_time())
                pattern = 2;
            if (*znowu_czas + 13.0 < al_get_time())
                pattern = 3;
            if (*znowu_czas + 20.0 < al_get_time())
            {
                ending = true;
                player_y-=5;
                if (player_y <= -20)
                {
                    ending = false;
                    level_1_done = true;
                }

            }

            move_background();
            *czas = al_get_time();
        }

    }
    if (lives == 0)
        game_state = 9;
    if (level_1_done == true)
    {
        game_state = 10;
    }

}

void level_2(double *czas, double pattern_time[2], double *znowu_czas)
{
    if (*czas == 0)
    {
        *czas = al_get_time();
        pattern_time[0] = al_get_time();
        pattern_time[1] = al_get_time();
        *znowu_czas = al_get_time();
        level_number = 2;
        saved = false;
    }
    if (lives != 0)
    {
        if ( al_get_time() > *czas + 0.01)
        {
            gameplay_fly();
            projectiles();
            respawn();
            switch (pattern)
            {
            case 1:
                how_many = 5;
                pattern_1(how_many, &pattern_time[0], 1);
                check_hitbox(how_many, 25);
                check_life(how_many);
                break;

            case 2:
                how_many = 8;
                patterns[0] = false;
                pattern_2(how_many, &pattern_time[1], 2);
                check_hitbox(how_many, 60);
                check_life(how_many);
                break;

            }
            if (*znowu_czas + 7.0 < al_get_time())
                pattern = 2;
            if (*znowu_czas + 11.0 < al_get_time())
            {
                ending = true;
                player_y-=5;
                if (player_y <= -20)
                {
                    ending = false;
                    level_1_done = true;
                }

            }

            move_background();
            *czas = al_get_time();
        }

    }
    if (lives == 0)
        game_state = 9;
    if (level_1_done == true)
    {
        game_state = 10;
    }

}

void level_3(double *czas, double pattern_time[2], double *znowu_czas)
{
    if (*czas == 0)
    {
        *czas = al_get_time();
        pattern_time[0] = al_get_time();
        pattern_time[1] = al_get_time();
        *znowu_czas = al_get_time();
        level_number = 3;
        saved = false;
    }
    if (lives != 0)
    {
        if ( al_get_time() > *czas + 0.01)
        {
            gameplay_fly();
            projectiles();
            respawn();
            switch (pattern)
            {
            case 1:
                how_many = 5;
                pattern_1(how_many, &pattern_time[0], 1);
                check_hitbox(how_many, 25);
                check_life(how_many);
                break;

            case 2:
                how_many = 10;
                patterns[0] = false;
                pattern_2(how_many, &pattern_time[1], 2);
                check_hitbox(how_many, 70);
                check_life(how_many);
                break;

            }
            if (*znowu_czas + 7.0 < al_get_time())
                pattern = 2;
            if (*znowu_czas + 11.0 < al_get_time())
            {
                ending = true;
                player_y-=5;
                if (player_y <= -20)
                {
                    ending = false;
                    level_1_done = true;
                }

            }

            move_background();
            *czas = al_get_time();
        }

    }
    if (lives == 0)
        game_state = 9;
    if (level_1_done == true)
    {
        game_state = 11;
    }

}


void game_loop(double *czas, double pattern_time[2], double *znowu_czas)
{
        al_get_keyboard_state(&klawiatura);
        switch (game_state)
        {
        case 1:
            level_1(czas, pattern_time, znowu_czas);
            draw_level(tarcza, tarczaX, ayyylien, ayyylienX, tlo, how_many);
            al_flip_display();
            al_rest(0.001);
            break;
        case 2:
            level_2(czas, pattern_time, znowu_czas);
            draw_level(ayyylien, ayyylienX, yyh, yyhX, tlo2, how_many);
            al_flip_display();
            al_rest(0.001);
            break;
        case 3:
            level_3(czas, pattern_time, znowu_czas);
            draw_level(yyh, yyhX, yyh, yyhX, tlo3, how_many);
            al_flip_display();
            al_rest(0.001);
            break;
        case 9:
            al_draw_bitmap (game_over,0,0,0);
            al_flip_display();
            al_rest(0.001);
            break;
        case 10:
            al_draw_bitmap (mission_end,0,0,0);
            al_draw_textf(font8,al_map_rgb(255,255,0), 550, 10, 0,"WYNIK=%6d", score);
            al_draw_textf(font8,al_map_rgb(255,255,0), 550, 30, 0,"ZESTRZELENI PRZECIWNICY=%6d", shot_enemies);
            switch(continue_menu)
            {
            case 1:
                al_draw_textf(font8,al_map_rgb(255,255,0), 550, 50, 0,"CZY CHCESZ ZAPISAC GRE?");
                al_draw_textf(font8,al_map_rgb(255,0,0), 550, 70, 0,"TAK");
                al_draw_textf(font8,al_map_rgb(255,255,0), 600, 70, 0,"NIE");
                if (al_key_down(&klawiatura, ALLEGRO_KEY_RIGHT)) continue_menu = 2;
                if(al_key_down(&klawiatura, ALLEGRO_KEY_ENTER)) continue_menu = 3;
                break;
            case 2:
                al_draw_textf(font8,al_map_rgb(255,255,0), 550, 50, 0,"CZY CHCESZ ZAPISAC GRE?");
                al_draw_textf(font8,al_map_rgb(255,255,0), 550, 70, 0,"TAK");
                al_draw_textf(font8,al_map_rgb(255,0,0), 600, 70, 0,"NIE");
                if (al_key_down(&klawiatura, ALLEGRO_KEY_LEFT)) continue_menu = 1;
                if(al_key_down(&klawiatura, ALLEGRO_KEY_ENTER)) continue_menu = 4;
                break;
            case 3:
                if (saved == false)
                {
                    save(&level_number);
                    saved = true;
                }
                al_draw_textf(font8,al_map_rgb(255,255,0), 550, 50, 0,"ZAPISANO");
                al_draw_textf(font8,al_map_rgb(255,255,0), 550, 70, 0,"WCISNIJ SPACJE ABY KONTYNUOWAC");
                if(al_key_down(&klawiatura, ALLEGRO_KEY_SPACE))
                {
                    clear_patterns();
                    pattern = 1;
                    level_1_done = false;
                    *czas = 0;
                    player_x = 360;
                    player_y = 530;
                    continue_menu = 1;
                    game_state = level_number+1;
                }
                break;
            case 4:
                al_draw_textf(font8,al_map_rgb(255,255,0), 550, 50, 0,"WCISNIJ SPACJE ABY KONTYNUOWAC");
                if(al_key_down(&klawiatura, ALLEGRO_KEY_SPACE))
                {
                    clear_patterns();
                    pattern = 1;
                    level_1_done = false;
                    *czas = 0;
                    player_x = 360;
                    player_y = 530;
                    game_state = level_number+1;
                }
                break;
            }
            al_flip_display();
            al_rest(0.001);
            break;
        case 11:
            al_draw_bitmap (end_screen,0,0,0);
            al_flip_display();
            al_rest(0.001);
            break;
        }

}

void menu_loop(double *menu_time, bool *exit)
{

        if (al_get_time() > *menu_time + 0.01)
        {
            al_get_keyboard_state(&klawiatura);
            switch(menu_selection)
            {
            case 1:
                menu_y = 220;
                if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN))
                {
                    menu_selection = 2;
                    al_rest(0.2);
                }
                if (al_key_down(&klawiatura, ALLEGRO_KEY_UP))
                {
                    menu_selection = 3;
                    al_rest(0.2);
                }
                if(al_key_down(&klawiatura, ALLEGRO_KEY_ENTER))
                {
                    menu_state = 2;

                }
                break;
            case 2:
                menu_y = 300;
                if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN))
                {
                    menu_selection = 3;
                    al_rest(0.2);
                }
                if (al_key_down(&klawiatura, ALLEGRO_KEY_UP))
                {
                    menu_selection = 1;
                    al_rest(0.2);
                }
                if(al_key_down(&klawiatura, ALLEGRO_KEY_ENTER))
                {
                    load(&level_number);
                    game_state = level_number;
                    menu_state = 2;
                }
                break;

            case 3:
                menu_y = 380;
                if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN))
                {
                    menu_selection = 1;
                    al_rest(0.2);
                }
                if (al_key_down(&klawiatura, ALLEGRO_KEY_UP))
                {
                    menu_selection = 2;
                    al_rest(0.2);
                }
                if(al_key_down(&klawiatura, ALLEGRO_KEY_ENTER))
                {
                    *exit = true;
                }
                break;
            }
            al_draw_bitmap (menu_back,0,0,0);
            al_draw_bitmap (new_game_g,200,220,0);
            al_draw_bitmap (load_game_g,200,300,0);
            al_draw_bitmap (exit_g,200,380,0);
            al_draw_bitmap (border,200,menu_y,0);
            *menu_time = al_get_time();
            al_flip_display();
            al_rest(0.001);
        }

}



