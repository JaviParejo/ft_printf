/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:51:55 by jparejo-          #+#    #+#             */
/*   Updated: 2021/11/24 19:46:46 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

// void	ft_putnbr_fd(int n, int fd)
// {
// 	if (n == -2147483648)
// 	{
// 		ft_putchar_fd('-', fd);
// 		ft_putchar_fd('2', fd);
// 		ft_putnbr_fd(147483648, fd);
// 	}
// 	else if (n >= 10)
// 	{
// 		ft_putnbr_fd(n / 10, fd);
// 		ft_putnbr_fd(n % 10, fd);
// 	}
// 	else if (n < 0)
// 	{
// 		n *= -1;
// 		ft_putchar_fd('-', fd);
// 		ft_putnbr_fd(n, fd);
// 	}
// 	else
// 		ft_putchar_fd(n + '0', fd);
// }

int	check_args(const char *a, int next, va_list arg)
{
	int		d;
	long int				dig;
	unsigned int			uns;
	unsigned long int		num;
	unsigned int			num_x;
	int		c;
	int 	re;
	int 	n;
	char 	ch;
	char	*dir_p;
	char	*dir_x;

	next++;
	d = 0;
	c = 0;
	n = 0;
	re = 0;
	if (a[next] == 'c')
	{
		d++;
		ft_putchar_fd(va_arg(arg, int), 1);
	}
	if (a[next] == 's')
	{
		print_s(va_arg(arg, char*), &d);
	}
	if (a[next] == 'p')
	{
		num = (unsigned long int)va_arg(arg, void*);

		n = 0;
		c = 0;
		while (n >= 16)
		{
			num = num / 16;
			n++;
		}
		dir_p = malloc(sizeof(char) * (n + 1));
		while (num >= 16)
		{
			re = num % 16;
			num = num / 16;
			if (re < 10)
				ch = re + 48;
			else
				ch = re + 55;
			dir_p[c] = ch;
			d++;
			c++;
		}
		if (num < 10)
			ch = num + 48;
		else
			ch = num + 55;
		dir_p[c] = ch;
		d = d + 3;
		write(1, "0x", 2);
		while (c >= 0)
		{
			if (dir_p[c] >= 'A' && dir_p[c] <= 'F')
				dir_p[c] += 32;
			write(1, dir_p+c, 1);
			c--;
		}
		free(dir_p);
	}
	if (a[next] == 'd' || a[next] == 'i')
	{
		dig = va_arg(arg, int);
		ft_putnbr_fd(dig, 1);
		if (dig <= 0)
		{
			dig = -dig;
			d++;
		}
		while (dig > 0)
		{	
			dig = dig / 10;
			d++;
		}
	}
	if (a[next] == 'u')
	{
		uns = va_arg(arg, unsigned int);
		if (uns >= 10)
		{
			ft_putnbr_fd(uns / 10, 1);
			ft_putnbr_fd(uns % 10, 1);
		}
		else if (uns == 0)
		{
			ft_putchar_fd(uns + '0', 1);
			d++;
		}
		else
			ft_putchar_fd(uns + '0', 1);
		while (uns > 0)
		{	
			uns = uns / 10;
			d++;
		}
	}
	if (a[next] == 'x' || a[next] == 'X')
	{
		num_x = va_arg(arg, unsigned int);
		n = 0;
		c = 0;
		while (n >= 16)
		{	
			num_x = num_x / 16;
			n++;
		}
		dir_x = malloc(sizeof(char) * (n + 1));
		while (num_x >= 16)
		{
			re = num_x % 16;
			num_x = num_x / 16;
			if (re < 10)
				ch = re + 48;
			else
				ch = re + 55;
			dir_x[c] = ch;
			d++;
			c++;
		}
		if (num_x < 10)
			ch = num_x + 48;
		else
			ch = num_x + 55;
		dir_x[c] = ch;
		d++;
		while (c >= 0)
		{
			if (a[next] == 'x')
			{
				if (dir_x[c] >= 'A' && dir_x[c] <= 'F')
					dir_x[c] += 32;
			}
			write(1, dir_x+c, 1);
			c--;
		}
		free(dir_x);
	}
	if (a[next] == '%')
	{
		d++;
		ft_putchar_fd('%', 1);
	}
	return (d);
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
		else {
			write(1, l+count, 1);
			res++;
		}
		count++;
	}
	va_end(arg);
	return (res);
}

int	main(void)
{
	int		a;
	int		b;
	// void	*s;

	// s = "e";
	a = ft_printf ("%s", "Hola");
	printf (", %d\n", a);
	b = printf ("%s", "Hola");
	printf (", %d\n", b);
}
