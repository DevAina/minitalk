/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:31:12 by trarijam          #+#    #+#             */
/*   Updated: 2024/03/21 11:38:25 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_char(va_list args)
{
	ft_putchar(va_arg(args, int));
	return (1);
}

int	print_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return ((int)ft_strlen(str));
}

int	print_digit(va_list args)
{
	int	nb;
	int	nb_char;

	nb = va_arg(args, int);
	nb_char = 0;
	if (nb == -2147483648)
	{
		nb_char += write(1, "-2147483648", 11);
		return (nb_char);
	}
	if (nb < 0)
	{
		nb_char += write(1, "-", 1);
		ft_putnbr(-nb);
		nb *= -1;
		return (nb_char += digit_len(-nb));
	}
	else
		ft_putnbr(nb);
	return (nb_char += digit_len(nb));
}

int	print_unsigned_int(va_list args)
{
	unsigned int	nb;
	unsigned int	tmp;
	int				len;

	nb = va_arg(args, unsigned int);
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	tmp = nb;
	len = 0;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	put_unsigned_int(nb);
	return (len);
}

int	print_digit_hexa(va_list args, char format)
{
	int				nb_char;
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	nb_char = 0;
	ft_puthex(nb, format, &nb_char);
	return (nb_char);
}
