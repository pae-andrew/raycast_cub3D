/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:15:14 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/17 21:50:15 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_update(t_all *all)
{
	if (all->move->move_forward == 1)
		move_forward(all);
	if (all->move->move_back == 1)
		move_back(all);
	if (all->move->move_right == 1)
		move_right(all);
	if (all->move->move_left == 1)
		move_left(all);
	if (all->move->rot_left == 1)
		rot_left(all);
	if (all->move->rot_right == 1)
		rot_right(all);
	return (0);
}

int	key_press(int key, t_all *all)
{
	if (key == 257)
	{
		all->move->move_speed--;
		if (all->move->move_speed <= 0)
			all->move->move_speed = 4;
	}
	if (key == 13 || key == 126)
		all->move->move_forward = 1;
	if (key == 1 || key == 125)
	{
		all->move->move_back = 1;
	}
	if (key == 12 || key == 123)
		all->move->rot_left = 1;
	if (key == 14 || key == 124)
		all->move->rot_right = 1;
	if (key == 2)
		all->move->move_right = 1;
	if (key == 0)
		all->move->move_left = 1;
	if (key == 53)
		exit_game (all);
	return (0);
}

int	key_release(int key, t_all *all)
{
	if (key == 13 || key == 126)
		all->move->move_forward = 0;
	if (key == 1 || key == 125)
		all->move->move_back = 0;
	if (key == 12 || key == 123)
		all->move->rot_left = 0;
	if (key == 14 || key == 124)
		all->move->rot_right = 0;
	if (key == 2)
		all->move->move_right = 0;
	if (key == 0)
		all->move->move_left = 0;
	return (0);
}
