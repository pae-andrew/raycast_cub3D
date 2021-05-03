/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:30:35 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/17 21:42:31 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		size_s;
	char		*newstring;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_s = ft_strlen(s1);
	while (size_s && ft_strchr(set, s1[size_s]))
		size_s--;
	newstring = ft_substr((char *)s1, 0, size_s + 1);
	return (newstring);
}
