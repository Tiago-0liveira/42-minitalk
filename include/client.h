/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:24:19 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/22 16:04:15 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../include/common.h"

# define PROGRAM_USAGE "Usage: ./client [server-pid] [message]\n"
# define DELAY_USLEEP 200

static void	action(int sig);
static void	send_message_to_pid(int pid, char *str);

#endif