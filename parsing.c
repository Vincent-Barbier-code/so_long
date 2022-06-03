/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:20:22 by vbarbier          #+#    #+#             */
/*   Updated: 2022/06/03 18:40:15 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_parsing(int cas)
{
	if (cas == 0)
		ft_putstr_fd("error : nom fichier n est pas une map .ber", 2);
	if (cas == 1)
		ft_putstr_fd("error : le fichier n est pas un .ber", 2);
	if (cas == 2)
		ft_putstr_fd("error : nombres d arguments", 2);
	exit(EXIT_FAILURE);
}

void	parsing(int ac, char *av)
{
	char	*ber;
	int		len;

	ber = ".ber";
	if (ac == 2)
	{
		len = ft_strlen(av);
		if (len <= 4)
			error_parsing(0);
		while (len - 4)
		{
			len--;
			av++;
		}
		while (*av)
		{
			if (*av != *ber)
				error_parsing(1);
			av++;
			ber++;
		}
	}
	else
		error_parsing(2);
}
