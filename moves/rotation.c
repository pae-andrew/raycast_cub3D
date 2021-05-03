/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:25:59 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/17 21:30:29 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rot_left(t_all *all)
{
	float	rotSpeed;
	float	oldDirX;
	float	oldPlaneX;

	rotSpeed = 0.05;
	oldDirX = all->plr->dirX;
	all->plr->dirX = all->plr->dirX * cos(-rotSpeed)
		- all->plr->dirY * sin(-rotSpeed);
	all->plr->dirY = oldDirX * sin(-rotSpeed)
		+ all->plr->dirY * cos(-rotSpeed);
	oldPlaneX = all->plr->planeX;
	all->plr->planeX = all->plr->planeX * cos(-rotSpeed)
		- all->plr->planeY * sin(-rotSpeed);
	all->plr->planeY = oldPlaneX * sin(-rotSpeed)
		+ all->plr->planeY * cos(-rotSpeed);
}

void	rot_right(t_all *all)
{
	float	rotSpeed;
	float	oldDirX;
	float	oldPlaneX;

	rotSpeed = 0.05;
	oldDirX = all->plr->dirX;
	all->plr->dirX = all->plr->dirX * cos(rotSpeed)
		- all->plr->dirY * sin(rotSpeed);
	all->plr->dirY = oldDirX * sin(rotSpeed)
		+ all->plr->dirY * cos(rotSpeed);
	oldPlaneX = all->plr->planeX;
	all->plr->planeX = all->plr->planeX * cos(-rotSpeed)
		- all->plr->planeY * sin(rotSpeed);
	all->plr->planeY = oldPlaneX * sin(rotSpeed)
		+ all->plr->planeY * cos(rotSpeed);
}
