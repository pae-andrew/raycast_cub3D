/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:00:31 by gcredibl          #+#    #+#             */
/*   Updated: 2020/11/06 15:38:38 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			a;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	a = 0;
	while (a < n)
	{
		d[a] = s[a];
		if (s[a] == (unsigned char)c)
			return ((void *)(d + a + 1));
		a++;
	}
	return (NULL);
}
