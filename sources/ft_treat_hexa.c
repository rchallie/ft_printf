/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:49:50 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/12 18:21:58 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_treat_hexa(unsigned long long ull, int lower, t_flags flags)
{
	int		char_count;
	char	*hexa;

	char_count = 0;
	
	if (ull == 0)
		return (ft_putstr("0", 1));
	hexa = ft_ull_base(ull, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	if (flags.minus == 1)
		char_count += ft_putstr(hexa, ft_strlen(hexa));
	char_count += ft_treat_width(flags.width, ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		char_count += ft_putstr(hexa, ft_strlen(hexa));
	free(hexa);
	return (char_count);
}
