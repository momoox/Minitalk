/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:15:37 by mgeisler          #+#    #+#             */
/*   Updated: 2023/05/27 18:15:59 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

void signal_handler(int signum)
{
	static char c;
	static int i;

	c <<= 1;
	if(signum == SIGUSR1)
		c += 1;
	i++;
	if(i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int main()
{
	pid_t getpid();
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while(1)
		pause();
}