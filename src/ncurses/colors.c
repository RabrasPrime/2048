#include "game.h"
#include <ncurses.h>

enum e_nc_color_id
{
	C_EMPTY      = 16,
	C_BOARD      = 17,
	C_LIGHT_TEXT = 18,
	C_DARK_TEXT  = 19,
	C_2          = 20,
	C_4          = 21,
	C_8          = 22,
	C_16         = 23,
	C_32         = 24,
	C_64         = 25,
	C_128        = 26,
	C_256        = 27,
	C_512        = 28,
	C_1024       = 29,
	C_2048       = 30
};

enum e_nc_pair_id
{
	P_EMPTY = 1,
	P_BOARD,
	P_2,
	P_4,
	P_8,
	P_16,
	P_32,
	P_64,
	P_128,
	P_256,
	P_512,
	P_1024,
	P_2048
};

static void	init_2048_colors(void)
{
	init_color(C_EMPTY,      804, 757, 706);
	init_color(C_BOARD,      733, 678, 627);
	init_color(C_LIGHT_TEXT, 976, 965, 949);
	init_color(C_DARK_TEXT,  467, 431, 396);
	init_color(C_2,          933, 894, 855);
	init_color(C_4,          929, 878, 784);
	init_color(C_8,          949, 694, 475);
	init_color(C_16,         961, 584, 388);
	init_color(C_32,         965, 486, 373);
	init_color(C_64,         965, 369, 231);
	init_color(C_128,        929, 812, 447);
	init_color(C_256,        929, 800, 380);
	init_color(C_512,        929, 784, 314);
	init_color(C_1024,       929, 773, 247);
	init_color(C_2048,       929, 761, 180);
}

void	init_ncurses_colors(void)
{
	if (!has_colors())
		return ;
	start_color();

	if (can_change_color())
		init_2048_colors();

	init_pair(P_EMPTY, C_DARK_TEXT, C_EMPTY);
	init_pair(P_BOARD, C_DARK_TEXT, C_BOARD);
	init_pair(P_2,     C_DARK_TEXT, C_2);
	init_pair(P_4,     C_DARK_TEXT, C_4);
	init_pair(P_8,     C_LIGHT_TEXT, C_8);
	init_pair(P_16,    C_LIGHT_TEXT, C_16);
	init_pair(P_32,    C_LIGHT_TEXT, C_32);
	init_pair(P_64,    C_LIGHT_TEXT, C_64);
	init_pair(P_128,   C_LIGHT_TEXT, C_128);
	init_pair(P_256,   C_LIGHT_TEXT, C_256);
	init_pair(P_512,   C_LIGHT_TEXT, C_512);
	init_pair(P_1024,  C_LIGHT_TEXT, C_1024);
	init_pair(P_2048,  C_LIGHT_TEXT, C_2048);
}

int	pair_from_value(int value)
{
	if (value == 0)
		return (P_EMPTY);
	else if (value == 2)
		return (P_2);
	else if (value == 4)
		return (P_4);
	else if (value == 8)
		return (P_8);
	else if (value == 16)
		return (P_16);
	else if (value == 32)
		return (P_32);
	else if (value == 64)
		return (P_64);
	else if (value == 128)
		return (P_128);
	else if (value == 256)
		return (P_256);
	else if (value == 512)
		return (P_512);
	else if (value == 1024)
		return (P_1024);
	else if (value == 2048)
		return (P_2048);
	return (P_2048);
}
