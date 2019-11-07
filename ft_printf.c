/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:09:36 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/07 16:45:30 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *input, ...)
{
	int			i;
	const char	*save;
	va_list		args;
	t_flags		flags;

	i = 0;
	save = ft_strdup(input);

	va_start(args, input);
	while (1)
	{
		flags.already_print = 0;
		flags.dot = 0;
		flags.minus = 0;
		flags.star = 0;
		flags.type = 0;
		flags.width = 0;
		flags.zero = 0;
		if (!save[i])
			break ;
		else if (save[i] == '%')
		{
			i++;
			if (save[i] == '0')
			{
				flags.zero = 1;
				i++;
			}
			while (save[i])
			{
				if (save[i] == '-')
				{
					flags.minus = 1;
					flags.zero = 0;
					i++;
				}
				if (ft_isdigit(save[i]))
					flags.width = (flags.width * 10) + (save[i] - '0');
				if (ft_is_in_type_list(save[i]))
				{
					flags.type = save[i];
					break ;
				}
				i++;
				/* Sorti */
				if (save[i] == ' ')
					break ;
				else if (!ft_isdigit(save[i]) && !ft_is_in_type_list(save[i]))
					break ;
			}
			if (ft_is_in_type_list(save[i]))
				ft_treatment((char)flags.type, flags, args);
			
			i++;
		}
		ft_putchar(save[i]);
		i++;
	}
	va_end(args);
	free((char *)save);
	return (0);
}
