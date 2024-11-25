#include "Pong.h"

void	clean_img(my_img img, void *mlx)
{
	if(img.data.img && mlx)
		mlx_destroy_image(mlx, img.data.img);
}

unsigned int	get_color(t_data *data, int x, int y)
{
	return(*(unsigned int*)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8))));
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_img(my_img *img, char *filename, void *mlx)
{
	img->data.img = mlx_xpm_file_to_image(mlx, filename, &img->width, &img->height);
	if(!img->data.img)
		return(-1);
	img->data.addr = mlx_get_data_addr(img->data.img, &img->data.bits_per_pixel, &img->data.line_length, &img->data.endian);
	if(!img->data.addr)
		return(-1);
	return(0);
}

void	put_img(my_img *img, int x, int y, my_img *put)
{
	int				i;
	int 			j;
	unsigned int	color;

	i = 0;

	while(i < put->height)
	{
		j = 0;
		while (j < put->width)
		{
			if(x + j - (put->width / 2) < img->width && y + i - (put->height / 2) < img->height && x + j - (put->width / 2) > 0 && y + i - (put->height / 2) > 0)
			{
				color =  get_color(&put->data, j, i);
				if(color <= 16777215)
					pixel_put(&img->data ,x + j - (put->width / 2), y + i - (put->height / 2), color);		
			}
			j++;
		}
		i++;
	}
	
}

void	put_black(my_img *img, int x, int y, my_img *put)
{
	int				i;
	int 			j;
	unsigned int	color;

	i = 0;

	while(i < put->height)
	{
		j = 0;
		while (j < put->width)
		{
			if(x + j - (put->width / 2) < img->width && y + i - (put->height / 2) < img->height && x + j - (put->width / 2) > 0 && y + i - (put->height / 2) > 0)
			{
				color =  get_color(&put->data, j, i);
				if(color == 0)
					pixel_put(&img->data ,x + j - (put->width / 2), y + i - (put->height / 2), color);		
			}
			j++;
		}
		i++;
	}
	
}

void	put_non_white(my_img *img, int x, int y, my_img *put)
{
	int				i;
	int 			j;
	unsigned int	color;

	i = 0;

	while(i < put->height)
	{
		j = 0;
		while (j < put->width)
		{
			if(x + j - (put->width / 2) < img->width && y + i - (put->height / 2) < img->height && x + j - (put->width / 2) > 0 && y + i - (put->height / 2) > 0)
			{
				color =  get_color(&put->data, j, i);
				if(color <= 13631487)
					pixel_put(&img->data ,x + j - (put->width / 2), y + i - (put->height / 2), color);		
			}
			j++;
		}
		i++;
	}
	
}

void	put_non_white2(my_img *img, int x, int y, my_img *put)
{
	int				i;
	int 			j;
	unsigned int	color;

	i = 0;

	while(i < put->height)
	{
		j = 0;
		while (j < put->width)
		{
			if(x + j - (put->width / 2) < img->width && y + i - (put->height / 2) < img->height && x + j - (put->width / 2) > 0 && y + i - (put->height / 2) > 0)
			{
				color =  get_color(&put->data, j, i);
				if(color < 16777215)
					pixel_put(&img->data ,x + j - (put->width / 2), y + i - (put->height / 2), color);		
			}
			j++;
		}
		i++;
	}
	
}

// void	put_img(my_img *img, int x, int y, my_img *put)
// {
// 	int				i;
// 	int 			j;
// 	unsigned int	color;

// 	i = 0;
// 	j = 0;

// 	while(i++ < put->height)
// 	{
// 		while (j++ < put->width)
// 		{
// 			if(x + j < img->width && y + i < img->height && x + j> 0 && y + i > 0)
// 			{
// 				color =  get_color(&put->data, j, i);
// 				//if(color < 16777215 )
// 					//pixel_put(&img->data ,x + j - (put->width / 2), y + i - (put->height / 2), color);
					
					
// 				pixel_put(&img->data ,x + j , y + i, 0);
					
// 			}
// 		}
// 		j = 0;
// 	}
	
// }