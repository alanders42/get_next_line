/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:47:30 by alanders          #+#    #+#             */
/*   Updated: 2019/07/02 12:47:34 by alanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *const	us1 = (const unsigned char *)s1;
	const unsigned char *const	us2 = (const unsigned char *)s2;
	size_t						i;

	i = (size_t)0;
	while (i < n)
	{
		if (us1[i] < us2[i])
			return (-1);
		else if (us1[i] > us2[i])
			return (1);
		else if (!us1[i])
			return (0);
		i++;
	}
	return (0);
}
