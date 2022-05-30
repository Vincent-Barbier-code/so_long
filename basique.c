/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basique.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 03:38:19 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/30 03:59:53 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}