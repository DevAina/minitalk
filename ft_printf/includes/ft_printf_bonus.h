/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:10:33 by trarijam          #+#    #+#             */
/*   Updated: 2024/03/28 15:48:21 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	width;
	int	hash;
	int	plus;
	int	space;
	int	precision;
}	t_flags;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	putchar_count(char c, int len);
t_flags	init_flags(void);
void	parse_flags(const char **format, t_flags *flags);
void	parse_flags_width_precision(const char **format, t_flags *flags);
int		print_digit_with_flags(va_list args, t_flags flags);
int		print_unsigned_with_flags(va_list args, t_flags flags);
int		print_str_with_flags(va_list args, t_flags flags);
int		print_char_with_flags(va_list args, t_flags flags);
int		print_ptrvoid_with_flags(va_list args, t_flags flags);
int		print_digit_hexa(va_list args, t_flags flags, char format);
void	parse_conversions(va_list args, const char **format, t_flags flags,
			int *nb_char);
void	parse_format(va_list args, const char *format, int *nb_char);
int		ft_printf(const char *format, ...);

#endif
