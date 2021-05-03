/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:13:33 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/18 14:15:13 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_walls(t_walls *walls, t_all *all, t_plr *pl)
{
	walls->cameraX = 2 * walls->x / (float)all->fin_config->res_x - 1;
	walls->rayDirX = pl->dirX + pl->planeX * walls->cameraX;
	walls->rayDirY = pl->dirY + pl->planeY * walls->cameraX;
	walls->mapX = (int)(pl->posX);
	walls->mapY = (int)(pl->posY);
	walls->deltaDistX = fabs(1 / walls->rayDirX);
	walls->deltaDistY = fabs(1 / walls->rayDirY);
	walls->hit = 0;
}

void	what_wall(t_walls *walls, t_plr *pl)
{
	if (walls->rayDirX < 0)
	{
		walls->stepX = -1;
		walls->sideDistX = (pl->posX - walls->mapX) * walls->deltaDistX;
	}
	else
	{
		walls->stepX = 1;
		walls->sideDistX = (walls->mapX + 1.0 - pl->posX) * walls->deltaDistX;
	}
	if (walls->rayDirY < 0)
	{
		walls->stepY = -1;
		walls->sideDistY = (pl->posY - walls->mapY) * walls->deltaDistY;
	}
	else
	{
		walls->stepY = 1;
		walls->sideDistY = (walls->mapY + 1.0 - pl->posY) * walls->deltaDistY;
	}
}

void	ray_cast(t_walls *walls, t_all *all)
{
	while (walls->hit == 0)
	{
		if (walls->sideDistX < walls->sideDistY)
		{
			walls->sideDistX += walls->deltaDistX;
			walls->mapX += walls->stepX;
			walls->side = 0;
		}
		else
		{
			walls->sideDistY += walls->deltaDistY;
			walls->mapY += walls->stepY;
			walls->side = 1;
		}
		if (all->map[walls->mapY][walls->mapX] == '1')
			walls->hit = 1;
	}
}

void	wall_distance(t_walls *walls, t_all *all, t_plr *pl)
{
	if (walls->side == 0)
		walls->perpWallDist = (walls->mapX - pl->posX
				+ (1 - walls->stepX) / 2) / walls->rayDirX;
	else
		walls->perpWallDist = (walls->mapY - pl->posY
				+ (1 - walls->stepY) / 2) / walls->rayDirY;
	walls->lineHeight = (int)((all->fin_config->res_y - 2)
			/ walls->perpWallDist);
	walls->drawStart = -walls->lineHeight / 2
		+ (all->fin_config->res_y - 2) / 2;
	if (walls->drawStart < 0)
		walls->drawStart = 0;
	walls->drawEnd = walls->lineHeight / 2 + (all->fin_config->res_y - 2) / 2;
	if (walls->drawEnd >= (all->fin_config->res_y - 2))
		walls->drawEnd = (all->fin_config->res_y - 2) - 1;
	walls->y = walls->drawStart;
	if (walls->side == 0)
		walls->wallX = pl->posY + walls->perpWallDist * walls->rayDirY;
	else
		walls->wallX = pl->posX + walls->perpWallDist * walls->rayDirX;
	walls->texX = (all->tex[0]->img_width
			* (walls->wallX - (int)walls->wallX));
	if (walls->side == 0 && walls->rayDirX > 0)
		walls->texX = all->tex[3]->img_width - walls->texX - 1;
}
