/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:38:26 by vbarbier          #+#    #+#             */
/*   Updated: 2022/06/07 08:28:43 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_top(t_data *data, int move)
{
	int	pi;
	int	pj;

	pi = get_player_i(*data);
	pj = get_player_j(*data);
	if ((*data).map[pj - 1][pi] == 'E' && !get_collec(*data))
		win_close(data);
	if ((*data).map[pj - 1][pi] != '1' && (*data).map[pj - 1][pi] != 'E')
	{
		(*data).map[pj - 1][pi] = 'P';
		(*data).map[pj][pi] = '0';
		move++;
		ft_printf("nombre move = %d \n", move);
	}
	return (move);
}

int	move_bot(t_data *data, int move)
{
	int	pi;
	int	pj;

	pi = get_player_i(*data);
	pj = get_player_j(*data);
	if ((*data).map[pj + 1][pi] == 'E' && !get_collec(*data))
		win_close(data);
	if ((*data).map[pj + 1][pi] != '1' && (*data).map[pj + 1][pi] != 'E')
	{
		(*data).map[pj + 1][pi] = 'P';
		(*data).map[pj][pi] = '0';
		move++;
		ft_printf("nombre move = %d \n", move);
	}
	return (move);
}

int	move_left(t_data *data, int move)
{
	int	pi;
	int	pj;

	pi = get_player_i(*data);
	pj = get_player_j(*data);
	if ((*data).map[pj][pi - 1] == 'E' && !get_collec(*data))
		win_close(data);
	if ((*data).map[pj][pi - 1] != '1' && (*data).map[pj][pi - 1] != 'E')
	{
		(*data).map[pj][pi - 1] = 'P';
		(*data).map[pj][pi] = '0';
		move++;
		ft_printf("nombre move = %d \n", move);
	}
	return (move);
}

int	move_right(t_data *data, int move)
{
	int	pi;
	int	pj;

	pi = get_player_i(*data);
	pj = get_player_j(*data);
	if ((*data).map[pj][pi + 1] == 'E' && !get_collec(*data))
		win_close(data);
	if ((*data).map[pj][pi + 1] != '1' && (*data).map[pj][pi + 1] != 'E')
	{
		(*data).map[pj][pi + 1] = 'P';
		(*data).map[pj][pi] = '0';
		move++;
		ft_printf("nombre move = %d \n", move);
	}
	return (move);
}
