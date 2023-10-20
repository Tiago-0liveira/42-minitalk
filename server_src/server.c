/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:26:51 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/20 16:37:00 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"
/* 
static void	sig_action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (!client_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		i = 0;
		ft_printf("Client PID: %d\n", client_pid);
	}
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar(c);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
} */

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	t_vars	*vars;
	int		bit;

	(void)info;
	(void)context;
	bit = get_bit(sig);
	vars = get_vars();
	vars->bits_buffer[vars->buffer_index++] = bit;
	vars->bits_n++;
	if (vars->buffer_index == 8)
	{
		char	ch;
		
		ch = get_char_from_bits_array(vars->bits_buffer);
		if (!ch)
		{
			ft_printf("%s\n", vars->message);
			vars->is_initialized = 0;//this will reset the variable
			//ft_printf("received %s chars | %d bytes\n", (int)(vars->bits_n / 8), vars->bits_n);
			ft_printf("Closed the client\n");
		} else
		{
			vars->message = ft_strjoinchar(vars->message, ch);
			vars->buffer_index = 0;
		}		
	}
}
char	get_char_from_bits_array(int *bits_arr)
{
	unsigned char c;
    int index;

	c = 0;
	index = 0;
    while (index < 8) {
        c = (c << 1) | bits_arr[index];
        index++;
    }
    return c;
}

void	kill_process()
{
	t_vars	*vars;

	vars = get_vars();
	if (vars->message)
		free(vars->message);
	exit(EXIT_SUCCESS);
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

t_vars *get_vars()
{
	static t_vars vars;
	if (!vars.is_initialized)
	{
		vars.is_initialized = 1;
		vars.c_pid = 0;
		vars.c_pid = getpid();
		vars.bits_n = 0;
		ft_bzero(vars.bits_buffer, 8);
		vars.buffer_index = 0;
		vars.message = malloc(1);
		if (!vars.message)
			exit(EXIT_FAILURE);
		vars.message[0] = '\0';
	}
	return (&vars);
}

//# define TEST

# ifdef TEST
int main(void)
{
	int t[8] = {0,1,1,0,0,0,0,1};
	ft_printf("%c|\n", get_char_from_bits_array(t));
	/* char *sd;
	sd = malloc(2);
	if (!sd)
		return (EXIT_FAILURE);
	
	ft_strcpy(sd, "s");
	ft_printf("%s\n", sd);
	sd = ft_strjoinchar(sd, 'd');
	ft_printf("%s|\n", sd); */
	return (0);
}
# endif
# ifndef TEST
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
# endif