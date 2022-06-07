/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:09:58 by vbarbier          #+#    #+#             */
/*   Updated: 2022/06/07 08:14:21 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[0][i] != '1' && i < max_i(data))
				error_wall(data);
			if (data->map[j][0] != '1')
				error_wall(data);
			if (data->map[max_j(data)][i] != '1' && i < max_i(data))
				error_wall(data);
			if (data->map[j][max_i(data) - 1] != '1')
				error_wall(data);
			i++;
		}
		j++;
	}
}

static int	verif_nb(char *str)
{
	static int	collect = 0;
	static int	exit = 0;
	static int	player = 0;
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			collect++;
		else if (str[i] == 'E')
			exit++;
		else if (str[i] == 'P')
			player++;
		else if (str[i] == '1' || str[i] == '0' || str[i] == '\n')
			;
		else
			return (0);
		i++;
	}
	if (collect > 0 && player == 1 && exit == 1)
		return (1);
	else
		return (0);
}

static int	verif(char *str)
{
	static int	flag = 1;

	if (!verif_rect(str))
		flag = 0;
	if (verif_nb(str) && flag)
		return (1);
	return (0);
}

static void	suite_lv(int ok, char *str, int fd, t_data *data)
{
	if (!ok)
	{
		free(str);
		close(fd);
		error_map(data);
	}
	free(str);
	close(fd);
}

int	ligne_verif(char *nom, t_data *data)
{
	int		ligne;
	int		fd;
	char	*str;
	int		ok;

	ligne = 0;
	fd = open(nom, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
		{
			suite_lv(ok, str, fd, data);
			return (ligne);
		}
		ok = verif(str);
		ligne++;
		free(str);
	}
}
