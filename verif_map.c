/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:09:58 by vbarbier          #+#    #+#             */
/*   Updated: 2022/06/01 00:40:35 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	max_j(t_data *data)
{
	int	j;

	j = 0;
	while (data->map[j])
	{
		j++;
	}
	return (j - 1);
}

int	max_i(t_data *data)
{
	return (ft_strlen(data->map[0]) - 1);
}

void	error_wall(t_data *data)
{
	ft_putstr_fd("error : Map non ferme par des murs", 1);
	win_close(data);
}

int verif_wall(t_data *data)
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
		else if (str[i] == 'E')
			exit++;
		else if (str[i] == 'P')
			player++;
		else if (str[i] == '1' || str[i] == '0' || str[i] == '\n')
			;
		else
		{
			printf("str = %c", str[i]);
			return (0);
		}
		i++;
	}
	if (collect > 0 && player == 1 && exit == 1)
		return (1);
	else
		return (0);
}

int	verif(char *str)
{
	static int	flag = 1;

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

void	suite_lv(int ok, char *str, int fd, t_data *data)
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
			return(ligne);
		}
		ok = verif(str);
		ligne++;
		free(str);
	}
}
