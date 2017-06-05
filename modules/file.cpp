#include <fstream>
#include <enemy.h>
#include <levels.h>
#include <stdio.h>

using namespace std;

void save(int *level_number)
{
    fstream saves;

    saves.open("save1.save", ios_base::out);
    saves << score << ' ' << shot_enemies << ' ' << lives << ' ' << *level_number + 1;
    saves.close();
}

void load(int *level_number)
{
    fstream saves;

    saves.open("save1.save", ios_base::in);
    saves >> score >> shot_enemies >> lives >> *level_number;

    saves.close();
}

