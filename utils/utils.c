/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:41:19 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/20 16:18:38 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common.h"

char	*ft_strjoinchar(char const *s1, char const c)
{
	int		s1l;
	char	*d;

	s1l = ft_strlen(s1);
	d = malloc(s1l + 2);
	if (d == NULL)
		return (NULL);
	ft_strcpy(d, s1);
	d[s1l] = c;
    d[s1l + 1] = '\0';
	return (d);
}   