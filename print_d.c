/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:47:44 by jparejo-          #+#    #+#             */
/*   Updated: 2021/11/25 17:50:53 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d(int d, int *n)
{
	ft_putnbr_fd(d, 1);
	if (d <= 0)
	{
		d = -d;
		d++;
	}
	while (d > 0)
	{	
		d = d / 10;
		*n = *n + 1;
	}
}
