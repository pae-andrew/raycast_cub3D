/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:00:50 by gcredibl          #+#    #+#             */
/*   Updated: 2020/10/30 13:42:41 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cur;

	cur = (unsigned char *)s;
	while (n--)
	{
		if (*cur == (unsigned char)c)
			return (cur);
		if (n)
			cur++;
	}
	return (NULL);
}
