/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:54:49 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/01 11:50:40 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendsignals(int pid, char c)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if ((c & (0x01 << i)) != 0)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(100);
		i++;
	}
}

void	receivedsignal(int s)
{
	if (s == SIGUSR1)
		ft_printf("signal received\n");
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("les argument doivent etre \"PID\" \"chaine de characters\"\n");
		return (0);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, receivedsignal);
	while (argv[2][i])
	{	
		sendsignals(pid, argv[2][i]);
		i++;
	}
	sendsignals(pid, '\n');
}
