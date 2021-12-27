/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:15:56 by mtsuji            #+#    #+#             */
/*   Updated: 2021/12/27 16:08:14 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	bit_handler(int signals)
{
	static int	bit_received;
	static char	c;

	bit_received = 0;
	c = 0;
	if (signals == SIGUSR1)
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
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, bit_handler);
	signal(SIGUSR2, bit_handler);
	while (1)
		pause();
	return (0);
}
