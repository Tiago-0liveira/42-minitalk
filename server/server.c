/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:26:51 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/07/29 02:28:35 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"
#include "../include/common.h"


int	main(void)
{
	int	process_id;

	process_id = getpid();

	ft_putnbr_fd(process_id, 1);
	ft_putchar_fd('\n', 1);
	ft_printf("Server PID: %d\n", process_id);
}
