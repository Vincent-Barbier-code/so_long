/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:57:51 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/30 06:00:11 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*create_wall(t_data data)
{
	int	i;
	int	j;
	int	max_i;
	int	max_j;

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

int	key_hook(int key, t_data *img)
{
	if (key == ESC)
	{
		win_close(img);
		return (1);
	}
	return (0);
}

void	*who_asset(t_data *data, char *str)
{
	void *asset;

	printf("%c",*str);
	if (*str == '1')
		asset = data->assets.wall;
	if (*str == '0')
		asset = data->assets.grid;
//	if (*str == "C") // Ajouter collectibles
	if (*str == 'E')
		asset = data->assets.exit;
	if (*str == 'P')
		asset = data->assets.player;
	return (asset);
}

void	new_map(t_data data, char *str)
{
	int	i;
	static int	j = 0;
	void *asset;

	i = 0;
	while (*str)
	{
		printf("%c",*str);
		if (*str == '1')
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.assets.wall, i * 200, j * 200);
		if (*str == '0')
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.assets.grid, i * 200, j * 200);
	//	if (*str == "C") // Ajouter collectibles
		if (*str == 'E')
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.assets.exit, i * 200, j * 200);
		if (*str == 'P')
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.assets.player, i * 200, j * 200);
		str++;
		i++;
	}
	printf("%c",*str);
	j++;
}

int	main(int ac, char **av)
{
	t_data	img;
	int		fd;
	char	*str;

	parsing(ac, av[1]);
	new_window(&img);
	load_imgs(&img);
	//create_wall(img);
	fd = open(av[1], O_RDONLY);
	while(str = get_next_line(fd))
	{
		new_map(img, str);	
	}

	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_hook(img.mlx_win, 17, 1L << 2, win_close, &img);
	mlx_loop(img.mlx);
}
