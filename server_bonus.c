/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:15:15 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/27 15:33:09 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(int nbr)
{
	write (1, &nbr, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putnbr(n / 10);
		ft_putchar('8');
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void	ft_putstr(char	*s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			write(1, &s[i++], 1);
}

void	handler_data(int signal, siginfo_t *info, void *secret)
{
	static int	count;
	static char	c;
	int			bit;
	pid_t		sinal;

	(void)secret;
	sinal = info->si_pid;
	bit = (signal == SIGUSR2);
	c |= bit << count;
	if (count == 7)
	{
		ft_putchar(c);
		kill(sinal, SIGUSR1);
		count = -1;
		c = 0;
	}
	count++;
}

int	main(void)
{
	struct sigaction	siga;

	siga.sa_sigaction = handler_data;
	siga.sa_flags = SA_SIGINFO;
	sigemptyset(&siga.sa_mask);
	sigaddset(&siga.sa_mask, SIGUSR2);
	sigaddset(&siga.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
}
