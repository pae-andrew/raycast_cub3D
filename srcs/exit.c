/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:05:03 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/27 21:13:35 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_mem(t_all *all)
{
	free(all->win);
	free(all->fin_config);
	free(all->plr);
	free(all->move);
}

int	exit_with_error(int i, char *str)
{
	ft_putendl_fd("Error:", 1);
	ft_putendl_fd(str, 1);
	exit (i);
}

int	exit_game(t_all *all)
{
	free_mem(all);
	ft_putendl_fd("See you later...", 1);
	exit (0);
}
