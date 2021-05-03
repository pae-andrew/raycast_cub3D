/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:08:43 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/28 00:52:56 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	change_char(char **map, int y, int x, int i)
{
	if (map[y][x] != '1' && map[y][x] != '2')
		map[y][x] = '2';
	if (map[y][x + 1] != '1' && map[y][x + 1] != '2')
		check_map(map, y, x + 1, i);
	if (map[y][x - 1] != '1' && map[y][x - 1] != '2')
		check_map(map, y, x - 1, i);
	if (map[y + 1][x] != '1' && map[y + 1][x] != '2')
		check_map(map, y + 1, x, i);
	if (map[y - 1][x] != '1' && map[y - 1][x] != '2')
		check_map(map, y - 1, x, i);
}

int	check_map(char **map, int y, int x, int i)
{
	char	**valid_map;

	valid_map = map;
	if (!valid_map[y] || y >= i - 1)
		exit_with_error(-3, "Map error");
	if (y < 0)
		exit_with_error(-3, "Map error");
	if (x < 0 || valid_map[y][x] == '\0')
		exit_with_error(-3, "Map error");
	if (ft_strchr("NEWS", valid_map[y][x]))
		valid_map[y][x] = '2';
	if ((valid_map[y][x] != '1') && (valid_map[y][x] != '0')
		&& (valid_map[y][x] != '2') && (valid_map[y][x] != ' '))
		exit_with_error(-3, "Wrong symbol in map");
	change_char(valid_map, y, x, i);
	return (0);
}

char	**parse_map(t_list **head, int size, t_config *config)
{
	int		i;
	t_list	*tmp;
	char	**map;

	i = -1;
	tmp = *head;
	map = NULL;
	map = malloc(sizeof(char *) * size);
	if (!map)
		exit_with_error(0, "Wrong map mem");
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = make_config(map, config);
	if (i == 0)
		exit_with_error(-3, "Wrong config");
	ft_lstclear(&tmp, &free);
	return (&map[i]);
}

char	**get_map(char *argv, t_config *config)
{
	int		fd;
	char	*line;
	t_list	*head;

	line = NULL;
	head = NULL;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit_with_error(0, "Invalid map.");
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(&head, ft_lstnew(line));
	close(fd);
	ft_lstadd_back(&head, ft_lstnew(line));
	return (parse_map(&head, ft_lstsize(head), config));
}
