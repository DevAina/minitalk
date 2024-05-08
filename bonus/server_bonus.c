/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:18:27 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/08 18:18:31 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	static unsigned char c;
	static int size;

	if (sig == SIGUSR2)
		c |= (1 << (7 - size));
	size++;
	if (size == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			if (kill(info->si_pid, SIGUSR1) == -1)
				exit(1);
		}
		write(1, &c, 1);
		c = 0;
		size = 0;
	}
}

int	main(void)
{
	struct sigaction siga;

	ft_printf("\033[0;34mPID: %d\n\033[0m", getpid());
	ft_printf("STRING:");
	while (1)
	{
		siga.sa_flags = SA_SIGINFO;
		siga.sa_sigaction = handler;
		sigaction(SIGUSR1, &siga, NULL);
		sigaction(SIGUSR2, &siga, NULL);
	}
}
