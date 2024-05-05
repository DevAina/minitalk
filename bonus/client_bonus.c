#include "../include/minitalk.h"

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
		send_bit_by_bit(pid, c, size);
		size--;
		usleep(100);
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

void	handler(int sig)
{
	(void)sig;
	ft_printf("Message received\n");
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, handler);
		send_message(pid, argv[2]);
	}
	return (1);
}
