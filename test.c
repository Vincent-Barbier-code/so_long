/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:57:51 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/30 03:49:31 by vbarbier         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data	img;

	parsing(ac, av);
	new_window(&img);
	load_imgs(&img);
	create_wall(img);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_hook(img.mlx_win, 17, 1L << 2, win_close, &img);
	mlx_loop(img.mlx);
}
