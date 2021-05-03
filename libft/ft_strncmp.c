/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:23:05 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/18 20:14:00 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	len;
	size_t	len2;
	int		res;

	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len <= len2)
		len = len + 1;
	else
		len = len2 + 1;
	if (len > n)
		len = n;
	res = ft_memcmp(s1, s2, len);
	return (res);
}
