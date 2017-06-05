#include <allegro5/allegro.h>
//#include <enemy.h>

short lives = 5;
double shot[3];
double level_time[3], untouchable_time;
int enemy_x[32], enemy_y[32], enemy_missle_x[32], enemy_missle_y[32];
int player_x = 360, player_y = 530, shot_x[3], shot_y[3];
int score = 0, shot_enemies = 0;
bool projectile[3] = {false, false, false}, player_dead = false, untouchable = false;
bool enemy_exists[32], enemy_is_dead[32], enemy_missles[32];
bool patterns[12], level_start[3] = {true, true, true}, ending = false;


void check_hitbox(int how_many, int points)
{
    for (int j = 0; j < how_many; j++)
    {
        for (int i = 0 ; i<3 ; i++)
            if (((((enemy_x[j]<=shot_x[i])||(enemy_x[j]<=shot_x[i]+10))&&((enemy_y[j]<=shot_y[i])||(enemy_y[j]<=shot_y[i]+20))&&((enemy_x[j]+40>=shot_x[i])
            ||(enemy_x[j]+40>=shot_x[i]+10))&&((enemy_y[j]+40>=shot_y[i])||(enemy_y[j]+40>=shot_y[i]+20)))&&(enemy_exists[j]==true))&&projectile[i]==true)
            {
                shot_enemies++;
                enemy_exists[j] = false;
                projectile[i] = false;
                enemy_is_dead[j] = true;
                score+=points;
            }
        if ((((((player_x+10<=enemy_x[j])||(player_x+10<=enemy_x[j]+40))&&((player_y+10<=enemy_y[j])||(player_y+10<=enemy_y[j]+40))&&((player_x+30>=enemy_x[j])
            ||(player_x+30>=enemy_x[j]+40))&&((player_y+30>=enemy_y[j])||(player_y+30>=enemy_y[j]+40)))&&(player_dead==false))&&enemy_is_dead[j]==false)&&untouchable == false)
        {
            player_dead = true;
            lives -= 1;
        }
        if ((((((player_x+10<=enemy_missle_x[j])||(player_x+10<=enemy_missle_x[j]+20))&&((player_y+10<=enemy_missle_y[j])||(player_y+10<=enemy_missle_y[j]+20))&&((player_x+30>=enemy_missle_x[j])
            ||(player_x+30>=enemy_missle_x[j]+20))&&((player_y+30>=enemy_missle_y[j])||(player_y+30>=enemy_missle_y[j]+20)))&&(player_dead==false))&&enemy_missles[j]==true)&&untouchable==false)
        {
            player_dead = true;
            lives -= 1;
        }

    }
}

void check_life(int how_many)
{
    for (int i = 0; i < how_many; i++)
        if (enemy_is_dead[i] == true)
                {
                    enemy_y[i] += 3;
                    if (enemy_y[i] > 600) enemy_is_dead[i] = false;
                }
}

void respawn()
{
    if (player_dead == true)
    {
        player_dead = false;
        untouchable = true;
        untouchable_time = al_get_time();
        player_x = 360;
        player_y = 530;
    }
    if ((untouchable == true) && (al_get_time() > untouchable_time + 1.0))
    {
        untouchable = false;
    }

}

void clear_patterns()
{
    for (int i = 0; i < 12; i++)
        patterns[i] = false;
}

void pattern_1(int how_many, double *time, short pattern_number)
{
    if (patterns[pattern_number-1] == false)
    {
        for (int i = 0; i < how_many; i++)
        {
            enemy_x[i]=600;
            enemy_y[i]=-40 - (i*60);
            enemy_exists[i]=true;
            enemy_is_dead[i] = false;
            enemy_missles[i] = false;
        }
        patterns[pattern_number-1] = true;
    }
    for (int i = 0; i < how_many; i++)
    {
        if (enemy_exists[i] == true)
            {
                if ((enemy_y[i] < 200)&&(enemy_x[i] == 600))
                {
                   enemy_y[i] += 2;
                }
                if ((enemy_y[i] == 200)&&(enemy_x[i] > 230 + (i*60)))
                {
                    enemy_x[i] -= 2;
                }
                if (((enemy_y[i] == 200)&&(enemy_x[i] == 230 + (i*60)))&&enemy_missles[i]==false)
                {
                    enemy_missle_x[i] = enemy_x[i] + 10;
                    enemy_missle_y[i] = enemy_y[i] + 40;
                    enemy_missles[i] = true;
                    *time = al_get_time();
                }
                if ((al_get_time() > *time + 1.5) && ((enemy_x[i] == 230 + (i*60))))
                    enemy_y[i] -= 5;
                if ((enemy_x[i] == 230 + (i*60))&&(enemy_y[i] == -50))
                    enemy_exists[i] = false;
            }

        if (enemy_missles[i] == true)
            enemy_missle_y[i] += 3;
    }
}

