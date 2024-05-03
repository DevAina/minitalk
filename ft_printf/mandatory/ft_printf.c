/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:21:07 by trarijam          #+#    #+#             */
/*   Updated: 2024/03/21 11:38:39 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_percent(void)
{
	ft_putchar('%');
	return (1);
}

void	analyze_format(va_list args, const char *format, int *nb_char)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				*nb_char += print_char(args);
			else if (*format == 's')
				*nb_char += print_str(args);
			else if (*format == 'd' || *format == 'i')
				*nb_char += print_digit(args);
			else if (*format == 'u')
				*nb_char += print_unsigned_int(args);
			else if (*format == 'x' || *format == 'X')
				*nb_char += print_digit_hexa(args, *format);
			else if (*format == '%')
				(*nb_char) += print_percent();
			else if (*format == 'p')
				*nb_char += print_ptrvoid(args);
		}
		else
			*nb_char += write(1, format, 1);
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			nb_char;

	nb_char = 0;
	va_start(args, format);
	analyze_format(args, format, &nb_char);
	va_end(args);
	return (nb_char);
}
