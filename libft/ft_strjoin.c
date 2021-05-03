/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:36:57 by gcredibl          #+#    #+#             */
/*   Updated: 2021/04/26 22:43:53 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return ((char *)0);
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_memset(new, '\0', len + 1);
	if (ft_strlcat(new, s1, len + 1) >= len + 1)
		return ((char *)0);
	if (ft_strlcat(new, s2, len + 1) >= len + 1)
		return ((char *)0);
	return (new);
}
