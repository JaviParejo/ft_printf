/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:01:26 by jparejo-          #+#    #+#             */
/*   Updated: 2021/12/15 16:21:24 by jparejo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

void		ft_putchar_fd(char c, int fd);

void		ft_putnbr_fd(int n, int fd);

void		print_s(char *s, int *n);

void		print_x(unsigned long int num, char l, int *n);

void		print_d(int d, int *n);

void		print_u(unsigned int u, int *n);

char		*digtohex(char *dir, unsigned long int num, int *n);

void		tolow(char *dir, char l, int count);

int			check_args(const char *a, int next, va_list arg);

int			ft_printf(const char *l, ...);

#endif
