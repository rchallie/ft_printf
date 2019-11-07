/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:44:44 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/07 16:30:20 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef	struct		s_flags
{
	int				already_print;
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

int			ft_printf(const char *str, ...);
int			ft_is_in_type_list(int c);
int			ft_is_in_flags_list(int c);
int			ft_treatment(int c, t_flags flags, va_list args);
int			ft_treat_width(int width, int minus, int has_zero);

void		ft_putchar(int c);
void		ft_putstr(char *str);

char		*ft_ull_base(unsigned long long ull, int base);
char		*ft_u_itoa(unsigned int n);
char		*ft_str_tolower(char *str);


#endif