#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mlx.h"


typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_point {
	int	coord_x;
	int	coord_y;
}				t_point;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	create_rectangle(int x, int y, t_data *img, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j++ < y)
	{
		while (i < x)
			my_mlx_pixel_put(img, i++, j, color);
		i = 0;
	}
}

void	create_tile(int x, int y, t_data *img, int color)
{
	int	i;
	int	j;

	if (x - 5 <= 0 || y - 5 <= 0)
		exit(EXIT_FAILURE);
	create_rectangle(x, y, img, color);
	i = 5;
	j = 5;
	while (j++ < y - 5)
	{
		while (i < x - 5)
			my_mlx_pixel_put(img, i++, j, 0);
		i = 5;
	}
}

void	create_tiles(t_data *img, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(j < 10)
	{
		while (i < 10)
		{
			create_tile(100 * i++, 100 * j, img, color);
		}
		j++;
		i = 0;
	}
}


void	*create_img(void *mlx, char *path)
{
	t_data	img;
	int taille;
	int width;
	int height;

	width = 200;
	height = 200;
	img.img = mlx_xpm_file_to_image(mlx, path, &width , &height);
	if (img.img == NULL)
	{
		printf("CWEDFWE");
		exit(EXIT_FAILURE);
	}
	return(img.img);
}

void *create_wall(void *mlx, void *mlx_win)
{
	t_data	img;
	int	i;
	int	j;
	int max_i;
	int max_j;

	i = 0;
	j = 0;
	max_i = 8;
	max_j = 7;

	while(j <= max_j)
	{
		while (i <= max_i)
		{
			if ((i == max_i && j <=	 max_j) || (i <= max_i && j == max_j) || \
			(i == 0 && j <=	 max_j) || (i <= max_i && j == 0))
			{
				img.img = create_img(mlx, "Wall.xpm");
				mlx_put_image_to_window(mlx, mlx_win, img.img, i * 200, j * 200);
			}
			i++;
		}
		j++;
		i = 0;
	}
}



/*
int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
*/

t_data new_window(t_data img)
{
	int width;
	int	height;
	 
	width = 2500;
	height = 1600;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, width, height, "so_long");
	return (img);
}

int	main(void)
{
	t_data	img;
	
	img = new_window(img);

	create_wall(img.mlx, img.mlx_win);
	mlx_loop(img.mlx);
}
