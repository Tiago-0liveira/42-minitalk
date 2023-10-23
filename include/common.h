/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagoliv <tiagoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:43:46 by tiagoliv          #+#    #+#             */
/*   Updated: 2023/10/23 14:11:20 by tiagoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../libft/libft.h"
# include <signal.h>
# define STRING_CHUNK_SIZE 20

typedef struct _dyn_str {
	char	*str;
	int		index;
}	t_dyn_str;
//char	*ft_strjoinchar(char **s1, char c);
int			dyn_str_append_character(t_dyn_str *ds, char c);
t_dyn_str	*dyn_str_init(void);
char		get_char_from_bits_array(int *bits_arr);

#endif