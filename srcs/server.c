/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:15:56 by mtsuji            #+#    #+#             */
/*   Updated: 2021/12/29 18:17:38 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	bit_handler(int signum)
{
	static int	bit_received = 0;
	static char	c = 0;

	if (signum == SIGUSR1)
		c |= (1 << bit_received);
	bit_received++;
	if (bit_received == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			ft_putchar('\n');
		bit_received = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("PID is :");
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, bit_handler);
		signal(SIGUSR2, bit_handler);
		pause();
	}
	return (0);
}
