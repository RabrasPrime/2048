#include "game.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

t_game  *game_init(int board_size)
{
    t_game  *game;
    int     i;
    int     j;

    game = malloc(sizeof(t_game));
    if (!game)
        return (NULL);
    game->mat = malloc(board_size * sizeof(int *));
    if (!game->mat)
    {
        free(game);
        return (NULL);
    }
    i = 0;
    while (i < board_size)
    {
        game->mat[i] = malloc(board_size * sizeof(int));
        if (!game->mat[i])
        {
            while (--i >= 0)
                free(game->mat[i]);
            free(game->mat);
            free(game);
            return (NULL);
        }
        j = 0;
        while (j < board_size)
            game->mat[i][j++] = 0;
        i++;
    }
    game->size = board_size;
    game->score = 0;
    return (game);
}

void    game_destroy(t_game *game)
{
    int i;

    i = 0;
    while (i < game->size)
        free(game->mat[i++]);
    free(game->mat);
    free(game);
}

int main(void)
{
    int     key;
    t_game  *game;
    int     moved;

    srand(time(NULL));
    initscr();
    timeout(50);
    keypad(stdscr, TRUE);
    game = game_init(5);
    if (!game)
        return (1);
    generate_num(game->mat, game->size);
    generate_num(game->mat, game->size);
    draw_game(game);
    while (TRUE)
    {
        key = getch();
        moved = 0;
        if (key == KEY_UP)
            moved = 1;
        else if (key == KEY_DOWN)
            moved = 1;
        else if (key == KEY_LEFT)
            moved = 1;
        else if (key == KEY_RIGHT)
            moved = 1;
        if (key == KEY_UP)
            to_up(game->mat, game->size);
        else if (key == KEY_DOWN)
            to_down(game->mat, game->size);
        else if (key == KEY_LEFT)
            to_left(game->mat, game->size);
        else if (key == KEY_RIGHT)
            to_right(game->mat, game->size);
        if (moved)
            generate_num(game->mat, game->size);
        draw_game(game);
        if (is_game_over(game->mat, game->size))
        {
            mvprintw(game->size + 2, 0, "GAME OVER! Score: %d", game->score);
            refresh();
            timeout(-1);
            getch();
            break ;
        }
    }
    endwin();
    game_destroy(game);
    return (0);
}
