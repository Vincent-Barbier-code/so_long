/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:38:26 by vbarbier          #+#    #+#             */
/*   Updated: 2022/06/01 01:28:12 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_top(t_data *data, int move)
{
	int	Pi;
	int Pj;

	Pi = get_player_i(*data);
	Pj = get_player_j(*data);
	if ((*data).map[Pj - 1][Pi] == 'E' && !get_collec(*data))
		win_close(data);
	if ((*data).map[Pj - 1][Pi] != '1' && (*data).map[Pj - 1][Pi] != 'E')
	{
		(*data).map[Pj - 1][Pi] = 'P';
		(*data).map[Pj][Pi] = '0';
		move++;
		printf("nombre move = %d \n", move);
	}
	return (move);
}

int	move_bot(t_data *data, int move)
{
	int	Pi;
	int Pj;

	Pi = get_player_i(*data);
	Pj = get_player_j(*data);
	if ((*data).map[Pj + 1][Pi] == 'E' && !get_collec(*data))
		win_close(data);
	if ((*data).map[Pj + 1][Pi] != '1' && (*data).map[Pj + 1][Pi] != 'E')
	{
		(*data).map[Pj + 1][Pi] = 'P';
		(*data).map[Pj][Pi] = '0';
		move++;
		printf("nombre move = %d \n", move);
	}
	return (move);
}

int	move_left(t_data *data, int move)
{
	int	Pi;
	int Pj;

	Pi = get_player_i(*data);
	Pj = get_player_j(*data);
	if ((*data).map[Pj][Pi - 1] == 'E' && !get_collec(*data))
		win_close(data);
	if ((*data).map[Pj][Pi - 1] != '1' && (*data).map[Pj][Pi - 1] != 'E')
	{
		(*data).map[Pj][Pi - 1] = 'P';
		(*data).map[Pj][Pi] = '0';
		move++;
		printf("nombre move = %d \n", move);
	}
	return (move);
}

int	move_right(t_data *data, int move)
{
	int	Pi;
	int Pj;

	Pi = get_player_i(*data);
	Pj = get_player_j(*data);
	if ((*data).map[Pj][Pi + 1] == 'E' && !get_collec(*data))
		win_close(data);
	if ((*data).map[Pj][Pi + 1] != '1' && (*data).map[Pj][Pi + 1] != 'E')
	{
		(*data).map[Pj][Pi + 1] = 'P';
		(*data).map[Pj][Pi] = '0';
		move++;
		printf("nombre move = %d \n", move);
	}
	return (move);
}