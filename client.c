/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:46:12 by mgeisler          #+#    #+#             */
/*   Updated: 2023/05/31 14:35:30 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

int		ft_atoi(char *str);

void	sendchar(char c, int pid);

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	nb;

	i = 0;
	n = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		n *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (n * nb);
}

void	received(int signum)
{
	(void)signum;
	ft_printf("Message received\n");
}

void	sendchar(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	signal(SIGUSR1, received);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			sendchar(argv[2][i], pid);
			i++;
		}
		sendchar('\0', pid);
	}
	else
	{
		ft_printf("Error: wrong number of arguments\n");
		return (1);
	}
	return (0);
}
