#include "game.h"
#include <ncurses.h>
#include <stdio.h>

t_game *game_init(int board_size)
{
	t_game *game;

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

	return game;
}

void	game_destroy(t_game *game)
{
	for (int i = 0; i < game->size; i++)
		free(game->mat[i]);
	free(game->mat);
	free(game);
}

int main()
{
	int		key;
	t_game	*game;

	initscr();
	start_color();
	use_default_colors();
	timeout(100);
	keypad(stdscr, TRUE);
	init_ncurses_colors();
	game = game_init(5);
	if (!game)
		return 1;

	game->mat[0][0] = 8;
	game->mat[0][1] = 4;
	while (TRUE)
	{
		key = getch();
		if (key == KEY_UP)
			to_up(game->mat, game->size);
		if (key == KEY_DOWN)
			to_down(game->mat, game->size);
		if (key == KEY_LEFT)
			to_left(game->mat, game->size);
		if (key == KEY_RIGHT)
			to_right(game->mat, game->size);
		draw_game(game);
	}
	endwin();
	game_destroy(game);
    return (0);
}
