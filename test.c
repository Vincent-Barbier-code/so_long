#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mlx.h"


typedef struct	s_game {
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
void	create_img(void *mlx, int img_width, int img_height)
{
	//void	*img;
	char	*relative_path = "./D.png";

	mlx_xpm_file_to_image(&mlx, relative_path, &img_width, &img_height);
	
}

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data	img2;
//	struct t_point p_hg;
//	struct t_point p_bd;
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	img.img = mlx_new_image(mlx, 1920, 1080);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img2.img = create_img(mlx, 400, 900);
	
//	create_tile(100, 100, &img, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img2.img, 0, 0);

	close(27, )
	mlx_loop(mlx);
}
