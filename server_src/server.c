/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:26:51 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/23 14:15:25 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	t_vars	*vars;
	char	ch;

	(void)context;
	vars = check_bit(sig, info);
	if (vars->buffer_index == 8)
	{
		ch = get_char_from_bits_array(vars->bits_buffer);
		if (!ch)
		{
			vars->is_initialized = 0;
			ft_printf("message: %s\n Closed the client.\n Received %d \
chars | %l bytes\n", vars->msg->str, (vars->bits_n - 8) / 8, vars->bits_n - 8);
			kill(vars->c_pid, SIGUSR2);
			free(vars->msg->str);
			ft_bzero(vars->bits_buffer, 8);
		}
		else
		{
			if (dyn_str_append_character(vars->msg, ch))
				kill_process();
			vars->buffer_index = 0;
		}
	}
}

int	get_bit(int sig)
{
	if (sig == SIGUSR1)
		return (0);
	else if (sig == SIGUSR2)
		return (1);
	else if (sig == SIGINT)
		kill_process();
	else
		kill_process();
	return (EXIT_FAILURE);
}

void	kill_process(void)
{
	t_vars	*vars;

	vars = get_vars();
	if (vars->msg)
	{
		if (vars->msg->str)
			free(vars->msg->str);
		free(vars->msg);
	}
	exit(EXIT_SUCCESS);
}

t_vars	*get_vars(void)
{
	static t_vars	vars;

	if (!vars.is_initialized)
	{
		vars.is_initialized = 1;
		vars.c_pid = 0;
		vars.bits_n = 0;
		ft_bzero(vars.bits_buffer, 8);
		vars.buffer_index = 0;
		vars.msg = dyn_str_init();
		if (!vars.msg)
			exit(EXIT_FAILURE);
	}
	return (&vars);
}

int	main(void)
{
	int					process_id;
	struct sigaction	s_sigaction;

	process_id = getpid();
	ft_printf("Server PID: %d\n", process_id);
	sigemptyset(&s_sigaction.sa_mask);
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	sigaction(SIGINT, &s_sigaction, NULL);
	while (1)
		pause();
	return (0);
}
