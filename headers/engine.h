#ifndef engine_h
#define engine_h

extern int screen_l, screen_w, player_size, game_states;
extern ALLEGRO_KEYBOARD_STATE keyboard;

void gameplay_fly();
void projectiles();

struct player {
    int pos_x;
    int pos_y;
    int size_x;
    int size_y;

};

#endif
