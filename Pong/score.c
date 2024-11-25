#include "Pong.h"

void	init_score_imgs(t_game *game)
{
	if(get_img(&(game->score_img[0]),"ScoreImgs/score_img0.xpm", game->mlx))
		printf("FALURE\n");
	get_img(&(game->score_img[1]),"ScoreImgs/score_img1.xpm", game->mlx);
	get_img(&(game->score_img[2]),"ScoreImgs/score_img2.xpm", game->mlx);
	get_img(&(game->score_img[3]),"ScoreImgs/score_img3.xpm", game->mlx);
	get_img(&(game->score_img[4]),"ScoreImgs/score_img4.xpm", game->mlx);
	// get_img(&(game->score_img[5]),"ScoreImgs/score_img5.xpm", game->mlx);
	// get_img(&(game->score_img[6]),"ScoreImgs/score_img6.xpm", game->mlx);
	// get_img(&(game->score_img[7]),"ScoreImgs/score_img7.xpm", game->mlx);
	// get_img(&(game->score_img[8]),"ScoreImgs/score_img8.xpm", game->mlx);
	// get_img(&(game->score_img[9]),"ScoreImgs/score_img9.xpm", game->mlx);
}

void	clean_score_imgs(t_game *game)
{
	for(int i = 0; i < WINSCORE; i++)
	{
		clean_img(game->score_img[i], game->mlx);
	}
}