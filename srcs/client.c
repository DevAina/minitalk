/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:58:47 by trarijam          #+#    #+#             */
/*   Updated: 2024/06/11 15:37:09 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_bit_received = 0;

void	handler(int sig)
{
	(void)sig;
	g_bit_received = 1;
}

void	send_bit(int pid, char c, int size)
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
		g_bit_received = 0;
		send_bit(pid, c, size);
		size--;
		while (!g_bit_received)
			pause();
	}
}

void	send_string(int pid, char *string)
{
	while (*string)
	{
		send_char(pid, *string);
		string++;
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
		send_string(pid, argv[2]);
		return (0);
	}
	return (1);
}
