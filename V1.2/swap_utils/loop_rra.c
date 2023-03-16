/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:50:55 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/09 18:23:38 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*loop_rra(t_pile *pile, int idx)
{
	char	*res;
	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	while (idx != pile->size)
	{
		rev_rotate(pile);
		res = join_f(res, "rra ");
		if (res == NULL)
			break ;
		idx++;
	}
	return (res);
}
