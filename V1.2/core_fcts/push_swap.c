/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:47:52 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/10 10:21:41 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*push_swap(t_pile *pile_a, t_pile *pile_b)
{
	int		*sorted_tab;

	sorted_tab = sort_pile(a->pile);
	if (sorted_tab == NULL)
		return ;
	push_to_b(a, b, a->size);
	sort_a_left(a);
	push_back(a, b);
	free(sorted_tab);
}
