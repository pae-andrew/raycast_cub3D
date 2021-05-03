/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:01:24 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/27 22:57:39 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main_loop(t_all *all)
{
	mlx_clear_window(all->win->mlx, all->win->win);
	check_update(all);
	draw_win(all);
	if (all->flag_save == 1)
		save_image(all);
	return (0);
}

void	init_tex(t_tex tex[5], t_all *all)
{
	tex[0].tex = mlx_xpm_file_to_image(all->win->mlx,
			all->fin_config->north, &tex[0].img_width, &tex[0].img_height);
	tex[0].addr = mlx_get_data_addr(tex[0].tex, &tex[0].bpp, &tex[0].line_l,
			&tex[0].en);
	tex[1].tex = mlx_xpm_file_to_image(all->win->mlx,
			all->fin_config->south, &tex[1].img_width, &tex[1].img_height);
	tex[1].addr = mlx_get_data_addr(tex[1].tex, &tex[1].bpp, &tex[1].line_l,
			&tex[1].en);
	tex[2].tex = mlx_xpm_file_to_image(all->win->mlx,
			all->fin_config->west, &tex[2].img_width, &tex[2].img_height);
	tex[2].addr = mlx_get_data_addr(tex[2].tex, &tex[2].bpp, &tex[2].line_l,
			&tex[2].en);
	tex[3].tex = mlx_xpm_file_to_image(all->win->mlx,
			all->fin_config->east, &tex[3].img_width, &tex[3].img_height);
	tex[3].addr = mlx_get_data_addr(tex[3].tex, &tex[3].bpp, &tex[3].line_l,
			&tex[3].en);
	tex[4].tex = mlx_xpm_file_to_image(all->win->mlx,
			all->fin_config->sprite, &tex[4].img_width, &tex[4].img_height);
	tex[4].addr = mlx_get_data_addr(tex[4].tex, &tex[4].bpp, &tex[4].line_l,
			&tex[4].en);
	all->tex[0] = &tex[0];
	all->tex[1] = &tex[1];
	all->tex[2] = &tex[2];
	all->tex[3] = &tex[3];
	all->tex[4] = &tex[4];
}

void	check_argv(int argc, char **argv)
{
	if (argc < 2)
		exit_with_error(0, "No map specified.");
	if (!(ft_strnstr(argv[1] + ft_strlen(argv[1]) - 4,
				".cub", ft_strlen(argv[1]))))
		exit_with_error(0, "Wrong map specified.");
}

int	run(t_all *all)
{
	mlx_hook(all->win->win, 2, (1L << 0), &key_press, all);
	mlx_hook(all->win->win, 3, (1L << 1), &key_release, all);
	mlx_hook(all->win->win, 17, 0, &exit_game, all);
	mlx_loop_hook(all->win->mlx, &main_loop, all);
	mlx_loop(all->win->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all			all;
	t_tex			tex[5];

	check_argv(argc, argv);
	if (argc == 3 && ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
		all.flag_save = 1;
	all.win = malloc(sizeof(t_win));
	all.win->mlx = mlx_init();
	all.config = malloc(sizeof(t_config));
	all.fin_config = malloc(sizeof(t_fin_config));
	all.plr = malloc(sizeof(t_plr));
	all.move = malloc(sizeof(t_move));
	init_mem(&all);
	all.map = get_map(argv[1], all.config);
	ft_init_player(all.map, all.plr);
	check_map(all.map, (int)(all.plr->posY),
		(int)(all.plr->posX), all.config->map_count);
	init_config(&all);
	init_win(&all);
	init_tex(tex, &all);
	all.move->move_speed = 2;
	run(&all);
	return (0);
}
