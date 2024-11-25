#include "Pong.h"

int	my_exit(t_game *game)
{
	clean_game(game);
	exit(0);
	return(0);
}

int	key_down(int keycode, t_game *game)
{
	if(keycode == 'w')
		game->keystates.w = 1;
	else if(keycode == 's')
		game->keystates.s = 1;
	else if(keycode == UPKEY)
		game->keystates.key_up = 1;
	else if(keycode == DOWNKEY)
		game->keystates.key_down = 1;
	else if(keycode == ESCAPEKEY)
		game->keystates.esc = 1;
	else if(keycode == 'p' || keycode == SPACEKEY)
	{
		if(game->keystates.pause)
			game->keystates.pause = 0;
		else
			game->keystates.pause = 1;
	}
	return(0);
}

int	key_up(int keycode, t_game *game)
{
	if(keycode == 'w')
		game->keystates.w = 0;
	else if(keycode == 's')
		game->keystates.s = 0;
	else if(keycode == UPKEY)
		game->keystates.key_up = 0;
	else if(keycode == DOWNKEY)
		game->keystates.key_down = 0;
	return(0);
}

int	key_press(int keycode, t_game *game)
{
	if(keycode == 'w')
		game->left_bar.y_pos -= (game->img.height / 50) * BAR_SPEED ;
	else if(keycode == 's')
		game->left_bar.y_pos += (game->img.height / 50) * BALL_SPEED;
	else if(keycode == UPKEY)
		game->right_bar.y_pos -= (game->img.height / 50) * BALL_SPEED;
	else if(keycode == DOWNKEY)
		game->right_bar.y_pos += (game->img.height / 50) * BALL_SPEED;
	else
		printf("%i\n", keycode);
	return(0);
}