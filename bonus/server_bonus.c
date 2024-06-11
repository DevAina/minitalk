/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:00:20 by trarijam          #+#    #+#             */
/*   Updated: 2024/06/11 15:51:05 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static char	*block_else_for_concatain_str(char *str, char c)
{
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 2));
	if (new_str == NULL)
	{
		ft_printf("Error: malloc\n");
		exit(1);
	}
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(str);
	return (new_str);
}

char	*concatain_str(char *str, char c)
{
	if (str == NULL)
	{
		str = malloc(sizeof(char) * 2);
		if (str == NULL)
		{
			ft_printf("Error: malloc\n");
			exit(1);
		}
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	return (block_else_for_concatain_str(str, c));
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	*str;
	static char	c;
	static int	size;

	(void)context;
	if (sig == SIGUSR2)
		c |= (1 << (7 - size));
	size++;
	if (size == 8)
	{
		str = concatain_str(str, c);
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
			kill(info->si_pid, SIGUSR2);
		}
		c = 0;
		size = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(1);
}

int	main(void)
{
	struct sigaction	siga;

	ft_printf("\033[0;34mPID: %d\n\033[0m", getpid());
	ft_printf("STRING:");
	sigemptyset(&siga.sa_mask);
	siga.sa_flags = SA_SIGINFO | SA_RESTART;
	siga.sa_sigaction = &handler;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
		pause();
}
