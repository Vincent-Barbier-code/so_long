/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:55:41 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/29 20:09:53 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 65307
# define LEFT 65361
# define TOP 65362
# define RIGHT 65363
# define BOT 65364

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mlx.h"

typedef struct s_assets
{
    void     *grid;
    void     *wall;
    void     *player;
    void     *collec1;
    void     *collec2;
    void     *exit;
}    t_assets;

typedef struct	s_data {
	void		*mlx;
	void		*mlx_win;
	t_assets	assets;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
//	int			endian;
}				t_data;

#endif