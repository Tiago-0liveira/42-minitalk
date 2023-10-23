/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:41:19 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/23 00:51:30 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common.h"

/*char	*ft_strjoinchar(char **s1, char c)
{
	int		s1l;
	char	*d;

	s1l = ft_strlen(*s1);
	d = malloc(s1l + 2);
	if (d == NULL)
		return (NULL);
	ft_strcpy(d, *s1);
	free(*s1);
	d[s1l] = c;
	d[s1l + 1] = '\0';
	return (d);
}*/

int	dyn_str_append_character(t_dyn_str *ds, char c)
{
	char	*tmp;

	if (ds->index % STRING_CHUNK_SIZE == 0)
	{
		tmp = malloc((ds->index + STRING_CHUNK_SIZE + 1) * sizeof(char));
		if (tmp == NULL)
			return (EXIT_FAILURE);
		if (ds->str)
		{
			ft_strcpy(tmp, ds->str);
			free(ds->str);
		}
		ds->str = tmp;
	}
	ds->str[ds->index++] = c;
	ds->str[ds->index] = '\0';
	return (EXIT_SUCCESS);
}

t_dyn_str	*dyn_str_init(void)
{
	t_dyn_str	*str;

	str = (t_dyn_str *)malloc(sizeof(t_dyn_str));
	if (str == NULL)
		return (NULL);
	str->str = NULL;
	str->index = 0;
	return (str);
}
