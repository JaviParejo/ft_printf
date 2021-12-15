/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:51:55 by jparejo-          #+#    #+#             */
/*   Updated: 2021/12/15 16:21:30 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	check_args(const char *a, int next, va_list arg)
{
	int	n;

	next++;
	n = 0;
	if (a[next] == 'c')
	{
		n++;
		ft_putchar_fd(va_arg(arg, int), 1);
	}
	if (a[next] == 's')
		print_s(va_arg(arg, char *), &n);
	if (a[next] == 'p')
		print_x((unsigned long int)va_arg(arg, void *), a[next], &n);
	if (a[next] == 'd' || a[next] == 'i')
		print_d(va_arg(arg, int), &n);
	if (a[next] == 'u')
		print_u(va_arg(arg, unsigned int), &n);
	if (a[next] == 'x' || a[next] == 'X')
		print_x(va_arg(arg, unsigned int), a[next], &n);
	if (a[next] == '%')
	{
		n++;
		ft_putchar_fd('%', 1);
	}
	return (n);
}

void	leaks(void)
{
	system("leaks a.out");
}

int	ft_printf(const char *l, ...)
{	
	int		count;
	int		res;
	va_list	arg;

	va_start(arg, l);
	count = 0;
	res = 0;
	while (l[count] != '\0')
	{
		if (l[count] == '%')
		{
			res += check_args(l, count, arg);
			count++;
		}
		else
		{
			write(1, l + count, 1);
			res++;
		}
		count++;
	}
	va_end(arg);
	return (res);
}

int	main(void)
{
	atexit(leaks);
	ft_printf("");
	return(0);
}
