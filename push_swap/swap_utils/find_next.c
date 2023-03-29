/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:33:46 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 11:34:51 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

int			find_next_idx(t_pile *pile, int elt)
{
	int	i;
	int	big_elt;

	i = 0;
	big_elt = find_biggest(pile);
	while (i < pile->size)
	{
		if (pile->pile[0][i] > elt && pile->pile[0][i] < big_elt)
			big_elt = pile->pile[0][i];
		i++;
	}
	return (find_idx(pile, big_elt));
}
