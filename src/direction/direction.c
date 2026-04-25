#include "game.h"
#include "libft.h"
#include <limits.h>

static void compact(int *row, int size)
{
    int tmp[size];
    int pos;
    int j;

    ft_memset(tmp, 0, size * sizeof(int));
    pos = 0;
    j = 0;
    while (j < size)
    {
        if (row[j] != 0)
            tmp[pos++] = row[j];
        j++;
    }
    j = 0;
    while (j < size)
    {
        row[j] = tmp[j];
        j++;
    }
}

static void merge_left(int *row, int size)
{
    int j;

    compact(row, size);
    j = 0;
    while (j < size - 1)
    {
        if (row[j] != 0 && row[j] == row[j + 1])
        {
            row[j] *= 2;
            row[j + 1] = 0;
            j++;
        }
        j++;
    }
    compact(row, size);
}

void to_left(int **mat, int size)
{
    int i;

    i = 0;
    while (i < size)
        merge_left(mat[i++], size);
}

void to_right(int **mat, int size)
{
    reverse_rows(mat, size);
    to_left(mat, size);
    reverse_rows(mat, size);
}

void to_up(int **mat, int size)
{
    transpose(mat, size);
    to_left(mat, size);
    transpose(mat, size);
}

void to_down(int **mat, int size)
{
    transpose(mat, size);
    to_right(mat, size);
    transpose(mat, size);
}
