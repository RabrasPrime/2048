#pragma once

#include <ncurses.h>

enum e_const
{
    WIN_VALUE = 2048
};

int draw_grid(int game_size);
int	draw_values();
