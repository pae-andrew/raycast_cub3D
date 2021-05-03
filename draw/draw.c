/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:10:26 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/28 00:49:40 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_draw_map(t_win *win, t_point *point, int i)
{
	t_point	end;

	ft_bzero(&end, sizeof(t_point));
	end.x = (point->x + 1) * SCALE;
	end.y = (point->y + 1) * SCALE;
	point->x *= SCALE;
	point->y *= SCALE;
	while (point->y < end.y)
	{
		while (point->x < end.x)
		{
			if (i == 1)
				my_mlx_pixel_put(win, point->x++, point->y,
					create_trgb(0, 11, 208, 233));
			else
				my_mlx_pixel_put(win, point->x++, point->y,
					create_trgb(0, 0, 0, 0));
		}
		point->x -= SCALE;
		point->y++;
	}
	point->y -= SCALE;
	point->y /= SCALE;
	point->x /= SCALE;
	return (0);
}

void	make_floor_and_sky(t_win *win, t_fin_config *fin_config)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= fin_config->res_y / 2)
	{
		x = -1;
		while (++x <= fin_config->res_x)
			my_mlx_pixel_put(win, x, y, fin_config->sky);
	}
	while (y <= fin_config->res_y - 2)
	{
		x = -1;
		while (++x <= fin_config->res_x)
			my_mlx_pixel_put(win, x, y, fin_config->floor);
		y++;
	}
}

int	draw_plr(t_win *win, t_plr *plr)
{
	t_plr	pl;

	ft_bzero(&pl, sizeof(t_plr));
	pl.posX = (plr->posX + 1) * SCALE;
	pl.posY = (plr->posY + 1) * SCALE;
	plr->posX *= SCALE;
	plr->posY *= SCALE;
	while (plr->posY < pl.posY)
	{
		while (plr->posX < pl.posX)
			my_mlx_pixel_put(win, plr->posX++, plr->posY,
				create_trgb(0, 250, 0, 0));
		plr->posX -= SCALE;
		plr->posY++;
	}
	plr->posY -= SCALE;
	plr->posY /= SCALE;
	plr->posX /= SCALE;
	return (0);
}

int	draw_win(t_all *all)
{
	t_point	point;

	ft_bzero(&point, sizeof(t_point));
	point.y = 0;
	make_floor_and_sky(all->win, all->fin_config);
	draw_walls(all, all->plr);
	draw_sprites(all, all->plr);
	while (point.y < all->config->map_count)
	{
		point.x = 0;
		while (all->map[point.y][point.x])
		{
			if (all->map[point.y][point.x] == '1')
				ft_draw_map(all->win, &point, 1);
			else
				ft_draw_map(all->win, &point, 0);
			point.x++;
		}
		point.y++;
	}
	draw_plr(all->win, all->plr);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	mlx_do_sync(all->win->mlx);
	return (0);
}
