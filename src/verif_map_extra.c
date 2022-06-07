/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 07:36:10 by vbarbier          #+#    #+#             */
/*   Updated: 2022/06/07 11:19:02 by vbarbier         ###   ########.fr       */
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
	ft_putstr_fd("error : Map non ferme par des murs", 2);
	win_close(data);
}

void	error_map(t_data *img)
{
	ft_putstr_fd("error : map non prise en charge", 2);
	destroy_imgs(img);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(EXIT_FAILURE);
}

int	verif_rect(char *str)
{
	static size_t	len_ligne = 0;
	static int		deb = 0;

	if (len_ligne != ft_strlen(str) && deb)
		return (0);
	len_ligne = ft_strlen(str);
	deb++;
	return (1);
}
