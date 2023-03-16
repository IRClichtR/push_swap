/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:08 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/09 18:52:58 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*loop_ra(t_pile *pile, int idx)
{
	char	*res;

	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	while (idx != 0)
	{
		rotate(pile);
		res = join_f(res, "ra ");
		if (res == NULL)
			break ;
		idx--;
	}
	return (res);
}
