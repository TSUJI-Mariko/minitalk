/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:38:09 by mtsuji            #+#    #+#             */
/*   Updated: 2021/12/27 16:01:21 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	ft_putnbr(int nb);

#endif
