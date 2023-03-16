/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_push_comp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:54:27 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/10 12:15:56 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

int	check_if_push_comp(t_pile *a, int *sorted_tab, int chunk, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < size)
		{
			if (a->pile[0][i] == sorted_tab[j] &&
			create_chunks(sorted_tab, size, sorted_tab[i]) == chunk)
				return (1);
		}
		i++;
	}
	return (0);
}
