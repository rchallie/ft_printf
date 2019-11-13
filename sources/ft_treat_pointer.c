/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:32:27 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/11 13:36:59 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_treat_pointer(unsigned long long ull, t_flags flags)
{
	char *pointer;
	pointer = ft_ull_base(ull, 16);
	pointer = ft_str_tolower(pointer);
	if (flags.minus == 1)
	{
		ft_putstr("0x", 2);
		ft_putstr(pointer, ft_strlen(pointer));
	}
	ft_treat_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
	{
		ft_putstr("0x", 2);
		ft_putstr(pointer, ft_strlen(pointer));
	}
	free(pointer);
}