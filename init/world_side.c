/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_side.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:52:01 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/18 14:53:19 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_S(t_plr *plr, t_point *pos)
{
	pos->oldDirX = plr->dirX;
	plr->dirX = plr->dirX * cos(1.57) - plr->dirY * sin(1.57);
	plr->dirY = pos->oldDirX * sin(1.57) + plr->dirY * cos(1.57);
	pos->oldPlaneX = plr->planeX;
	plr->planeX = plr->planeX * cos(-1.57)
		- plr->planeY * sin(1.57);
	plr->planeY = pos->oldPlaneX * sin(1.57)
		+ plr->planeY * cos(1.57);
}

void	map_E(t_plr *plr)
{
	plr->dirX = 1;
	plr->dirY = 0;
	plr->planeX = 0;
	plr->planeY = 0.6;
}

void	map_W(t_plr *plr, t_point *pos)
{
	pos->oldDirX = plr->dirX;
	plr->dirX = plr->dirX * cos(3.14) - plr->dirY * sin(3.14);
	plr->dirY = pos->oldDirX * sin(3.14) + plr->dirY * cos(3.14);
	pos->oldPlaneX = plr->planeX;
	plr->planeX = plr->planeX * cos(-3.14)
		- plr->planeY * sin(3.14);
	plr->planeY = pos->oldPlaneX * sin(3.14)
		+ plr->planeY * cos(3.14);
}

void	map_N(t_plr *plr, t_point *pos)
{
	pos->oldDirX = plr->dirX;
	plr->dirX = plr->dirX * cos(-1.57) - plr->dirY * sin(-1.57);
	plr->dirY = pos->oldDirX * sin(-1.57) + plr->dirY * cos(-1.57);
	pos->oldPlaneX = plr->planeX;
	plr->planeX = plr->planeX * cos(-1.57)
		- plr->planeY * sin(-1.57);
	plr->planeY = pos->oldPlaneX * sin(-1.57)
		+ plr->planeY * cos(-1.57);
}
