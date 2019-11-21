/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:06:58 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/20 17:40:25 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*treat_base(unsigned long long ull_save, int base,
char *rtn, int count)
{
	while (ull_save != 0)
	{
		if ((ull_save % base) < 10)
			rtn[count - 1] = (ull_save % base) + 48;
		else
			rtn[count - 1] = (ull_save % base) + 55;
		ull_save /= base;
		count--;
	}
	return (rtn);
}

char		*ft_ull_base(unsigned long long ull, int base)
{
	char				*rtn;
	unsigned long long	ull_save;
	int					count;

	rtn = 0;
	count = 0;
	ull_save = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	if (!(rtn = malloc(sizeof(char) * (count + 1))))
		return (0);
	rtn[count] = '\0';
	rtn = treat_base(ull_save, base, rtn, count);
	return (rtn);
}
