/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:55:41 by vbarbier          #+#    #+#             */
/*   Updated: 2022/05/30 02:37:37 by vbarbier         ###   ########.fr       */
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

//img.c
void	error_destroy_imgs(t_data *data, int cmp);
void	error_img(t_data *img, int cmp);
void	*load_img(void *asset, t_data *data, char *path);
void	load_imgs(t_data *data);
void	destroy_imgs(t_data *data);

//windows.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		win_close(t_data *img);
void	new_window(t_data *img);

//parsing.c
void	parsing(int ac, char **av);	

#endif