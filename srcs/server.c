/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:33:15 by trarijam          #+#    #+#             */
/*   Updated: 2024/05/03 10:55:36 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler(int sig)
{
	static unsigned char c;
	static int size;

	if (sig == SIGUSR2)
		c |= (1 << (7 - size));
	size++;
	if (size == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		write(1, &c, 1);
		c = 0;
		size = 0;
	}
}

int main(void)
{
	struct sigaction siga;

	ft_printf("\033[0;34mPID: %d\n\033[0m", getpid());
	ft_printf("STRING:");
	while (1)
	{
		siga.sa_flags = 0;
		siga.sa_handler = handler;
		sigaction(SIGUSR1, &siga, NULL);
		sigaction(SIGUSR2, &siga, NULL);
	}
}
