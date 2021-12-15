/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:52:23 by jparejo-          #+#    #+#             */
/*   Updated: 2021/12/15 15:36:25 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(unsigned int u, int *n)
{
	if (u >= 10)
	{
		ft_putnbr_fd(u / 10, 1);
		ft_putnbr_fd(u % 10, 1);
	}
	else if (u == 0)
	{
		ft_putchar_fd(u + '0', 1);
		*n = *n + 1;
	}
	else
		ft_putchar_fd(u + '0', 1);
	while (u > 0)
	{	
		u = u / 10;
		*n = *n + 1;
	}
}
