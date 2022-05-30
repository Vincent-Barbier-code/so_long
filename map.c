/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:33:31 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/30 14:37:48 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*who_asset(t_data data, char c)
{
	void	*asset;

	if (c == '1')
		asset = data.assets.wall;
	if (c == '0')
		asset = data.assets.grid;
//	if (c == "C") // Ajouter collectibles
	if (c == 'E')
		asset = data.assets.exit;
	if (c == 'P')
		asset = data.assets.player;
	return (asset);
}

char	*new_map(t_data data, char *str)
{
	int			i;
	static int	j = 0;
	void		*asset;

	i = 0;
	while (str[i])
	{
		asset = who_asset(data, str[i]);
		mlx_put_image_to_window(data.mlx, data.mlx_win, asset, i * 200, j * 200);	
		i++;
	}
	j++;
	return (str);
}

int	cmp_ligne(char *nom)
{
	int ligne;
	int		fd;
	char *str;

	ligne = 1;
	fd = open(nom, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
		{
			close(fd);
			return (ligne);
		}
		ligne++;
		free (str);
	}
}

void init_map(t_data *data, char *nom, int ligne)
{
	int		fd;
	char	*str;
	int		i;
	i = 0;
	fd = open(nom, O_RDONLY);
	data->map = malloc (sizeof(data->map) * ligne);	
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
		{
			data->map[i] = '\0';
			close(fd);
			return ;
		}
		data->map[i] = ft_strdup(new_map(*data, str));
		free(str);
		printf("%s", data->map[i]);
		i++;
	}
}