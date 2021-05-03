/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:19:03 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/18 13:19:40 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(t_tex *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	*sortSprites(int order[], float dist[], int amount)
{
	int		i;
	int		done;
	int		a;

	done = 1;
	while (done)
	{
		done = 0;
		i = 1;
		while (i < amount)
		{
			if (dist[order[i]] > dist[order[i - 1]])
			{
				a = order[i];
				order[i] = order[i - 1];
				order[i - 1] = a;
				done = 1;
			}
			i++;
		}
	}
	return (order);
}
