#pragma once

#include <ncurses.h>

enum e_const
{
    WIN_VALUE = 2048
};

typedef struct s_game
{
    int **mat;
    int  size;
    int  score;
}   t_game;

/*=-=-=-=-=-=-MOVEMENT-=-=-=-=-=-=*/

void transpose(int **mat, int size);
void reverse_rows(int **mat, int size);
void to_left(int **mat, int size);
void to_right(int **mat, int size);
void to_up(int **mat, int size);
void to_down(int **mat, int size);

/*=-=-=-=-=-=-STATUS-=-=-=-=-=-=*/

int is_game_over(int **mat, int size);

/*=-=-=-=-=-=-DRAWING-=-=-=-=-=-=*/

int draw_grid(int game_size);
int	draw_values();
