/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:30:21 by alanders          #+#    #+#             */
/*   Updated: 2019/07/02 12:30:29 by alanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *)b;
	i = 0;
	while (len > 0)
	{
		str[i] = c;
		len--;
		i++;
	}
	return (b);
}
