/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:26:47 by trarijam          #+#    #+#             */
/*   Updated: 2024/06/11 15:51:46 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_bit_receved = 0;

void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_bit_receved = 1;
	if (sig == SIGUSR2)
		ft_printf("Message received\n");
}

void	send_bit_by_bit(int pid, char c, int size)
{
	if ((c >> size) & 1)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			exit(1);
	}
}

void	send_char(int pid, char c)
{
	int	size;

	size = 7;
	while (size >= 0)
	{
		g_bit_receved = 0;
		send_bit_by_bit(pid, c, size);
		size--;
		while (!g_bit_receved)
			pause();
	}
}

void	send_message(int pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		send_message(pid, argv[2]);
		return (0);
	}
	return (1);
}
