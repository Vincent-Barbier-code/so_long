/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:55:50 by vbarbier          #+#    #+#             */
/*   Updated: 2022/06/07 11:25:49 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_destroy_imgs(t_data *data, int cmp)
{
	if (cmp > 0)
		mlx_destroy_image(data->mlx, data->assets.wall);
	if (cmp > 1)
		mlx_destroy_image(data->mlx, data->assets.grid);
	if (cmp > 2)
		mlx_destroy_image(data->mlx, data->assets.player);
	if (cmp > 3)
		mlx_destroy_image(data->mlx, data->assets.exit);
	if (cmp > 4)
		mlx_destroy_image(data->mlx, data->assets.collec1);
}

void	error_img(t_data *img, int cmp)
{
	error_destroy_imgs(img, cmp);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(1);
}

void	*load_img(void *asset, t_data *data, char *path)
{
	int			width;
	int			height;
	static int	cmp = 0;

	width = 200;
	height = 200;
	asset = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	if (asset == NULL)
	{
		ft_putstr_fd("error : chargement image xpm", 2);
		error_img(data, cmp);
		exit(EXIT_FAILURE);
	}
	cmp++;
	return (asset);
}

void	load_imgs(t_data *data)
{
	data->assets.wall = load_img(data->assets.wall, data, "./img/Wall.xpm");
	data->assets.grid = load_img(data->assets.grid, data, "./img/Grid.xpm");
	data->assets.player = \
	load_img(data->assets.player, data, "./img/Player.xpm");
	data->assets.exit = load_img(data->assets.exit, data, "./img/Exit.xpm");
	data->assets.collec1 = \
	load_img(data->assets.collec1, data, "./img/Collec.xpm");
}

void	destroy_imgs(t_data *data)
{
	if (data->assets.wall)
		mlx_destroy_image(data->mlx, data->assets.wall);
	if (data->assets.grid)
		mlx_destroy_image(data->mlx, data->assets.grid);
	if (data->assets.player)
		mlx_destroy_image(data->mlx, data->assets.player);
	if (data->assets.exit)
		mlx_destroy_image(data->mlx, data->assets.exit);
	if (data->assets.collec1)
		mlx_destroy_image(data->mlx, data->assets.collec1);
}
