/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:09:34 by jparejo-          #+#    #+#             */
/*   Updated: 2021/11/24 20:13:42 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*digtohex(char *dir, unsigned int num, int *n)
{
	char	ch;
	int 	count;
	int 	res;

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
	return(dir);
}

void	print_x(unsigned int num, int next, int *n)
{
	int		count;
	char	*dir;

	count = 0;
	while (num >= 16)
	{	
		num = num / 16;
		count++;
	}
	dir = malloc(sizeof(char) * (count + 1));
	dir = digtohex(dir, num, n);
	// while (dir[count] != '\0')
	// 	count++;
	// while (count >= 0)
	// {
	// 	if (a[next] == 'x')
	// 	{
	// 		if (dir[count] >= 'A' && dir[count] <= 'F')
	// 			dir[count] += 32;
	// 	}
	// 	write(1, dir+count, 1);
	// 	count--;
	// }
	free(dir);
}
