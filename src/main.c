#include "game.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

t_game  *game_init(int board_size)
{
    t_game  *game;
    int		val = WIN_VALUE;

    if (val <= 0 || (val & (val - 1)) != 0)
    {
    	ft_printf("WIN_VALUE must be a power of 2\n");
     	return NULL;
    }
    if (val > 131072)
    {
    	ft_printf("WIN_VALUE can be at most 131072\n");
     	return NULL;
    }

	game = malloc(sizeof(t_game));
	if (!game)
		return NULL;

	game->mat = malloc(board_size * sizeof(int *));
	if (!game->mat)
	{
		free(game);
		return NULL;
	}

	for (int i = 0; i < board_size; i++)
	{
		game->mat[i] = malloc(board_size * sizeof(int));
		if (!game->mat[i])
		{
			i--;
			while (i > 0)
			{
				free(game->mat[i]);
				i--;
			}
			break;
		}
	}

	game->size = board_size;
	game->score = 0;
	generate_num(game->mat, game->size);
    generate_num(game->mat, game->size);

	return game;
}

void screen_init(t_game *game)
{
	srand(time(NULL));
    initscr();
    start_color();
    use_default_colors();
    init_ncurses_colors();
    timeout(50);
    keypad(stdscr, TRUE);
    set_escdelay(25);
    draw_game(game);
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

    game = game_init(5);
    if (!game)
        return (1);
    screen_init(game);

    while (TRUE)
    {
        key = getch();
        moved = 0;
        if (key == KEY_UP)
            moved = to_up(game->mat, game->size, &game->score);
        else if (key == KEY_DOWN)
            moved = to_down(game->mat, game->size, &game->score);
        else if (key == KEY_LEFT)
            moved = to_left(game->mat, game->size, &game->score);
        else if (key == KEY_RIGHT)
            moved = to_right(game->mat, game->size, &game->score);
        else if (key == 27)
        	break ;

        if (moved)
        {
            generate_num(game->mat, game->size);
            draw_game(game);
        }

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
