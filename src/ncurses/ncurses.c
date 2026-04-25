#include "game.h"
#include <ncurses.h>

static int	draw_grid(int cell_w, int cell_h, int grid_w, int grid_h)
{
	if (cell_w < 7 || cell_h < 2)
		return (1);

	clear();
	for (int i = 0; i < grid_h; i++)
	{
		for (int j = 0; j < grid_w; j++)
		{
			int	on_h = (i % cell_h == 0);
			int	on_v = (j % cell_w == 0);

			if (on_h && on_v)
				mvaddch(i, j, '+');
			else if (on_h)
				mvaddch(i, j, '-');
			else if (on_v)
				mvaddch(i, j, '|');
			else
				mvaddch(i, j, ' ');
		}
	}
	return (0);
}

static int	nb_len(int nb)
{
	int	i = 1;
	int	len = 0;

	while (nb / i != 0)
	{
		len++;
		i *= 10;
	}
	return len;
}

static int	draw_values(t_game *game, int cell_w, int cell_h)
{
	for (int i = 0; i < game->size; i++)
	{
		for (int j = 0; j < game->size; j++)
		{
			if (game->mat[i][j] != 0)
			{
				attron(COLOR_PAIR(pair_from_value(game->mat[i][j])));

				for (int k = 1; k < cell_w; k++)
				{
					for (int l = 1; l < cell_h; l++)
					{
						mvaddch(l + i * cell_h, k + j * cell_w, ' ');
					}
				}

				mvprintw(cell_h * (i + 1) - cell_h / 2,
			 			cell_w * (j + 1) - cell_w / 2 - nb_len(game->mat[i][j]) / 2,
						"%d", game->mat[i][j]);

				attroff(COLOR_PAIR(pair_from_value(game->mat[i][j])));
			}
		}
	}
	return 0;
}

int	draw_game(t_game *game)
{
	int	cell_w = (COLS - 1) / game->size;
	int	cell_h = (LINES - 1) / game->size;
	int	grid_w = cell_w * game->size + 1;
	int	grid_h = cell_h * game->size + 1;

	clear();
	if (draw_grid(cell_w, cell_h, grid_w, grid_h) == 0)
		draw_values(game, cell_w, cell_h);
	move(LINES - 1, COLS - 1);

	return refresh();
}
