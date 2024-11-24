#include "Pong.h"

int main(void)
{
	t_game	*game;

	game = init_game();
	delta_time();

	if(!game)
	{
		write(1, "Error\n", 6);
		return(-1);
	}

	//Key Hooks
	mlx_hook(game->win, 02, 1L << 0, key_down, game);
	mlx_hook(game->win, 03, 1L << 1, key_up, game);
	//mlx_key_hook(game->win, key_press, game);

	//Close Hook
	mlx_hook(game->win, 17, 1L << 0, my_exit, game);
	
	//Loop Hook
	mlx_loop_hook(game->mlx, loop_function, game);

	//loop
	mlx_loop(game->mlx);
	return(0);
}