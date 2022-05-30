/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:20:22 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/30 03:43:52 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_parsing(int cas)
{
	if (cas == 0)
		ft_putstr_fd("error : nom fichier n est pas une map .ber", 1);
	if (cas == 1)
		ft_putstr_fd("error : le fichier n est pas un .ber", 1);
	if (cas == 2)
		ft_putstr_fd("error : nombres d arguments", 1);
	exit(0);
}

void	parsing(int ac, char **av)
{
	char	*ber;
	int		len;

	ber = ".ber";
	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		if (len <= 4)
			error_parsing(0);
		while (len - 4)
		{
			len--;
			av[1]++;
		}
		while (*av[1])
		{
			if (*av[1] != *ber)
				error_parsing(1);
			av[1]++;
			ber++;
		}
	}
	else
		error_parsing(2);
}
