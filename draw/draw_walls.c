/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:25:51 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/18 14:15:23 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	side_1(t_walls *walls, t_all *all)
{
	if (walls->rayDirY < 0)
	{
		my_mlx_pixel_put(all->win, walls->x, walls->y,
			get_color(all->tex[0], walls->texX, walls->texY));
	}
	else
	{
		my_mlx_pixel_put(all->win, walls->x, walls->y,
			get_color(all->tex[1], walls->texX, walls->texY));
	}
}

void	side_0(t_walls *walls, t_all *all)
{
	if (walls->rayDirX < 0)
	{
		my_mlx_pixel_put(all->win, walls->x, walls->y,
			get_color(all->tex[2], walls->texX, walls->texY));
	}
	else
	{
		my_mlx_pixel_put(all->win, walls->x, walls->y,
			get_color(all->tex[3], walls->texX, walls->texY));
	}
}

void	draw_texs(t_walls *walls, t_all *all)
{
	while (walls->y <= walls->drawEnd)
	{
		walls->texY = (int) walls->texPos & (all->tex[0]->img_height - 1);
		if (walls->side == 1)
			side_1(walls, all);
		else
			side_0(walls, all);
		walls->texPos += walls->step;
		walls->y++;
	}
}

int	draw_walls(t_all *all, t_plr *pl)
{
	t_walls	walls;

	walls.x = -1;
	while (++walls.x < all->fin_config->res_x)
	{
		init_walls(&walls, all, pl);
		what_wall(&walls, pl);
		ray_cast(&walls, all);
		wall_distance(&walls, all, pl);
		if (walls.side == 1 && walls.rayDirY < 0)
			walls.texX = all->tex[0]->img_width - walls.texX - 1;
		walls.step = 1.0 * all->tex[0]->img_height / walls.lineHeight;
		walls.texPos = (walls.drawStart - (all->fin_config->res_y - 2)
				/ 2 + walls.lineHeight / 2) * walls.step;
		draw_texs(&walls, all);
		pl->ZBuffer[walls.x] = walls.perpWallDist;
	}
	return (0);
}
