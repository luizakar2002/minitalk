/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:58:07 by lukarape          #+#    #+#             */
/*   Updated: 2021/07/27 14:58:09 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(int pid, char ch)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((ch >> i & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		i--;
		usleep(50);
	}
}

void	handle_str(char *pid, char *str)
{
	int		p;

	p = ft_atoi(pid);
	while (*str)
	{
		send_byte(p, *str);
		str++;
	}
	if (*str == '\0')
		send_byte(p, *str);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "./client <pid> <str>\n", 23);
		return (0);
	}
	handle_str(argv[1], argv[2]);
	return (0);
}
