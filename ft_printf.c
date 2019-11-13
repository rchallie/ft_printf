/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:09:36 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/12 16:22:25 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *input, ...)
{
	int			i;
	const char	*save;
	va_list		args;
	t_flags		flags;
	int			char_count;

	i = 0;
	save = ft_strdup(input);
	char_count = 0;
	va_start(args, input);
	while (1)
	{
		flags.already_print = 0;
		flags.dot = -1;
		flags.minus = 0;
		flags.star = 0;
		flags.type = 0;
		flags.width = 0;
		flags.zero = 0;
		if (!save[i])
			break ;
		else if (save[i] == '%' && save[i + 1])
		{
			i++;
			while (save[i])
			{
				if (save[i] == '0' && flags.width == 0 && flags.minus == 0)
				{
					flags.zero = 1;
				}
				if (save[i] == '.')
				{
					i++;
					if (save[i] == '*')
					{
						flags.dot = va_arg(args, int);
						i++;
					}
					else
					{
						flags.dot = 0;
						while (ft_isdigit(save[i]))
							flags.dot = (flags.dot * 10) + (save[i++] - '0');
					}
				}
				if (save[i] == '-')
				{
					flags.minus = 1;
					flags.zero = 0;
				}
				if (save[i] == '*')
				{
					flags.star = 1;
					flags.width = va_arg(args, int);
				}
				if (ft_isdigit(save[i]) && flags.star == 0)
				{
					flags.width = (flags.width * 10) + (save[i] - '0');
				}
				if (ft_is_in_type_list(save[i]))
				{
					flags.type = save[i];
					break ;
				}
				i++;
				/* Sorti */
				if (save[i] == ' ' || !save[i])
					break ;
				else if (!ft_isdigit(save[i]) && !ft_is_in_type_list(save[i]) && !ft_is_in_flags_list(save[i]))
					break ;
			}
			if (ft_is_in_type_list(save[i]))
				char_count += ft_treatment((char)flags.type, flags, args);
		}
		else
		{
			char_count++;
			ft_putchar(save[i]);
		}
		i++;
	}
	va_end(args);
	free((char *)save);
	return (char_count);
}
