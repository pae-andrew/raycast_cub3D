/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:00:10 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/28 00:22:08 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_win(t_all *all)
{
	all->win->win = mlx_new_window(all->win->mlx, all->fin_config->res_x,
			all->fin_config->res_y, "Dron's Cub3D");
	all->win->img = mlx_new_image(all->win->mlx, all->fin_config->res_x,
			all->fin_config->res_y);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bpp,
			&all->win->line_l, &all->win->en);
}

int	init_config_texs2(t_all *all)
{
	int		i;

	i = 2;
	while (all->config->east[i] == ' ')
		i++;
	all->fin_config->east = ft_strdup(all->config->east + i);
	i = 2;
	while (all->config->sprite[i] == ' ')
		i++;
	all->fin_config->sprite = ft_strdup(all->config->sprite + i);
	return (0);
}

int	init_config_texs1(t_all *all)
{
	int		i;

	i = 2;
	while (all->config->south[i] == ' ')
		i++;
	all->fin_config->south = ft_strdup(all->config->south + i);
	i = 2;
	while (all->config->west[i] == ' ')
		i++;
	all->fin_config->west = ft_strdup(all->config->west + i);
	i = 2;
	while (all->config->north[i] == ' ')
		i++;
	all->fin_config->north = ft_strdup(all->config->north + i);
	return (init_config_texs2(all));
}

void	init_resolution(t_fin_config *fin_config, t_config *config)
{
	int		i;

	fin_config->res_x = ft_atoi(config->resolution);
	i = 1;
	while (config->resolution[i] == ' ')
		i++;
	while (config->resolution[i] >= 48 && config->resolution[i] <= 57)
		i++;
	fin_config->res_y = ft_atoi(config->resolution + i);
	if (config->resolution[i] > 32)
		exit_with_error(0, "Wrong resolution");
}

int	init_config(t_all *all)
{
	char	**floor;
	char	**sky;

	init_resolution(all->fin_config, all->config);
	floor = ft_split(all->config->floor, ',');
	sky = ft_split(all->config->sky, ',');
	if (!floor[0] || !floor[1] || !floor[2] || floor[3])
		exit_with_error(0, "Wrong color of floor");
	if (!sky[0] || !sky[1] || !sky[2] || sky[3])
		exit_with_error(0, "Wrong color of sky");
	all->fin_config->sky = create_trgb(0, ft_atoi(sky[0]),
			ft_atoi(sky[1]), ft_atoi(sky[2]));
	all->fin_config->floor = create_trgb(0, ft_atoi(floor[0]),
			ft_atoi(floor[1]), ft_atoi(floor[2]));
	init_config_texs1(all);
	free(all->config);
	check_config(all->fin_config, all);
	return (0);
}
