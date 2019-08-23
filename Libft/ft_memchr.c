/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:28:56 by alanders          #+#    #+#             */
/*   Updated: 2019/07/02 12:29:02 by alanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	c1 = (unsigned char)c;
	while (n)
	{
		if (str[i] == c1)
			return (str + i);
		n--;
		i++;
	}
	return (0);
}
