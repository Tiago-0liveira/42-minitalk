/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:27:36 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/07/29 15:55:36 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_printf("%d successfully sent characters\n", received);
		exit(0);
	}
}

static void	send_message_to_pid(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf(PROGRAM_USAGE);
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	ft_printf("Sending message to PID %d\n", server_pid);
	ft_printf("Message: %s\n", message);
	ft_printf("Message size: %d|%d bytes\n", ft_strlen(message), \
	ft_strlen(message) * 8);
	send_message_to_pid(server_pid, message);
	while (1)
		pause();
	return (0);
}
