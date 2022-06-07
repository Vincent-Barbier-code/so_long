/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:59:45 by vbarbier          #+#    #+#             */
/*   Updated: 2022/06/07 07:06:18 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_player_i(t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data.map[j])
	{
		while (data.map[j][i])
		{
			if (data.map[j][i] == 'P')
				return (i);
			i++;
		}
		i = 0;
		j++;
	}
}

int	get_player_j(t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data.map[j])
	{
		while (data.map[j][i])
		{
			if (data.map[j][i] == 'P')
				return (j);
			i++;
		}
		i = 0;
		j++;
	}
}

int	get_collec(t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data.map[j])
	{
		while (data.map[j][i])
		{
			if (data.map[j][i] == 'C')
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
