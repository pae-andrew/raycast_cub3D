/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:48:24 by gcredibl          #+#    #+#             */
/*   Updated: 2020/11/06 18:02:16 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list		*new;

	new = malloc(sizeof(t_list) * 1);
	if (!new)
		return (NULL);
	if (content == NULL)
		new->content = NULL;
	else
	{
		new->content = malloc(sizeof(t_list) * 1);
		if (new->content == NULL)
			return (NULL);
		new->content = content;
	}
	new->next = NULL;
	return (new);
}
