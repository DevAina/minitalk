/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:58:47 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/03 10:32:31 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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
		send_bit(pid, c, size);
		size--;
		usleep(100);
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
	int pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_string(pid, argv[2]);
		return (0);
	}
	return (1);
}
