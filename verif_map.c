/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:09:58 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/30 19:04:56 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int verif_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1')
		{
			ft_putstr_fd("error : Map non ferme par des murs", 1);
			win_close(data);
		}
		
		
		i++;
	}
}

int	verif_rect(char *str)
{
	static int	len_ligne = 0;
	static int	deb = 0;

	if (len_ligne != ft_strlen(str) && deb)
		return (0);
	len_ligne = ft_strlen(str);
	deb++;
	return (1);	
}

int	verif_nb (char *str)
{
	static int	collect = 0;
	static int	exit = 0;
	static int	player = 0;
	int			i;

	i = 0;
	while (str[i])
	{
		// Ajoute un cas pour le collectible 2 si j en rajoute
		if (str[i] == 'C')
			collect++;
		if (str[i] == 'E')
			exit++;
		if (str[i] == 'P')
			player++;
		i++;
	}
	if (collect > 0 && player == 1 && exit == 1)
		return (1);
	else
		return (0);
}

int	verif(char *str)
{
	static int flag = 1;
	if (!verif_rect(str))
		flag = 0;
	if (verif_nb(str) && flag)
		return (1);
	return (0);
}

void	error_map(t_data *img)
{
	ft_putstr_fd("error : map non prise en charge", 1);
	destroy_imgs(img);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(EXIT_FAILURE);
}

int	ligne_verif(char *nom, t_data *data)
{
	int		ligne;
	int		fd;
	char	*str;
	int		ok;

	ligne = 0;
	fd = open(nom, O_RDONLY);
	ok = 1;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
		{
			if (!ok)
			{
				free(str);
				close(fd);
				error_map(data);
			}
			free(str);
			close(fd);
			return (ligne);
		}
		ok = verif(str);
		ligne++;
		free(str);
	}
}
