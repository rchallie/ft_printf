/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:33:15 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/16 11:33:10 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putstr(char *str, int prec)
{
	int char_count;

	char_count = 0;
	while (str[char_count] && char_count < prec)
		ft_putchar(str[char_count++]);
	return (char_count);
}
