/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:16:16 by mtsuji            #+#    #+#             */
/*   Updated: 2021/12/28 23:20:03 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_char_to_bit(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))//データの一部分を調べている？
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(500);
	}
}

void	send_string(pid_t pid, char *str)
{
	while (*str)
	{
		send_char_to_bit(pid, *str);
		str++;
	}
	send_char_to_bit(pid, '\0');
}

int	main(int argc, char *argv[])
{
	char	*str;
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_string(pid, str);
	}
	else
		ft_putstr("Error!\n");
	return (0);
}

