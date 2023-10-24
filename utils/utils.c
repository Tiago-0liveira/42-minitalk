/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:41:19 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/24 15:42:56 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common.h"

int	dyn_str_append_character(t_dyn_str *ds, char c)
{
	ds->str[ds->index++] = c;
	ds->str[ds->index] = '\0';
	return (EXIT_SUCCESS);
}

t_dyn_str	*dyn_str_init(int size)
{
	t_dyn_str	*str;

	str = (t_dyn_str *)malloc(sizeof(t_dyn_str));
	if (str == NULL)
		return (NULL);
	str->str = malloc(size + 1);
	if (!str->str)
		return (NULL);
	str->index = 0;
	return (str);
}

char	get_char_from_bits_array(int *bits_arr)
{
	unsigned char	c;
	int				index;

	c = 0;
	index = 0;
	while (index < 8)
	{
		c = (c << 1) | bits_arr[index];
		index++;
	}
	return (c);
}
