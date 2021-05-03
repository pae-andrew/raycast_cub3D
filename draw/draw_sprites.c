/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:45:36 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/18 16:59:55 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_dist(t_sprites *sprites, t_plr *pl)
{
	sprites->spriteDistance = malloc(sizeof(float *) * pl->count_sprites);
	sprites->spriteOrder = malloc(sizeof(int *) * pl->count_sprites);
	sprites->i = -1;
	while (++sprites->i < pl->count_sprites)
	{
		sprites->spriteOrder[sprites->i] = sprites->i;
		sprites->spriteDistance[sprites->i] = ((pl->posX
					- pl->sprite_x[sprites->i])
				* (pl->posX - pl->sprite_x[sprites->i])
				+ (pl->posY - pl->sprite_y[sprites->i])
				* (pl->posY - pl->sprite_y[sprites->i]));
	}
	sprites->spriteOrder = sortSprites(sprites->spriteOrder,
			sprites->spriteDistance, pl->count_sprites);
}

void	sprite_size(t_sprites *sprites, t_all *all, t_plr *pl)
{
	sprites->spriteX = pl->sprite_x[sprites->spriteOrder[sprites->i]]
		- pl->posX;
	sprites->spriteY = pl->sprite_y[sprites->spriteOrder[sprites->i]]
		- pl->posY;
	sprites->invDet = 1.0 / (pl->planeX * pl->dirY - pl->dirX * pl->planeY);
	sprites->transformX = sprites->invDet * (pl->dirY * sprites->spriteX
			- pl->dirX * sprites->spriteY);
	sprites->transformY = sprites->invDet * (-pl->planeY * sprites->spriteX
			+ pl->planeX * sprites->spriteY);
	sprites->spriteScreenX = (int)((all->fin_config->res_x / 2)
			* (1 + sprites->transformX / sprites->transformY));
	sprites->spriteHeight = abs((int)((all->fin_config->res_y - 2)
				/ (sprites->transformY)));
	sprites->drawStartY = -sprites->spriteHeight / 2
		+ (all->fin_config->res_y - 2) / 2;
	if (sprites->drawStartY < 0)
		sprites->drawStartY = 0;
	sprites->drawEndY = sprites->spriteHeight / 2
		+ (all->fin_config->res_y - 2) / 2;
	if (sprites->drawEndY >= (all->fin_config->res_y - 2))
		sprites->drawEndY = (all->fin_config->res_y - 2) - 1;
}

void	draw_sprite_tex(t_sprites *sprites, t_all *all, t_plr *pl)
{
	sprites->texX = (int)(256 * (sprites->stripe
				- (-sprites->spriteWidth / 2 + sprites->spriteScreenX))
			* all->tex[4]->img_width / sprites->spriteWidth) / 256;
	if (sprites->transformY > 0 && sprites->stripe > 0
		&& sprites->stripe < all->fin_config->res_x
		&& sprites->transformY < pl->ZBuffer[sprites->stripe])
	{
		sprites->y = sprites->drawStartY;
		while (sprites->y < sprites->drawEndY)
		{
			sprites->d = (sprites->y) * 256 - (all->fin_config->res_y - 2)
				* 128 + sprites->spriteHeight * 128;
			sprites->texY = ((sprites->d * all->tex[4]->img_height)
					/ sprites->spriteHeight) / 256;
			if (get_color(all->tex[4], sprites->texX, sprites->texY) != 0)
				my_mlx_pixel_put(all->win, sprites->stripe, sprites->y,
					get_color(all->tex[4], sprites->texX, sprites->texY));
			sprites->y++;
		}
	}
	sprites->stripe++;
}

int	draw_sprites(t_all *all, t_plr *pl)
{
	t_sprites	sprites;

	sprite_dist(&sprites, pl);
	sprites.i = -1;
	while (++sprites.i < pl->count_sprites)
	{
		sprite_size(&sprites, all, pl);
		sprites.spriteWidth = abs((int)((all->fin_config->res_y - 2)
					/ (sprites.transformY)));
		sprites.drawStartX = -sprites.spriteWidth / 2 + sprites.spriteScreenX;
		if (sprites.drawStartX < 0)
			sprites.drawStartX = 0;
		sprites.drawEndX = sprites.spriteWidth / 2 + sprites.spriteScreenX;
		if (sprites.drawEndX >= all->fin_config->res_x)
			sprites.drawEndX = all->fin_config->res_x - 1;
		sprites.stripe = sprites.drawStartX;
		while (sprites.stripe < sprites.drawEndX)
			draw_sprite_tex(&sprites, all, pl);
	}
	free(sprites.spriteOrder);
	free(sprites.spriteDistance);
	return (0);
}
