/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:48:19 by ialves-m          #+#    #+#             */
/*   Updated: 2023/03/02 18:04:56 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	len(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	message_send(char *pid_nbr, char *message)
{
	__pid_t	pid;
	int		i;
	int		j;
	int		mask;
	int		size;

	i = 0;
	j = 0;
	mask = 0b00000001;
	size = len(message);
	pid = atoi(pid_nbr);
	while (i <= size)
	{
		while (j < 8)
		{
			if (message[i] & (mask << j++))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
		}
		j = 0;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		message_send(argv[1], argv[2]);
}
