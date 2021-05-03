/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:17:29 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/17 21:30:32 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_all *all)
{
	if (all->map[(int)(all->plr->posY)][(int)
			(all->plr->posX + all->plr->dirX
			/ all->move->move_speed)] != '1')
		all->plr->posX += all->plr->dirX / all->move->move_speed;
	if (all->map[(int)(all->plr->posY + all->plr->dirY
			/ all->move->move_speed)][(int)(all->plr->posX)] != '1')
		all->plr->posY += all->plr->dirY / all->move->move_speed;
}

void	move_back(t_all *all)
{
	if (all->map[(int)(all->plr->posY)][(int)
			(all->plr->posX - all->plr->dirX
			/ all->move->move_speed)] != '1')
		all->plr->posX -= all->plr->dirX / all->move->move_speed;
	if (all->map[(int)(all->plr->posY - all->plr->dirY
			/ all->move->move_speed)][(int)(all->plr->posX)] != '1')
		all->plr->posY -= all->plr->dirY / all->move->move_speed;
}

void	move_right(t_all *all)
{
	if (all->map[(int)(all->plr->posY)][(int)
			(all->plr->posX + all->plr->planeX
			/ all->move->move_speed)] != '1')
		all->plr->posX += all->plr->planeX / all->move->move_speed;
	if (all->map[(int)(all->plr->posY + all->plr->planeY
			/ all->move->move_speed)][(int)(all->plr->posX)] != '1')
		all->plr->posY += all->plr->planeY / all->move->move_speed;
}

void	move_left(t_all *all)
{
	if (all->map[(int)(all->plr->posY)][(int)
			(all->plr->posX - all->plr->planeX
			/ all->move->move_speed)] != '1')
		all->plr->posX -= all->plr->planeX / all->move->move_speed;
	if (all->map[(int)(all->plr->posY - all->plr->planeY
			/ all->move->move_speed)][(int)(all->plr->posX)] != '1')
		all->plr->posY -= all->plr->planeY / all->move->move_speed;
}
