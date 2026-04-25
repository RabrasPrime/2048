#pragma once

#include <ncurses.h>
#include <limits.h>
#include <stdlib.h>

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
int to_left(int **mat, int size, int *score);
int to_right(int **mat, int size, int *score);
int to_up(int **mat, int size, int *score);
int to_down(int **mat, int size, int *score);

/*=-=-=-=-=-=-STATUS-=-=-=-=-=-=*/

int is_game_over(int **mat, int size);

/*=-=-=-=-=-=-DRAWING-=-=-=-=-=-=*/

int		draw_game(t_game *game);
void	init_ncurses_colors(void);
int		pair_from_value(int value);

void generate_num(int **mat, int size);
