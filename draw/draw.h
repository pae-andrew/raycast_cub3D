/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:17:37 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/24 16:36:02 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

typedef struct s_walls
{
	int		y;
	int		x;
	int		lineHeight;
	float	cameraX;
	float	rayDirX;
	float	rayDirY;
	int		mapX;
	int		mapY;
	float	sideDistX;
	float	sideDistY;
	float	deltaDistX;
	float	deltaDistY;
	float	perpWallDist;
	int		stepX;
	int		stepY;
	int		side;
	int		hit;
	int		drawStart;
	int		drawEnd;
	float	wallX;
	int		texX;
	float	step;
	float	texPos;
	int		texY;
}			t_walls;

typedef struct s_sprites
{
	int		y;
	int		i;
	float	*spriteDistance;
	int		*spriteOrder;
	float	spriteX;
	float	spriteY;
	float	invDet;
	float	transformX;
	float	transformY;
	int		spriteScreenX;
	int		spriteHeight;
	int		drawStartY;
	int		drawEndY;
	int		spriteWidth;
	int		drawStartX;
	int		drawEndX;
	int		stripe;
	int		texX;
	int		d;
	int		texY;
}			t_sprites;

#endif