void pattern_2(int how_many, double *time, short pattern_number)
{
    if (patterns[pattern_number-1] == false)
    {
        for (int i = 0; i < how_many/2; i++)
        {
            enemy_x[2*i]=-40;
            enemy_y[2*i]=20 + (i*60);
            enemy_x[2*i+1]=840;
            enemy_y[2*i+1]=20 + (i*60);
            enemy_exists[2*i] = true;
            enemy_is_dead[2*i] = false;
            enemy_missles[2*i] = false;
            enemy_exists[2*i+1] = true;
            enemy_is_dead[2*i+1] = false;
            enemy_missles[2*i+1] = false;
        }
        patterns[pattern_number-1] = true;
    }
    for (int i = 0; i < how_many/2; i++)
    {
        if (enemy_exists[2*i] == true)
            {
                if ((enemy_x[2*i] < 200)&&(enemy_y[2*i] == 20 + (i*60)))
                {
                   enemy_x[2*i] += 2;
                }
                if (((enemy_x[2*i] == 200)&&(enemy_y[2*i] == 20 + (i*60)))&&enemy_missles[2*i]==false)
                {
                    enemy_missle_x[2*i] = enemy_x[2*i] + 10;
                    enemy_missle_y[2*i] = enemy_y[2*i] + 40;
                    enemy_missles[2*i] = true;
                    *time = al_get_time();
                }
                if ((al_get_time() > *time + 1.5) && ((enemy_x[2*i] == 200)))
                    enemy_y[2*i] -= 5;
                if ((enemy_x[2*i] == 200 + (i*60))&&(enemy_y[2*i] == -50))
                    enemy_exists[2*i] = false;
            }
            if (enemy_exists[2*i+1] == true)
            {
                if ((enemy_x[2*i+1] > 600)&&(enemy_y[2*i+1] == 20 + (i*60)))
                {
                   enemy_x[2*i+1] -= 2;
                }
                if (((enemy_x[2*i+1] == 600)&&(enemy_y[2*i+1] == 20 + ((i)*60)))&&enemy_missles[2*i+1]==false)
                {
                    enemy_missle_x[2*i+1] = enemy_x[2*i+1] + 10;
                    enemy_missle_y[2*i+1] = enemy_y[2*i+1] + 40;
                    enemy_missles[2*i+1] = true;
                    *time = al_get_time();
                }
                if ((al_get_time() > *time + 1.5) && ((enemy_x[2*i+1] == 600)))
                    enemy_y[2*i+1] -= 5;
                if ((enemy_x[2*i] == 600 + (i*60))&&(enemy_y[2*i+1] == -50))
                    enemy_exists[2*i+1] = false;
            }

        if (enemy_missles[2*i] == true)
        {
            enemy_missle_y[2*i] += 3;
            enemy_missle_x[2*i] += 2;
        }
        if (enemy_missles[2*i+1] == true)
        {
            enemy_missle_y[2*i+1] += 3;
            enemy_missle_x[2*i+1] -= 2;
        }


    }
}

void pattern_3(int how_many, double *time, short pattern_number)
{
    if (patterns[pattern_number-1] == false)
    {
        for (int i = 0; i < how_many; i++)
        {
            enemy_x[i]=600;
            enemy_y[i]=-40 - (i*60);
            enemy_exists[i]=true;
            enemy_is_dead[i] = false;
            enemy_missles[i] = false;
        }
        patterns[pattern_number-1] = true;
    }
    for (int i = 0; i < how_many; i++)
    {
        if (enemy_exists[i] == true)
            {
                if ((enemy_y[i] < 200)&&(enemy_x[i] == 600))
                {
                   enemy_y[i] += 2;
                }
                if ((enemy_y[i] == 200)&&(enemy_x[i] > 230 + (i*60)))
                {
                    enemy_x[i] -= 2;
                }
                if (((enemy_y[i] == 200)&&(enemy_x[i] == 230 + (i*60)))&&enemy_missles[i]==false)
                {
                    enemy_missle_x[i] = enemy_x[i] + 10;
                    enemy_missle_y[i] = enemy_y[i] + 40;
                    enemy_missles[i] = true;
                    *time = al_get_time();
                }
                if ((al_get_time() > *time + 1.5) && ((enemy_x[i] == 230 + (i*60))))
                    enemy_y[i] -= 5;
                if ((enemy_x[i] == 230 + (i*60))&&(enemy_y[i] == -50))
                    enemy_exists[i] = false;
            }

        if (enemy_missles[0] == true)
        {
            enemy_missle_y[0] += 2;
            enemy_missle_x[0] -= 2;
        }
        if (enemy_missles[1] == true)
        {
            enemy_missle_y[1] += 2;
            enemy_missle_x[1] -= 1;
        }
        if (enemy_missles[2] == true)
        {
            enemy_missle_y[2] += 2;
        }
        if (enemy_missles[3] == true)
        {
            enemy_missle_y[3] += 2;
            enemy_missle_x[3] += 1;
        }
        if (enemy_missles[4] == true)
        {
            enemy_missle_y[4] += 2;
            enemy_missle_x[4] += 2;
        }

    }
}




