/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_previous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:12:26 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/10 13:13:58 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

int	find_previous_idx(t_pile *pile, int elt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < pile->size)
	{
		if (pile->pile[0][i] < elt)
		{
			if (pile->pile[0][j] < pile->pile[0][i])
				j = i;
		}
		i++;
	}
	return (j);
}
