/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:22:31 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/24 12:47:05 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_color_save(t_win *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	set_header(char *header, t_all *all)
{
	unsigned int	k;

	k = 40;
	ft_memcpy((header + 14), &k, 4);
	k = all->fin_config->res_x;
	ft_memcpy((header + 18), &k, 4);
	k = all->fin_config->res_y;
	ft_memcpy((header + 22), &k, 4);
	k = 1;
	ft_memcpy((header + 26), &k, 2);
	k = 32;
	ft_memcpy((header + 28), &k, 2);
	k = 5000;
	ft_memcpy((header + 38), &k, 4);
	ft_memcpy((header + 42), &k, 4);
}

void	set_file_header(char *header, t_all *all)
{
	unsigned int	size;
	int				i;

	i = 53;
	size = 54 + all->win->line_l * all->fin_config->res_y;
	while (i >= 0)
	{
		header[i] = 0;
		i--;
	}
	header[0] = 'B';
	header[1] = 'M';
	ft_memcpy((header + 2), &size, sizeof(unsigned int));
	size = 54;
	ft_memcpy((header + 10), &size, sizeof(int));
}

void	write_data(int fd, t_all *all)
{
	int				i;
	int				j;
	unsigned int	color;

	i = all->fin_config->res_y - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < all->fin_config->res_x)
		{
			color = get_color_save(all->win, j, i);
			if (write(fd, &color, 4) < 0)
				exit_with_error(-5, "Error\nSaving file\n");
			j++;
		}
		i--;
	}
	return ;
}

void	save_image(t_all *all)
{
	int		fd;
	char	header[54];

	fd = open("example.bmp", O_RDWR);
	if (fd < 0)
		exit_with_error(0, "Error\nUnable to open file\n");
	set_file_header(header, all);
	set_header(header, all);
	write(fd, &header, 54);
	write_data(fd, all);
	close(fd);
	exit(0);
}
