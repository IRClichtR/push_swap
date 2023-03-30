/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_idxa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:35:14 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/30 12:42:02 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

int	select_idxa(t_pile *a, int *sorted_tab, int chunk)
{
	int	idx_rot;
	int	idx_rev;

	idx_rot = 0;
	idx_rev = a->size - 1;
	while (idx_rot < a->size / 2 || idx_rev <= a->size / 2)
	{
		if (create_chunks(sorted_tab, a->size, a->pile[0][idx_rev]) == chunk
			|| create_chunks(sorted_tab, a->size, a->pile[0][idx_rot]) == chunk)
			break ;
		idx_rot++;
		idx_rev--;
	}

	if (a->size - idx_rot < a->size - idx_rev)
		return (idx_rot);
	else
		return (idx_rev);
}
