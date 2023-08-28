/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:54:44 by cdupuis           #+#    #+#             */
/*   Updated: 2023/05/01 11:39:50 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_trtmt(int signal, siginfo_t *r_info, void *s)
{
	static int	i;
	static int	c;

	(void)s;
	if (signal == SIGUSR1)
	{
		c |= (1 << i);
		i++;
	}
	else if (signal == SIGUSR2)
	{
		c |= (0 << i);
		i++;
	}
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == '\n')
			kill(r_info->si_pid, SIGUSR1);
		i = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	response;

	(void)argv;
	if (argc != 1)
	{
		return (0);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	ft_printf("waiting...\n");
	response.sa_sigaction = sig_trtmt;
	sigemptyset(&response.sa_mask);
	response.sa_flags = 0;
	sigaction(SIGUSR1, &response, NULL);
	sigaction(SIGUSR2, &response, NULL);
	while (1 == 1)
	{
		pause();
	}
	return (0);
}
