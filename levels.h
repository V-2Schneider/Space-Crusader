#ifndef levels_h
#define levels_h


extern int menu_state;

void level_1(double *czas, double pattern_time[2], double *znowu_czas);
void level_2(double *czas, double pattern_time[2], double *znowu_czas);
void level_3(double *czas, double pattern_time[2], double *znowu_czas);
void game_loop(double *czas, double pattern_time[2], double *znowu_czas);
void menu_loop(double *menu_time, bool *exit);
void high_scores(double *menu_time);

#endif
