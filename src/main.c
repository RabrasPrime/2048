#include "game.h"
#include <unistd.h>

int main()
{
	initscr();

	while (TRUE)
	{
		clear();
		draw_grid(5);
		draw_values();
		refresh();
		sleep(1);
	}
	endwin();
    return (0);
}
