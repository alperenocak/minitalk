/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:54:52 by yuocak            #+#    #+#             */
/*   Updated: 2025/02/10 19:31:59 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int		g_ack_received = 0;

void	ack_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "Congratss!!\n", 13);
	}
	g_ack_received = 1;
}

int	ft_atoi(char *str)
{
	int		i;
	long	res;

	res = 0;
	i = -1;
	while (str[++i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res > 2147483647)
			return (0);
	}
	return (res * (str[i] == '\0'));
}

void	ft_sendbit(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack_received = 0;
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack_received)
			pause();
		bit++;
	}
}

int	main(int ac, char **av)
{
	int					i;
	int					server_pid;
	struct sigaction	sa;

	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	server_pid = ft_atoi(av[1]);
	if (server_pid < 1)
	{
		write(1, "invalid pid\n", 12);
		return (0);
	}
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (ac != 3)
	{
		write(1, "./client <PID> <MESSAGE>\n", 25);
		return (0);
	}
	i = -1;
	while (av[2][++i])
		ft_sendbit(server_pid, av[2][i]);
	ft_sendbit(server_pid, av[2][i]);
	return (0);
}
