/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:28:02 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/30 04:14:49 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1

static int	ft_read_buf(int fd, char **str)
{
	char		*buf;
	int			i;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	i = 1;
	while (!ft_strchr(*str, '\n') && i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (-1);
		}
		buf[i] = '\0';
		*str = ft_strjoin(*str, buf);
	}
	free(buf);
	return (i);
}

static char	*ft_get_line(char **str)
{
	char	*line;
	char	*strcp;
	int		i;

	i = 0;
	while (*str && str[0][i] != '\n')
		i++;
	strcp = *str;
	line = ft_substr(strcp, 0, i + 1);
	*str = ft_substr(ft_strchr(strcp, '\n'), 1, ft_strlen(strcp));
	free(strcp);
	strcp = NULL;
	return (line);
}

static char	*ft_new_line(char **str, int fd)
{
	char	*strcp;
	int		i;

	if (ft_strchr(*str, '\n'))
		return (ft_get_line(str));
	i = ft_read_buf(fd, str);
	if ((i == -1 || i == 0) && !**str)
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	if (ft_strchr(*str, '\n'))
		return (ft_get_line(str));
	if (**str)
	{
		strcp = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (strcp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*strcp;

	if (!str)
		str = ft_strdup("");
	if (fd >= 0 && BUFFER_SIZE > 0)
		strcp = ft_new_line(&str, fd);
	else
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (strcp);
}
