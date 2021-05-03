/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:03:35 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/18 19:09:15 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_resolution(t_fin_config *config, t_all *all)
{
	int	x;
	int	y;

	mlx_get_screen_size(all->win->mlx, &x, &y);
	if (config->res_x > x)
		config->res_x = x;
	if (config->res_y >= y)
		config->res_y = y;
	if (config->res_x < 300)
		config->res_x = 300;
	if (config->res_y < 300)
		config->res_y = 300;
}

void	check_config(t_fin_config *config, t_all *all)
{
	if (!(ft_strnstr(config->north + ft_strlen(config->north) - 4,
				".xpm", ft_strlen(config->north)))
		|| !(ft_strnstr(config->south + ft_strlen(config->south) - 4,
				".xpm", ft_strlen(config->south)))
		|| !(ft_strnstr(config->east + ft_strlen(config->east) - 4,
				".xpm", ft_strlen(config->east)))
		|| !(ft_strnstr(config->west + ft_strlen(config->west) - 4,
				".xpm", ft_strlen(config->west)))
		|| !(ft_strnstr(config->sprite + ft_strlen(config->sprite) - 4,
				".xpm", ft_strlen(config->sprite))))
		exit_with_error(0, "Wrong textures");
	if (read(open(config->north, O_RDONLY), NULL, 0) < 0
		|| read(open(config->south, O_RDONLY), NULL, 0) < 0
		|| read(open(config->east, O_RDONLY), NULL, 0) < 0
		|| read(open(config->west, O_RDONLY), NULL, 0) < 0
		|| read(open(config->sprite, O_RDONLY), NULL, 0) < 0)
		exit_with_error(0, "Wrong textures");
	if (config->res_x <= 0 || config->res_y <= 0)
		exit_with_error(0, "Wrong resolution");
	check_resolution(config, all);
}
