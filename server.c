/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:54:48 by yuocak            #+#    #+#             */
/*   Updated: 2025/02/10 13:08:59 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putnbr(int num)
{
	char	c;

	if (num > 9)
		ft_putnbr(num / 10);
	c = (num % 10) + 48;
	write(1, &c, 1);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char	messages = 0;
	static int	bit = 0;

	(void) context;
	if (sig == SIGUSR1)
		messages |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &messages, 1);
		messages = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					server_pid;
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	server_pid = getpid();
	ft_putnbr(server_pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
