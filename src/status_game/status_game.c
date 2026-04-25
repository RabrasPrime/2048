#include "game.h"

static int has_empty(int **mat, int size)
{
    int i = 0;
    int j;

    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (mat[i][j] == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

static int can_merge(int **mat, int size)
{
    int i = 0;
    int j;

    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (j + 1 < size && mat[i][j] == mat[i][j + 1])
                return (1);
            if (i + 1 < size && mat[i][j] == mat[i + 1][j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int is_game_over(int **mat, int size)
{
    return (!has_empty(mat, size) && !can_merge(mat, size));
}

int has_won(int **mat, int size)
{
    int i = 0;
    int j;

    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (mat[i][j] == WIN_VALUE)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
