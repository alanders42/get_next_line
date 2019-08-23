/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:29:35 by alanders          #+#    #+#             */
/*   Updated: 2019/07/02 12:29:42 by alanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0 || dst == src)
		return (dst);
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	while (n)
	{
		*str1 = *str2;
		str1++;
		str2++;
		n--;
	}
	return (dst);
}
