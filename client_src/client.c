/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:27:36 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/24 15:41:48 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

void	action(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR1)
	{
		ft_printf("  Message sent successfully.\n");
		exit(EXIT_FAILURE);
	}
	else if (sig == SIGINT)
		exit(EXIT_SUCCESS);
}

void	send_message_size_to_pid(pid_t pid, int size)
{
	unsigned long	i;
	int				bit;

	i = 0;
	while (i < sizeof(int) * 8)
	{
		bit = (size >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		i++;
	}
}

void	send_message_to_pid(int pid, char *str)
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
			usleep(DELAY_USLEEP);
		}
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	s_sigaction;
	int					server_pid;
	char				*message;

	if (argc != 3)
	{
		ft_printf(PROGRAM_USAGE);
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	sigemptyset(&s_sigaction.sa_mask);
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = &action;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	sigaction(SIGINT, &s_sigaction, NULL);
	ft_printf("Message: %s\n", message);
	ft_printf("Message size: %d|%d bytes\n", ft_strlen(message),
		ft_strlen(message) * 8);
	send_message_size_to_pid(server_pid, ft_strlen(message));
	send_message_to_pid(server_pid, message);
	while (1)
		pause();
	return (0);
}
