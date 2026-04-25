#include "game.h"
#include "libft.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

volatile int g_running = 1;

static void handle_sigint(int sig)
{
    (void)sig;
    g_running = 0;
}

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

int main(int argc, char **argv)
{
    int     key;
    t_game  *game;
    int     moved;
    int     size;
    int     won = 0;

    if (argc > 2)
    {
        ft_printf("Error: wrong number of arguments \n");
        return (1);
    }
    else if (argc != 2)
        size = 4;
    else
        size = ft_atoi(argv[1]);
    if (size < 4 || size > 5)
    {
        ft_printf("Error: wrong size \n");
        return (1);
    }
    game = game_init(size);
    if (!game)
        return (1);
    screen_init(game);
    signal(SIGINT, handle_sigint);
    while (g_running)
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

            if (!won)
            {
                if (has_won(game->mat, game->size))
                {
                    won = 1;
                    mvprintw((LINES - 2) / 2, (COLS - 49) / 2, "VICTORY! Score: %d, press any button to continue", game->score);
                    refresh();
                }
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
    }
    endwin();
    game_destroy(game);
    return (0);
}
