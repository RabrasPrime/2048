#include "game.h"

void transpose(int **mat, int size)
{
    int i = 0;
    int j;
    int tmp;

    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            tmp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = tmp;
            j++;
        }
        i++;
    }
}

void reverse_rows(int **mat, int size)
{
    int i = 0;
    int j;
    int tmp;

    while (i < size)
    {
        j = 0;
        while (j < size / 2)
        {
            tmp = mat[i][j];
            mat[i][j] = mat[i][size - j - 1];
            mat[i][size - j - 1] = tmp;
            j++;
        }
        i++;
    }
}
