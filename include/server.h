/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:24:08 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/23 00:08:31 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/types.h>
# include <unistd.h>
# include "../include/common.h"

# define MALLOC_MSG_SIZE 32

typedef struct _t_vars {
	int				is_initialized;
	pid_t			c_pid;
	pid_t			s_pid;
	unsigned long	bits_n;
	int				bits_buffer[8];
	int				buffer_index;
	t_dyn_str		*msg;
}	t_vars;

void	sig_handler(int sig, siginfo_t *info, void *context);
char	get_char_from_bits_array(int bits_arr[]);
void	kill_process(void);
int		get_bit(int sig);
t_vars	*get_vars(void);
char	*ft_strjoinchar(char **s1, char c);

#endif