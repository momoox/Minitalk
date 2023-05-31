/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:15:37 by mgeisler          #+#    #+#             */
/*   Updated: 2023/05/31 14:40:22 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

void	print_string(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;

	(void)context;
	(void)info;
	c <<= 1;
	if (signum == SIGUSR1)
		c += 1;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	pid_t				getpid();

	(void)argc;
	(void)argv;
	ft_printf("PID: %d\n", getpid());
	act.sa_sigaction = print_string;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
