#include "game.h"
#include "libft.h"
#include <limits.h>

static int  compact(int *row, int size)
{
    int tmp[size];
    int pos;
    int j;
    int changed;

    ft_memset(tmp, 0, size * sizeof(int));
    pos = 0;
    j = 0;
    while (j < size)
    {
        if (row[j] != 0)
            tmp[pos++] = row[j];
        j++;
    }
    changed = (ft_memcmp(row, tmp, size * sizeof(int)) != 0);
    j = 0;
    while (j < size)
    {
        row[j] = tmp[j];
        j++;
    }
    return (changed);
}

static int  merge_left(int *row, int size, int *score)
{
    int changed;
    int j;

    changed = compact(row, size);
    j = 0;
    while (j < size - 1)
    {
        if (row[j] != 0 && row[j] == row[j + 1])
        {
            row[j] *= 2;
            *score += row[j];
            row[j + 1] = 0;
            changed = 1;
            j++;
        }
        j++;
    }
    changed |= compact(row, size);
    return (changed);
}

int to_left(int **mat, int size, int *score)
{
    int changed = 0;
    int i;

    i = 0;
    while (i < size)
        changed |= merge_left(mat[i++], size, score);
    return (changed);
}

int to_right(int **mat, int size, int *score)
{
    int changed = 0;

    reverse_rows(mat, size);
    changed |= to_left(mat, size, score);
    reverse_rows(mat, size);

    return (changed);
}

int to_up(int **mat, int size, int *score)
{
    int changed = 0;

    transpose(mat, size);
    changed |= to_left(mat, size, score);
    transpose(mat, size);

    return (changed);
}

int to_down(int **mat, int size, int *score)
{
    int changed = 0;

    transpose(mat, size);
    changed |= to_right(mat, size, score);
    transpose(mat, size);

    return (changed);
}
