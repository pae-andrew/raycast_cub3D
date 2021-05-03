/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:01:11 by gcredibl          #+#    #+#             */
/*   Updated: 2020/11/12 17:52:46 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;

	i = 0;
	if (!str1)
		return (NULL);
	if (ft_strlen(str2) == 0)
		return ((char *)&str1[i]);
	while (i < len)
	{
		if (ft_strncmp((char *)&str1[i], (char *)str2, ft_strlen(str2)) == 0)
		{
			if (i + ft_strlen(str2) > len)
				return (NULL);
			return ((char *)&str1[i]);
		}
		i++;
	}
	return (NULL);
}
