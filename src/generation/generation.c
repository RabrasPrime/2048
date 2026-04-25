#include "game.h"

void generate_num(int **mat, int size)
{
    int empty[size * size][2];
    int value =(rand() % 10 <= 1) ? 4 : 2;
    int id_i;
    int len = 0;
    int i = 0;
    int j;

    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (mat[i][j] == 0)
            {
                empty[len][0] = i;
                empty[len][1] = j;
                len++;
            }
            j++;
        }
        i++;
    }
    if (len == 0)
            return ;
    id_i = rand() % len;
    mat[empty[id_i][0]][empty[id_i][1]] = value;
}
