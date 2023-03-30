/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:32:57 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/30 11:46:13 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back_ends(t_pile *a, t_pile *b)
{
	if (b->pile[0][0] < a->pile[0][0])
		push(b, a, 'a');
	else
	{
		push(b, a, 'a');
		rotate(a, 'a');
	}
	push(b, a, 'a');
}

static int	smallest_value(t_pile *src)
{
	int	smallest;
	int	i;

	i = 0;
	smallest = src->pile[0][0];
	while (i < src->size)
	{
		if (src->pile[0][i] < smallest)
			smallest = src->pile[0][i];
		i++;
	}
	return (smallest);
}

void	sort_5(t_pile *a, t_pile *b)
{
	int	*o_tab;

	while (a->size != 3)
	{
		if (a->pile[0][0] == find_biggest(a)
			|| a->pile[0][0] == smallest_value(a))
			push(a, b, 'b');
		else
			rotate(a, 'a');
	}
	o_tab = save_pile(a);
	if (o_tab == NULL)
		return ;
	if (check_if_sorted(a->pile[0], a->size) == -1)
		sort_3(a, o_tab);
	push_back_ends(a, b);
	free(o_tab);
}
