/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:57:51 by vbarbier          #+#    #+#             */
/*   Updated: 2022/06/07 08:04:23 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

enum e_move {top, bot, left, right};

int	move_player(t_data *data, int i, int cas)
{
	if (cas == top)
		return (move_top(data, i));
	if (cas == bot)
		return (move_bot(data, i));
	if (cas == left)
		return (move_left(data, i));
	if (cas == right)
		return (move_right(data, i));
}

int	key_hook(int key, t_data *data)
{
	static int	i = 0;

	if (key == ESC)
	{
		win_close(data);
		return (1);
	}
	if (key == TOP)
		i = move_player(data, i, top);
	if (key == BOT)
		i = move_player(data, i, bot);
	if (key == LEFT)
		i = move_player(data, i, left);
	if (key == RIGHT)
		i = move_player(data, i, right);
	aff_map(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		ligne;

	parsing(ac, av[1]);
	new_window(&data);
	load_imgs(&data);
	ligne = ligne_verif(av[1], &data);
	init_map(&data, av[1], ligne);
	verif_wall(&data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_hook(data.mlx_win, 17, 1L << 2, win_close, &data);
	mlx_loop(data.mlx);
}
