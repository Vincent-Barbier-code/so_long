/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:57:51 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/29 23:41:41 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	*load_img(void *asset, t_data *data, char *path)
{
	int taille;
	int width;
	int height;

	width = 200;
	height = 200;
	asset = mlx_xpm_file_to_image(data->mlx, path, &width , &height);
	if (asset == NULL)
	{
		printf("Error chargement xpm");
		//error_img();
		exit(EXIT_FAILURE);
	}
	return(asset);
}

t_data	load_imgs(t_data *data)
{
	data->assets.wall = load_img(data->assets.wall, data, "Wall.xpm");
	data->assets.grid = load_img(data->assets.grid, data, "Grid.xpm");
	data->assets.player = load_img(data->assets.player, data, "Player.xpm");
	data->assets.exit = load_img(data->assets.exit, data, "Exit.xpm");
//	load_img(data.assets.wall, data.mlx, "Wall.xpm"); Ajouter collectible
	return (*data);
}

void	*create_wall(t_data data){
	int	i;
	int	j;
	int max_i;
	int max_j;

	i = 0;
	j = 0;
	max_i = 7;
	max_j = 7;
	while (j <= max_j)
	{
		while (i <= max_i)
		{
			if ((i == max_i && j <=	 max_j) || (i <= max_i && j == max_j) || \
			(i == 0 && j <=	 max_j) || (i <= max_i && j == 0))
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.assets.wall, i * 200, j * 200);
			i++;
		}
		j++;
		i = 0;
	}
}

t_data	destroy_imgs(t_data *data)
{
	if (data->assets.wall)
		mlx_destroy_image(data->mlx, data->assets.wall);
	if (data->assets.grid)
		mlx_destroy_image(data->mlx, data->assets.grid);
	if (data->assets.player)
		mlx_destroy_image(data->mlx, data->assets.player);
	if (data->assets.exit)
		mlx_destroy_image(data->mlx, data->assets.exit);
}

int	win_close(t_data *img)
{
	//mlx_destroy_image(img->mlx, img->img);
	//mlx_clear_window()
	destroy_imgs(img);
	//mlx_destroy_images(img->mlx);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	//FREE TOUT A FAIRE

	exit(0);
	return(0);
}

t_data	new_window(t_data *img)
{
	int width;
	int	height;
	 
	width = 2500;
	height = 1600;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, width, height, "so_long");
	//return (img);
}

int	key_hook(int key, t_data *img)
{
	if (key == ESC)
	{
		win_close(img);
		return (1);
	}
	return (0);
}

int	main(void)
{
	t_data	img;

	new_window(&img);
	load_imgs(&img);
	create_wall(img);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_hook(img.mlx_win, 17, 1L<<2, win_close, &img);
	mlx_loop(img.mlx);
}
