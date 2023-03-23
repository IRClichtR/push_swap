/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_rrb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:50:39 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/21 18:15:11 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*loop_rrb(t_pile *pile, int idx)
{
	char	*res;
	char	*new_res;

	res = ft_calloc(2, sizeof(char));
	if (!res)
		return (NULL);
	res = "_";
	while (idx != pile->size)
	{
		rev_rotate(pile);
		new_res = ft_strjoin(res, "rrb ");
		if (new_res == NULL)
			return (free(res), NULL);
		res = new_res;
		idx++;
	}
	return (res);
}
