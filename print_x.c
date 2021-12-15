/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:09:34 by jparejo-          #+#    #+#             */
/*   Updated: 2021/12/15 15:36:22 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*digtohex(char *dir, unsigned long int num, int *n)
{
	char	ch;
	int		count;
	int		res;

	count = 0;
	res = 0;
	while (num >= 16)
	{
		res = num % 16;
		num = num / 16;
		if (res < 10)
			ch = res + 48;
		else
			ch = res + 55;
		dir[count] = ch;
		*n = *n + 1;
		count++;
	}
	if (num < 10)
		ch = num + 48;
	else
		ch = num + 55;
	dir[count] = ch;
	*n = *n + 1;
	return (dir);
}

void	tolow(char *dir, char l, int count)
{
	if (l == 'x' || l == 'p')
	{
		if (dir[count] >= 'A' && dir[count] <= 'F')
			dir[count] += 32;
	}
	write(1, dir + count, 1);
}

void	print_x(unsigned long int num, char l, int *n)
{
	int					count;
	unsigned long int	d;
	char				*dir;

	count = 0;
	d = num;
	while (d >= 16)
	{	
		d = d / 16;
		count++;
	}
	dir = malloc(sizeof(char) * (count + 1));
	dir = digtohex(dir, num, n);
	if (l == 'p')
	{
		*n = *n + 2;
		write(1, "0x", 2);
	}
	while (count >= 0)
	{
		tolow(dir, l, count);
		count--;
	}
	free(dir);
}
