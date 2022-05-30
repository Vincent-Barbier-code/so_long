/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:59:00 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/30 14:06:22 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

int	win_close(t_data *img)
{
	destroy_imgs(img);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	free_map(img);
	exit(0);
	return (0);
}

void	new_window(t_data *img)
{
	int	width;
	int	height;

	width = 2800;
	height = 1600;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, width, height, "so_long");
}
