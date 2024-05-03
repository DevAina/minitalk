/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:16:55 by trarijam          #+#    #+#             */
/*   Updated: 2024/03/26 15:38:30 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# include "../libft/libft.h"

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		digit_len(int nb);
void	put_unsigned_int(unsigned int nb);
void	ft_puthex(unsigned int nb, char format, int *nb_char);
void	ft_putptr(void *ptr, int *nb_Char);
int		print_ptrvoid(va_list args);
int		print_char(va_list args);
int		print_str(va_list args);
int		print_digit(va_list args);
int		print_unsigned_int(va_list args);
int		print_digit_hexa(va_list args, char format);
void	analyze_format(va_list args, const char *format, int *nb_char);
int		ft_printf(const char *format, ...);

#endif
