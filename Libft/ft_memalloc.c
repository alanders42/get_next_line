/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:27:56 by alanders          #+#    #+#             */
/*   Updated: 2019/07/02 12:28:00 by alanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*new;
	size_t	i;

	new = NULL;
	new = (char *)malloc(size);
	if (new)
	{
		i = 0;
		while (size-- > 0)
		{
			new[i] = 0;
			i++;
		}
	}
	return (new);
}
