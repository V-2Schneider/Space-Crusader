#include <allegro.h>
#include "../headers/enemy.h"

int screen_l=800, screen_w=600, player_size=40, game_state = 1;
ALLEGRO_KEYBOARD_STATE keyboard;


void gameplay_fly()
{
    if ((player_dead == false)&&(ending==false))
    {
        if ( al_key_down(&keyboard, ALLEGRO_KEY_RIGHT ) && player_x < screen_l - player_size) player_x += 2;

        if ( al_key_down(&keyboard, ALLEGRO_KEY_LEFT ) && player_x > 0) player_x -= 2;

        if ( al_key_down(&keyboard, ALLEGRO_KEY_DOWN ) && player_y < screen_w - player_size) player_y += 2;

        if ( al_key_down(&keyboard, ALLEGRO_KEY_UP ) && player_y > 0) player_y -= 2;
    }
}

void projectiles()
{
    if ((player_dead == false)&&(ending==false))
    {
        if ( al_key_down(&keyboard, ALLEGRO_KEY_SPACE ) && projectile[0] == false && !(!(al_get_time() > shot[2] + 0.3)&&(projectile[2]==true)))
        {
            shot_x[0] = player_x+15; //setting up the starting position
            shot_y[0] = player_y;    //of projectile number 1
            projectile[0] = true;
            shot[0] = al_get_time();
        }
        if ( al_key_down(&keyboard, ALLEGRO_KEY_SPACE ) && projectile[0] == true && projectile[1] == false && al_get_time() > shot[0] + 0.3)
        {
            shot_x[1] = player_x+15; //setting up the starting position
            shot_y[1] = player_y;    //of projectile number 2
            projectile[1] = true;
            shot[1] = al_get_time();
        }
        if ( al_key_down(&keyboard, ALLEGRO_KEY_SPACE ) && projectile[1] == true && projectile[2] == false && al_get_time() > shot[1] + 0.3)
        {
            shot_x[2] = player_x+15; //setting up the starting position
            shot_y[2] = player_y;    //of projectile number 3   
            projectile[2] = true;
            shot[2] = al_get_time();
        }
    }
    for (int i = 0 ; i<3 ; i++)
        if (projectile[i] == true) shot_y[i] -= 5;
    for (int i = 0 ; i < 3 ; i++)
        if (shot_y[i] < -20) projectile[i] = false;
}
