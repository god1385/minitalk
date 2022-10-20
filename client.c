/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:09:06 by ctorrek           #+#    #+#             */
/*   Updated: 2022/03/10 21:32:48 by ctorrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert(int c, int pid)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if (c >> i & 1)
		{
			kill(pid, SIGUSR1);
			usleep (500);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep (500);
		}
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	counter = 0;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		counter++;
	else if (sig == SIGUSR2)
	{
		counter++;
		write(1, "Letters received : ", ft_strlen("Letters received : "));
		ft_putnbr(counter);
		write(1, "\n", 1);
		exit(0);
	}
	usleep(5000);
}

void	kostil(char **argv, int i, int pid)
{
	while (argv[2][i])
	{
		convert((int)argv[2][i], pid);
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	a;
	int					pid;
	int					i;

	a.sa_flags = SA_SIGINFO;
	a.sa_sigaction = handler;
	sigaction(SIGUSR1, &a, 0);
	sigaction(SIGUSR2, &a, 0);
	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == 0 || pid < 0)
		{
			write(1, "Invalid PID!\n", 13);
			return (0);
		}
		kostil(argv, i, pid);
		convert(0, pid);
		while (1)
			pause();
	}
	else
		write(1, "Usage: ./client [PID] [STRING_TO_PASS]\n", 40);
	return (0);
}
