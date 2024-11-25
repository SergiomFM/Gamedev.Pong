#ifndef PONG_HPP
#define PONG_HPP

# include "minilibx-linux/minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <time.h>

#define IMG_SPACE 00
#define BALL_SPEED 1
#define BAR_SPEED 1
#define ACELARATION 0.15

#define UPKEY 65362
#define DOWNKEY 65364
#define ESCAPEKEY 65307
#define SPACEKEY 32
#define WINSCORE 5

#define ABS(x) ((x) < 0 ? -(x) : (x))
//MLX stuff

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_my_img{

	t_data	data;

	int		width;
	int		height;

}my_img;

void			clean_img(my_img img, void *mlx);
void			pixel_put(t_data *data, int x, int y, int color);
unsigned int	get_color(t_data *data, int x, int y);
void			put_img(my_img *img, int x, int y, my_img *put);
int				get_img(my_img *img, char *filename, void *mlx);

//Game Stuff

typedef struct s_ball{

	double	x_pos;
	double	y_pos;

	double	x_velocity;
	double	y_velocity;

	my_img	img;

}t_ball;


typedef struct s_bar{

	double	x_pos;
	double	y_pos;

	double	width;

	my_img	img;

}t_bar;

typedef struct s_keystates{

	int	w;
	int	s;

	int key_up;
	int key_down;

	int pause;
	int esc;

}t_keystates;

typedef struct s_game{

	int		delta_time;
	t_ball	ball;
	t_bar	right_bar;
	t_bar	left_bar;

	my_img	score_img[WINSCORE];
	my_img	right_win_img;
	my_img	left_win_img;

	int		right_score;
	int		left_score;


	void			*mlx;
	void			*win;
	my_img			board_img;
	my_img			img;
	my_img			pause_img;

	t_keystates		keystates;

}t_game;



t_game	*init_game(void);
void	clean_game(t_game *game);
int		loop_function(t_game *game);
void	colision_check(t_game *game);

//events

int		key_press(int keycode, t_game *game);
int		key_down(int keycode, t_game *game);
int		key_up(int keycode, t_game *game);
int		my_exit(t_game *game);
void	key_handler(t_game *game);
void	start_ball(t_game *game);

long long int	get_time_mil();
long long int 	delta_time(void);

void	init_score_imgs(t_game *game);
void	clean_score_imgs(t_game *game);
void	put_black(my_img *img, int x, int y, my_img *put);
void	put_non_white(my_img *img, int x, int y, my_img *put);

#endif