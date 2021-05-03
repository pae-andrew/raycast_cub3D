/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:33:59 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/27 23:09:25 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFF_SIZE
#  define BUFF_SIZE 64
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup_for_next_line(char *s1, int i);
char	*ft_strjoin_for_next_line(char *s1, char *s2);
size_t	ft_strlen(const char *str);
#endif
