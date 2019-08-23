/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:26:10 by alanders          #+#    #+#             */
/*   Updated: 2019/07/02 12:53:02 by alanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*i;

	if (*alst)
	{
		while ((*alst) && alst)
		{
			i = (*alst)->next;
			(*del)((*alst)->content, (*alst)->content_size);
			ft_memdel((void **)alst);
			*alst = i;
		}
	}
	(*alst) = NULL;
}
