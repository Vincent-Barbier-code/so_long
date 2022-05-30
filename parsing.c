/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:20:22 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/30 02:57:01 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	error_parsing(int cas)
{
	if (cas == 0)
		printf("error : nom fichier n est pas une map .ber");
	if (cas == 1)
		printf("error : le fichier n est pas un .ber");
	if (cas == 2)
		printf("error : nombres d arguments");
	exit(0);
}

void	parsing(int ac, char **av)
{
	char	*ber;
	int		len;

	len = ft_strlen(av[1]);
	ber = ".ber";
	if (ac != 1)
	{
		if (len <= 4)
			error_parsing(0);
		while (len - 4)
		{
			len--;
			av[1]++;
		}
		while (*av[1])
		{
			av[1]++;
			ber++;
			if (*av[1] != *ber)
				error_parsing(1);
		}
	}
	else
		error_parsing(2);
}
