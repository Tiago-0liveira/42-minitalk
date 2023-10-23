/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:14:51 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/23 14:15:21 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

t_vars	*check_bit(int sig, siginfo_t *info)
{
	t_vars	*vars;

	vars = get_vars();
	vars->bits_buffer[vars->buffer_index++] = get_bit(sig);
	if (!vars->c_pid)
		vars->c_pid = info->si_pid;
	vars->bits_n++;
	return (vars);
}
