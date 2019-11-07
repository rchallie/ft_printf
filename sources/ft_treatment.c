/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:33:17 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/07 18:47:03 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_in_type_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		ft_is_in_flags_list(int c)
{
	return ((c == '-') || (c == '0') || (c == '.') || (c == '*'));
}

int		ft_treatment(int c, t_flags flags, va_list args)
{
	// c
	char ch;

	// s
	char *str;

	// d - i
	char *d_i;

	// u
	unsigned int ui;
	char *unsi_int;

	// p
	char *pointer;

	// x
	char *x;

	// X
	char *X;

	if (c == 'c')
	{	
		ch = va_arg(args, int);
		if (flags.minus == 1)
			ft_putchar(ch);
		ft_treat_width(flags.width, 1, 0);
		if (flags.minus == 0)
			ft_putchar(ch);
	}
	else if (c == 's')
	{
		str = va_arg(args, char *);
		if (flags.minus == 1)
			ft_putstr(str);
		ft_treat_width(flags.width, ft_strlen(str), 0);
		if (flags.minus == 0)
			ft_putstr(str);
	}
	else if (c == 'p')
	{
		pointer = ft_ull_base(va_arg(args, unsigned long long), 16);
		pointer = ft_str_tolower(pointer);
		if (flags.minus == 1)
		{
			ft_putstr("0x");
			ft_putstr(pointer);
		}
		ft_treat_width(flags.width, ft_strlen(pointer) + 2, 0);
		if (flags.minus == 0)
		{
			ft_putstr("0x");
			ft_putstr(pointer);
		}
		free(pointer);
	}
	else if (c == 'd' || c == 'i')
	{
		d_i = ft_itoa(va_arg(args, int));
		if (flags.minus == 1)
			ft_putstr(d_i);
		ft_treat_width(flags.width, ft_strlen(d_i), flags.zero);
		if (flags.minus == 0)
			ft_putstr(d_i);
		free(d_i);
	}
	else if (c == 'u')
	{
		ui = (unsigned int)(4294967295 + 1
				+ (unsigned int)va_arg(args, unsigned int));
		unsi_int = ft_u_itoa(ui);
		if (flags.minus == 1)
			ft_putstr(unsi_int);
		ft_treat_width(flags.width, ft_strlen(unsi_int), flags.zero);
		if (flags.minus == 0)
			ft_putstr(unsi_int);
		free(unsi_int);
	}
	else if (c == 'x')
	{
		x = ft_ull_base(va_arg(args, unsigned long long), 16);
		x = ft_str_tolower(x);
		if (flags.minus == 1)
			ft_putstr(x);
		ft_treat_width(flags.width, ft_strlen(x), flags.zero);
		if (flags.minus == 0)
			ft_putstr(x);
		free(x);
	}
	else if (c == 'X')
	{
		X = ft_ull_base(va_arg(args, unsigned long long), 16);
		if (flags.minus == 1)
			ft_putstr(X);
		ft_treat_width(flags.width, ft_strlen(X), flags.zero);
		if (flags.minus == 0)
			ft_putstr(X);
		free(X);
	}
	else if (c == '%')
	{
		if (flags.minus == 1)
			ft_putchar('%');
		ft_treat_width(flags.width, 1, flags.zero);
		if (flags.minus == 0)
			ft_putchar('%');
	}
	else
		ft_putstr("| No type find |"); //Sensé faire une erreur
	return (0);
}
