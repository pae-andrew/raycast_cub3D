/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:19:51 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/27 23:07:15 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	make_east_west(char **map, t_config *config, int i, int count)
{
	if (ft_strnstr(map[i], "WE", ft_strlen(map[i])))
	{
		if (config->west)
			exit_with_error(-3, "Double west in config :(");
		config->west = ft_strdup(ft_strnstr(map[i], "WE", ft_strlen(map[i])));
		count++;
	}
	else if (ft_strnstr(map[i], "EA", ft_strlen(map[i])))
	{
		if (config->east)
			exit_with_error(-3, "Double east in config :(");
		config->east = ft_strdup(ft_strnstr(map[i], "EA", ft_strlen(map[i])));
		count++;
	}
	return (count);
}

int	make_texs(char **map, t_config *config, int i, int count)
{
	if (ft_strnstr(map[i], "NO", ft_strlen(map[i])))
	{
		if (config->north)
			exit_with_error(-3, "Double north in config :(");
		config->north = ft_strdup(ft_strnstr(map[i], "NO", ft_strlen(map[i])));
		count++;
	}
	else if (ft_strnstr(map[i], "SO", ft_strlen(map[i])))
	{
		if (config->south)
			exit_with_error(-3, "Double south in config :(");
		config->south = ft_strdup(ft_strnstr(map[i], "SO", ft_strlen(map[i])));
		count++;
	}
	else if (ft_strnstr(map[i], "S", ft_strlen(map[i])))
	{
		if (config->sprite)
			exit_with_error(-3, "Double sprite in config :(");
		config->sprite = ft_strdup(ft_strnstr(map[i], "S", ft_strlen(map[i])));
		count++;
	}
	return (count);
}

int	make_floor_sky(char **map, t_config *config, int i, int count)
{
	if (ft_strnstr(map[i], "F", ft_strlen(map[i])))
	{
		if (config->floor)
			exit_with_error(-3, "Double floor in config :(");
		config->floor = ft_strdup(ft_strnstr(map[i], "F", ft_strlen(map[i])));
		count++;
	}
	else if (ft_strnstr(map[i], "C", ft_strlen(map[i])))
	{
		if (config->sky)
			exit_with_error(-3, "Double sky in config :(");
		config->sky = ft_strdup(ft_strnstr(map[i], "C", ft_strlen(map[i])));
		count++;
	}
	return (count);
}

int	map_count(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	make_config(char **map, t_config *config)
{	
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (ft_strnstr(map[i], "R", ft_strlen(map[i])))
		{
			if (config->resolution)
				exit_with_error(-3, "Double resolution in config :(");
			config->resolution = ft_strdup(map[i]);
			count++;
		}
		count = make_east_west(map, config, i, count);
		count = make_texs(map, config, i, count);
		count = make_floor_sky(map, config, i, count);
		i++;
		config->map_count = map_count(&map[i]);
		if (count == 8 && (ft_strnstr(map[i], "1", ft_strlen(map[i]))))
			return (i);
	}
	return (0);
}
