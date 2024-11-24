#include "Pong.h"

void clean_game(t_game *game)
{
	clean_img(game->ball.img, game->mlx);
	clean_img(game->right_bar.img, game->mlx);
	clean_img(game->left_bar.img, game->mlx);
	clean_img(game->board_img, game->mlx);
	clean_img(game->img, game->mlx);

	if(game->mlx)
	{
		if(game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

void	start_ball(t_game *game)
{
	srand(time(NULL));

	game->ball.x_pos = game->img.width / 2;
	game->ball.y_pos = game->img.height / 2;

	int	r = rand() % 4;
	if(r == 0)
	{
		game->ball.x_velocity = BALL_SPEED;
		game->ball.y_velocity = BALL_SPEED;
	}
	else if(r == 1)
	{
		game->ball.x_velocity = BALL_SPEED;
		game->ball.y_velocity = -BALL_SPEED;
	}
	else if(r == 2)
	{
		game->ball.x_velocity = -BALL_SPEED;
		game->ball.y_velocity = BALL_SPEED;
	}
	else if(r == 3)
	{
		game->ball.x_velocity = -BALL_SPEED;
		game->ball.y_velocity = -BALL_SPEED;
	}
}

t_game	*init_game(void)
{
	t_game	*game;
	
	game  = (t_game*)calloc(1, sizeof(t_game));
	if(!game)	
		return(NULL);

	game->mlx = mlx_init();

	// init board

	if(get_img(&game->board_img,"Imgs/board_img.xpm", game->mlx))
	{
		clean_game(game);
		return(NULL);
	}
	// init ball

	if(get_img(&game->ball.img,"Imgs/ball_img.xpm", game->mlx))
	{
		clean_game(game);
		return(NULL);
	}

	//init bars

	if(get_img(&game->right_bar.img,"Imgs/right_bar_img.xpm", game->mlx))
	{
		clean_game(game);
		return(NULL);
	}

	if(get_img(&game->left_bar.img,"Imgs/left_bar_img.xpm", game->mlx))
	{
		clean_game(game);
		return(NULL);
	}

	//init game image
	get_img(&game->img,"Imgs/board_img.xpm", game->mlx);
	game->win = mlx_new_window(game->mlx, game->img.width, game->img.height, "Pong");

	//init ball position
	start_ball(game);

	//init bars position

	game->right_bar.x_pos = game->img.width - 50;
	game->right_bar.y_pos = game->img.height / 2;
	game->right_bar.width = game->left_bar.img.height;

	game->left_bar.x_pos = 50;
	game->left_bar.y_pos = game->img.height / 2;
	game->left_bar.width = game->right_bar.img.height;

	return(game);
}

int		loop_function(t_game *game)
{
	//set delta time
	game->delta_time = delta_time();

	//check colision

	colision_check(game);

	//check points

	if (game->left_score >= WINSCORE || game->right_score >= WINSCORE)
	{
		clean_game(game);
		exit(0);
	}

	//check key states 
	key_handler(game);

	//move ball

	//printf("%d\n", game->delta_time);
	//printf("X::%f Y::%f\n",game->ball.x_pos, game->ball.y_pos);

	game->ball.x_pos += (game->ball.x_velocity * game->delta_time);
	game->ball.y_pos += (game->ball.y_velocity * game->delta_time);


	// change image
	put_img(&game->img, game->img.width / 2, game->img.height / 2, &game->board_img);
	put_img(&game->img, roundf(game->ball.x_pos), roundf(game->ball.y_pos) , &game->ball.img);
	put_img(&game->img, roundf(game->left_bar.x_pos), roundf(game->left_bar.y_pos) , &game->left_bar.img);
	put_img(&game->img, roundf(game->right_bar.x_pos), roundf(game->right_bar.y_pos) , &game->right_bar.img);


	//put image to screen
	mlx_put_image_to_window(game->mlx, game->win, game->img.data.img, 0, 0);

	return(0);
}

void	key_handler(t_game *game)
{
	if(game->keystates.w)
	{
		if(game->left_bar.y_pos >= 0 + game->left_bar.img.height / 2)
			game->left_bar.y_pos -= game->img.height / 500 * BAR_SPEED * game->delta_time;
	}
	if(game->keystates.s)
	{
		if(game->left_bar.y_pos <= game->img.height - game->left_bar.img.height / 2)
			game->left_bar.y_pos += game->img.height / 500 * BAR_SPEED * game->delta_time;
	}
	if(game->keystates.key_up)
	{
		if(game->right_bar.y_pos >= 0 + game->right_bar.img.height / 2)
			game->right_bar.y_pos -= game->img.height / 500 * BAR_SPEED * game->delta_time;
	}
	if(game->keystates.key_down)
	{
		if(game->right_bar.y_pos <= game->img.height - game->right_bar.img.height / 2)
			game->right_bar.y_pos += game->img.height / 500 * BAR_SPEED * game->delta_time;
	}
	if(game->keystates.esc)
	{
		clean_game(game);
		exit(0);
	}
}