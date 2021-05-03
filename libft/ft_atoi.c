/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:32:37 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/18 17:20:30 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_res(long a)
{
	if (a == 9223372036854775807L)
		return (-1);
	else if (a > 2147483647)
		return (0);
	else if (a == -9223372036854775807L - 1L)
		return (0);
	else if (a < -2147483648)
		return (-1);
	else
		return (a);
}

int	ft_atoi(char *str)
{
	long	res;
	int		sign;
	long	i;

	sign = 1;
	i = 0;
	res = 0;
	if (!str)
		return (0);
	while ((str[i] >= 57 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
		i++;
	while ((str[i] > 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = (-1);
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return ((int)(check_res(res * sign)));
}
