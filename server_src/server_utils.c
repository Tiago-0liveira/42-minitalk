/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:14:51 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/24 15:08:13 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

t_vars	*check_bit(int sig, siginfo_t *info)
{
	t_vars	*vars;
	int		bit;

	vars = get_vars();
	bit = get_bit(sig);
	if (vars->size.index < vars->size.int_size)
		vars->size.buffer[vars->size.index++] = bit;
	if (vars->size.index == vars->size.int_size && !vars->size.done)
	{
		vars->size.size = get_int_from_bit_array(&vars->size);
		vars->size.done = 1;
		vars->msg = dyn_str_init(vars->size.size);
		if (!vars->msg)
			kill_process();
		printf("vars->size.size:%zu\n", vars->size.size);
	}
	else if (vars->size.done)
		vars->bits_buffer[vars->buffer_index++] = bit;
	if (!vars->c_pid)
		vars->c_pid = info->si_pid;
	vars->bits_n++;
	return (vars);
}

size_t	get_int_from_bit_array(t_int_size *int_size)
{
	int		i;
	size_t	result;

	i = int_size->int_size - 1;
	result = 0;
	while (i >= 0)
	{
		result = (result << 1) | int_size->buffer[i];
		i--;
	}
	return (result);
}
