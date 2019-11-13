/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:58:00 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/12 11:24:40 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_put_part_uint(char *unsi_int, t_flags flags)
{
	if (flags.minus == 1)
	{
		if (flags.dot == -1)
			ft_putstr(unsi_int, ft_strlen(unsi_int));
		else
			ft_putstr(unsi_int, flags.dot);
	}
	ft_treat_width(flags.width, ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
	{
		if (flags.dot == -1)
			ft_putstr(unsi_int, ft_strlen(unsi_int));
		else
			ft_putstr(unsi_int, flags.dot);
	}
}

void		ft_treat_uint(unsigned int unsi, t_flags flags)
{
	char				*unsi_int;

	unsi = (unsigned int)(4294967295 + 1
				+ unsi);
	unsi_int = ft_u_itoa(unsi);
	ft_put_part_uint(unsi_int, flags);
	free(unsi_int);
}
