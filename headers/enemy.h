#ifndef enemy_h
#define enemy_h

extern short lives;
extern double shot[3];
extern double level_time[3], untouchable_time;
extern int enemy_x[32], enemy_y[32], enemy_missle_x[32], enemy_missle_y[32];
extern int player_x, player_y, shot_x[3], shot_y[3];
extern int score, shot_enemies;
extern bool projectile[3], player_dead, untouchable;
extern bool enemy_exists[32], enemy_is_dead[32], enemy_missles[32];
extern bool patterns[12], level_start[3], ending;

void check_hitbox(int how_many, int points);
void pattern_1(int how_many, double *time, short pattern_number);
void pattern_2(int how_many, double *time, short pattern_number);
void pattern_3(int how_many, double *time, short pattern_number);
void check_life(int how_many);
void clear_patterns();
void respawn();


#endif
