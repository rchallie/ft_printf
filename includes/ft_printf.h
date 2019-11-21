/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:44:44 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/20 17:12:32 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

int					ft_printf(const char *str, ...);
int					ft_is_in_type_list(int c);
int					ft_is_in_flags_list(int c);
int					ft_treatment(int c, t_flags flags, va_list args);
int					ft_treat_width(int width, int minus, int has_zero);
int					ft_putstrprec(char *str, int prec);
int					ft_treat_char(char c, t_flags flags);
int					ft_treat_string(char *str, t_flags flags);
int					ft_treat_int(int i, t_flags flags);
int					ft_treat_percent(t_flags flags);
int					ft_treat_hexa(unsigned int ui, int lower, t_flags flags);
int					ft_treat_uint(unsigned int unsi, t_flags flags);
int					ft_flag_dot(const char *save, int start,
					t_flags *flags, va_list args);
int					ft_putchar(int c);
int					ft_treat_pointer(unsigned long long pointer, t_flags flags);

char				*ft_ull_base(unsigned long long ull, int base);
char				*ft_u_itoa(unsigned int n);
char				*ft_str_tolower(char *str);

t_flags				ft_flag_minus(t_flags flags);
t_flags				ft_flag_width(va_list args, t_flags flags);
t_flags				ft_flag_digit(char c, t_flags flags);

#endif
