/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:09:36 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/21 10:08:29 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_flags		ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int			ft_flag_parse(const char *save, int i, t_flags *flags, va_list args)
{
	while (save[i])
	{
		if (!ft_isdigit(save[i]) && !ft_is_in_type_list(save[i])
		&& !ft_is_in_flags_list(save[i]))
			break ;
		if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (save[i] == '.')
			i = ft_flag_dot(save, i, flags, args);
		if (save[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (save[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(save[i]))
			*flags = ft_flag_digit(save[i], *flags);
		if (ft_is_in_type_list(save[i]))
		{
			flags->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}

int			ft_treat_save(const char *save, va_list args)
{
	int			i;
	t_flags		flags;
	int			char_count;

	i = 0;
	char_count = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (!save[i])
			break ;
		else if (save[i] == '%' && save[i + 1])
		{
			i = ft_flag_parse(save, ++i, &flags, args);
			if (ft_is_in_type_list(save[i]))
				char_count += ft_treatment((char)flags.type, flags, args);
			else if (save[i])
				char_count += ft_putchar(save[i]);
		}
		else if (save[i] != '%')
			char_count += ft_putchar(save[i]);
		i++;
	}
	return (char_count);
}

int			ft_printf(const char *input, ...)
{
	const char	*save;
	va_list		args;
	int			char_count;

	save = ft_strdup(input);
	char_count = 0;
	va_start(args, input);
	char_count += ft_treat_save(save, args);
	va_end(args);
	free((char *)save);
	return (char_count);
}
