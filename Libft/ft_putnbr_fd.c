/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:31:58 by alanders          #+#    #+#             */
/*   Updated: 2019/07/02 12:32:01 by alanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int i;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	i = (unsigned int)n;
	if (i < 10)
		ft_putchar_fd(i + 48, fd);
	else
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putchar_fd(i % 10 + 48, fd);
	}
}
