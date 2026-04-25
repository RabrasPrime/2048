#pragma once

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

void transpose(int **mat, int size);
void reverse_rows(int **mat, int size);
void to_left(int **mat, int size);
void to_right(int **mat, int size);
void to_up(int **mat, int size);
void to_down(int **mat, int size);
