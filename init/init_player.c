/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:06:21 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/27 23:11:24 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	while_map(char **map, t_plr *plr, t_point *pos)
{
	if (ft_strchr("2", map[pos->y][pos->x]))
	{
		plr->count_sprites++;
		plr->sprite_x[plr->count_sprites - 1] = pos->x + 0.5;
		plr->sprite_y[plr->count_sprites - 1] = pos->y + 0.5;
	}
	if (ft_strchr("NEWS", map[pos->y][pos->x]))
	{
		plr->count++;
		plr->posX = pos->x;
		plr->posY = pos->y;
		plr->dirX = 1;
		plr->dirY = 0;
		plr->planeX = 0;
		plr->planeY = 0.6;
		if (map[pos->y][pos->x] == 'S')
			map_S(plr, pos);
		if (map[pos->y][pos->x] == 'E')
			map_E(plr);
		if (map[pos->y][pos->x] == 'W')
			map_W(plr, pos);
		if (map[pos->y][pos->x] == 'N')
			map_N(plr, pos);
	}
}

void	ft_init_player(char **map, t_plr *plr)
{
	t_point	pos;

	plr->count = 0;
	plr->count_sprites = 0;
	ft_bzero(&pos, sizeof(t_point));
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			while_map(map, plr, &pos);
			pos.x++;
		}
		pos.y++;
	}
	if (plr->count != 1)
		exit_with_error(1, "Not valid count of players");
}
