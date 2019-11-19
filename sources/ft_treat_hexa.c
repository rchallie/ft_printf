/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:49:50 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/13 16:06:13 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_put_part_hexa(char *hexa, t_flags flags)
{
	int		char_count;

	char_count = 0;
	if (flags.minus == 1)
	{
		if (flags.dot >= 0)
			char_count += ft_putstr(hexa, flags.dot);
		else
			char_count += ft_putstr(hexa, ft_strlen(hexa));
	}
	if (flags.dot >= 0)
	{
		char_count += ft_treat_width(flags.dot, ft_strlen(hexa), 1);
		char_count += ft_treat_width(flags.width, flags.dot, flags.zero);
	}
	else
		char_count += ft_treat_width(flags.width, ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
	{
		if (flags.dot >= 0)
			char_count += ft_putstr(hexa, flags.dot);
		else
			char_count += ft_putstr(hexa, ft_strlen(hexa));
	}
	return (char_count);
}

int				ft_treat_hexa(unsigned int ui, int lower, t_flags flags)
{
	int		char_count;
	char	*hexa;

	char_count = 0;
	if (ui == 0)
	{
		hexa = "0";
		if (flags.dot >= 0)
		{
			char_count += ft_treat_width(flags.dot + flags.width, 0, 0);
			return (char_count);
		}
		else
			char_count += ft_treat_width(flags.width,
			ft_strlen(hexa), flags.zero);
		return (ft_putstr("0", 1) + char_count);
	}
	hexa = ft_ull_base((unsigned long long)ui, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	char_count += ft_put_part_hexa(hexa, flags);
	free(hexa);
	return (char_count);
}
