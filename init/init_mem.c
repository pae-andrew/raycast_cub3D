/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:28:15 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/27 23:15:33 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_mem(t_all *all)
{
	all->fin_config->north = NULL;
	all->fin_config->west = NULL;
	all->fin_config->east = NULL;
	all->fin_config->south = NULL;
	all->fin_config->sprite = NULL;
	all->config->east = NULL;
	all->config->floor = NULL;
	all->config->north = NULL;
	all->config->resolution = NULL;
	all->config->sky = NULL;
	all->config->south = NULL;
	all->config->sprite = NULL;
	all->config->west = NULL;
}
