#include "game.h"
#include <ncurses.h>

int	draw_grid(int game_size)
{
	int	cell_w = (COLS - 1) / game_size;
	int	cell_h = (LINES - 1) / game_size;
	int	grid_w = cell_w * game_size + 1;
	int	grid_h = cell_h * game_size + 1;

	if (game_size <= 0)
		return (1);
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
int	draw_values()
{
	return 0;
}
