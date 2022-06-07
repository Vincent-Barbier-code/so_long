/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarbier <vbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:55:41 by vbarbier          #+#    #+#             */
/*   Updated: 2022/06/07 08:29:24 by vbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 65307
# define LEFT 65361
# define TOP 65362
# define RIGHT 65363
# define BOT 65364

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>

typedef struct s_assets
{
	void	*grid;
	void	*wall;
	void	*player;
	void	*collec1;
	void	*collec2;
	void	*exit;
}	t_assets;

typedef struct s_data {
	void		*mlx;
	void		*mlx_win;
	char		**map;
	t_assets	assets;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
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
void	parsing(int ac, char *av);

//basique.c
int		ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);

//map.c
void	aff_map(t_data *data);
char	*new_map(t_data data, char *str);
void	init_map(t_data *data, char *nom, int ligne);

//free_map.c
void	free_map(t_data *data);

//verif_map.c
int		verif_wall(t_data *data);
int		ligne_verif(char *nom, t_data *data);

//verif_map_extra.c
int		max_j(t_data *data);
int		max_i(t_data *data);
void	error_wall(t_data *data);
void	error_map(t_data *img);
int		verif_rect(char *str);

//move_player.c
int		move_top(t_data *data, int move);
int		move_bot(t_data *data, int move);
int		move_left(t_data *data, int move);
int		move_right(t_data *data, int move);

//where_player.c
int		get_player_i(t_data data);
int		get_player_j(t_data data);
int		get_collec(t_data data);

#endif