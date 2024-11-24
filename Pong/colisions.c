#include "Pong.h"

void	colison_v(t_ball *ball)
{
	ball->y_velocity *= -1;
}


void	colison_h_left(t_ball *ball)
{
	if (ball->x_velocity < 0)
		ball->x_velocity *= -1;
}

void	colison_h_right(t_ball *ball)
{
	if (ball->x_velocity > 0)
		ball->x_velocity *= -1;
}

void	colision_check(t_game *game)
{
	//Bar colsion
	if (ABS(game->left_bar.x_pos - game->ball.x_pos) < game->left_bar.img.width / 2 + game->ball.img.width / 2 - IMG_SPACE &&  ABS(game->left_bar.y_pos - game->ball.y_pos) < game->left_bar.width / 2 + game->ball.img.height / 2 - IMG_SPACE)
	{
		colison_h_left(&game->ball);
	}
	else if (ABS(game->right_bar.x_pos - game->ball.x_pos) < game->right_bar.img.width / 2 + game->ball.img.width / 2 - IMG_SPACE && ABS(game->right_bar.y_pos - game->ball.y_pos ) < game->right_bar.width /2 + game->ball.img.height / 2 - IMG_SPACE)
	{
		colison_h_right(&game->ball);
	}//Vertical colision
	if (game->ball.y_pos < 0 + (game->ball.img.width) / 2 - IMG_SPACE)
	{
		colison_v(&game->ball);
	}
	else if (game->ball.y_pos > game->img.height - (game->ball.img.height) / 2 + IMG_SPACE)
	{
		colison_v(&game->ball);
	}//Horizontal colision
	else if(game->ball.x_pos < 0 + (game->ball.img.width / 2 - IMG_SPACE))
	{
		game->left_score ++;
		start_ball(game);
	}
	else if (game->ball.x_pos > game->img.width - (game->ball.img.width / 2 - IMG_SPACE))
	{
		game->left_score ++;
		start_ball(game);
	}

}