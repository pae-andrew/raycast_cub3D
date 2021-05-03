/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:01:55 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/27 22:02:54 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "draw/draw.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <math.h>

# define SCALE 5

typedef struct s_move {
	int		move_forward;
	int		move_back;
	int		move_right;
	int		move_left;
	int		rot_left;
	int		rot_right;
	int		move_speed;
}			t_move;

typedef struct s_tex {
	void		*tex;
	char		*addr;
	int			bpp;
	int			line_l;
	int			en;
	int			img_width;
	int			img_height;
}				t_tex;

typedef struct s_plr {
	float	posX;
	float	posY;
	float	dirX;
	float	dirY;
	float	dir;
	float	planeX;
	float	planeY;
	float	start;
	float	end;
	float	ZBuffer[16384];
	int		count_sprites;
	float	sprite_y[100];
	float	sprite_x[100];
	int		count;
}			t_plr;

typedef struct s_point
{
	int		x;
	int		y;
	float	oldDirX;
	float	oldPlaneX;
}			t_point;

typedef struct s_win {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		en;
}			t_win;

typedef struct s_config {
	char	*resolution;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	char	*floor;
	char	*sky;
	int		map_count;
}			t_config;

typedef struct s_fin_config {
	char	*north;
	char	*west;
	char	*east;
	char	*south;
	char	*sprite;
	int		sky;
	int		floor;
	int		res_x;
	int		res_y;
}			t_fin_config;

typedef struct s_all
{
	t_move			*move;
	t_tex			*tex[5];
	t_win			*win;
	t_plr			*plr;
	t_config		*config;
	t_fin_config	*fin_config;
	char			**map;
	int				start_map;
	int				flag_save;
}					t_all;

int		draw_walls(t_all *all, t_plr *pl);
int		draw_sprites(t_all *all, t_plr *pl);
int		ft_draw_map(t_win *win, t_point *point, int i);
void	make_floor_and_sky(t_win *win, t_fin_config *fin_config);
int		draw_plr(t_win *win, t_plr *plr);
int		draw_win(t_all *all);
void	wall_distance(t_walls *walls, t_all *all, t_plr *pl);
void	ray_cast(t_walls *walls, t_all *all);
void	what_wall(t_walls *walls, t_plr *pl);
void	init_walls(t_walls *walls, t_all *all, t_plr *pl);

int		create_trgb(int t, int r, int g, int b);
int		get_color(t_tex *data, int x, int y);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
int		*sortSprites(int order[], float dist[], int amount);

int		exit_game(t_all *all);
int		exit_with_error(int i, char *str);

int		check_update(t_all *all);
int		key_press(int key, t_all *all);
int		key_release(int key, t_all *all);
int		main_loop(t_all *all);

int		make_config(char **map, t_config *config);
char	**parse_map(t_list **head, int size, t_config *config);
char	**get_map(char *argv, t_config *config);
int		check_map(char **map, int y, int x, int i);
int		ft_drawcub(int x, int drawStart, int drawEnd, t_win *win);

void	init_tex(t_tex tex[5], t_all *all);
void	init_win(t_all *all);
void	init_mem(t_all *all);

void	move_forward(t_all *all);
void	move_back(t_all *all);
void	move_right(t_all *all);
void	move_left(t_all *all);
void	rot_left(t_all *all);
void	rot_right(t_all *all);

void	check_config(t_fin_config *config, t_all *all);
int		init_config(t_all *all);
int		init_config_texs1(t_all *all);
int		init_config_texs2(t_all *all);
void	ft_init_player(char **map, t_plr *plr);
void	map_S(t_plr *plr, t_point *pos);
void	map_E(t_plr *plr);
void	map_W(t_plr *plr, t_point *pos);
void	map_N(t_plr *plr, t_point *pos);

void	save_image(t_all *all);

#endif