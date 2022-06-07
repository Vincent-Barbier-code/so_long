/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:57:51 by vbarbier          #+#    #+#             */
/*   Updated: 2022/06/07 07:01:41 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_data *img)
{
	static int	i = 0;

	if (key == ESC)
	{
		win_close(img);
		return (1);
	}
	if (key == TOP)
	{
		i = move_top(img, i);
		aff_map(img);
	}
	if (key == BOT)
	{
		i = move_bot(img, i);
		aff_map(img);
	}
	if (key == LEFT)
	{
		i = move_left(img, i);
		aff_map(img);
	}
	if (key == RIGHT)
	{
		i = move_right(img, i);
		aff_map(img);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	img;
	int		ligne;

	parsing(ac, av[1]);
	new_window(&img);
	load_imgs(&img);
	ligne = ligne_verif(av[1], &img);
	init_map(&img, av[1], ligne);
	verif_wall(&img);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_hook(img.mlx_win, 17, 1L << 2, win_close, &img);
	mlx_loop(img.mlx);
}
