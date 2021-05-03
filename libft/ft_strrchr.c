/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:01:18 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/11 12:09:27 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	a = (char *)s + ft_strlen(s);
	while (*a != c)
	{
		if (a == s)
			return (NULL);
		a--;
	}
	return (a);
}
