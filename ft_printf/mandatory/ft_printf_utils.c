/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:05:06 by trarijam          #+#    #+#             */
/*   Updated: 2024/04/03 15:19:00 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	digit_len(int nb)
{
	int	digit_len;

	if (nb == 0)
		return (1);
	digit_len = 0;
	while (nb)
	{
		nb /= 10;
		digit_len++;
	}
	return (digit_len);
}

void	put_unsigned_int(unsigned int nb)
{
	if (nb < 10)
		ft_putchar('0' + nb);
	else
	{
		put_unsigned_int(nb / 10);
		put_unsigned_int(nb % 10);
	}
}

void	ft_puthex(unsigned int nb, char format, int *nb_char)
{
	char	c;

	if (nb >= 16)
		ft_puthex(nb / 16, format, nb_char);
	nb = nb % 16;
	if (nb < 10)
	{
		c = nb + '0';
		(*nb_char) += write(1, &c, 1);
	}
	else
	{
		if (format == 'x')
		{
			c = (nb - 10) + 'a';
			(*nb_char) += write(1, &c, 1);
		}
		else if (format == 'X')
		{
			c = (nb - 10) + 'A';
			(*nb_char) += write(1, &c, 1);
		}
	}
}

void	ft_putptr(void *ptr, int *nb_char)
{
	unsigned long	address;
	char			hexa_address[16];
	char			*hex;
	int				i;
	int				j;

	address = (unsigned long)ptr;
	hex = "0123456789abcdef";
	i = 15;
	hexa_address[i] = '\0';
	while (address > 0)
	{
		hexa_address[i--] = hex[address % 16];
		address /= 16;
	}
	j = i + 1;
	while (j < 16)
	{
		ft_putchar(hexa_address[j++]);
		(*nb_char) += 1;
	}
}

int	print_ptrvoid(va_list args)
{
	void	*ptr;
	int		nb_char;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr("0x");
	nb_char = 2;
	ft_putptr(ptr, &nb_char);
	return (nb_char);
}
