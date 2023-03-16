/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:50:54 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/16 17:08:19 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*sort_3(t_pile *a)
{
	int		*o_tab;

	o_tab = keep_tracks(pile, size);
	if (o_tab[0] > o_tab[1] && o_tab[1] < o_tab[2] && o_tab[2] < o_tab[0])
		rotate(a);
	if (o_tab[0] > o_tab[1] && o_tab[1] < o_tab[2] && o_tab[0] < o_tab[2])
		swap(a);
	if (o_tab[0] < o_tab[1] && o_tab[1] > o_tab[2])
		rev_rotate(a);
	if (o_tab[0] < o_tab[1] && o_tab[1] > o_tab[2] && o_tab[0] < o_tab[2])
	{
		swap(a);
		rotate(a);
	}
	if (o_tab[0] > o_tab[1] && o_tab[1] > o_tab[2])
	{
		swap(a);
		rev_rotate(a);
	}
}

char		*sort_a_left(t_pile *a)
{
	int		*o_tab;

	o_tab = keep_tracks(pile, size);
	if (check_if_sorted(a) == 1)
		return ("");
	sort_3(a);
	if (o_tab[0] > o_tab[1] && o_tab[1] < o_tab[2] && o_tab[2] < o_tab[0])
		return ("ra ");
	if (o_tab[0] > o_tab[1] && o_tab[1] < o_tab[2] && o_tab[0] < o_tab[2])
		return ("sa ");
	if (o_tab[0] < o_tab[1] && o_tab[1] > o_tab[2])
		return ("rra ");
	if (o_tab[0] < o_tab[1] && o_tab[1] > o_tab[2] && o_tab[0] < o_tab[2])
		return ("sa ra");
	if (o_tab[0] > o_tab[1] && o_tab[1] > o_tab[2])
		return ("sa rra");
}
