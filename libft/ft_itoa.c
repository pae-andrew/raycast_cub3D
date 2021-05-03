/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:23:39 by pae-andrew        #+#    #+#             */
/*   Updated: 2021/04/11 12:02:52 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getlen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	copy;
	int				len;
	char			*res;

	if (n > 0)
		copy = n;
	else
		copy = -n;
	len = getlen(n);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	*(res + len--) = '\0';
	while (copy > 0)
	{
		*(res + len--) = copy % 10 + '0';
		copy /= 10;
	}
	if (n < 0)
	{
		*res = '-';
	}
	if (n == 0)
		*res = '0';
	return (res);
}
