/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rrarrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:01:20 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/10 19:19:43 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

static char	*rra_or_rrb(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*res;

	if (idx_a == 0)
		res = loop_rrb(b, idx_b);
	else
		res = loop_rra(a, idx_a);
	return (res);
}

char		*move_rrarrb(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*res;
	char	*temp;
	int		save_a;
	int		save_b;

	save_a = value_at_idx(a, idx_a);
	save_b = value_at_idx(b, idx_b);
	res = loop_rrr(a, b, idx_a, idx_b);
	if (res == NULL)
		return (NULL);
	if (idx_a == idx_b)
		return (res);
	idx_a = find_idx(a, save_a);
	idx_b = find_idx(b, save_b);
	temp = rra_or_rrb(a, b, idx_a, idx_b);
	if (temp == NULL)
		return (res);
	res = join_f(res, temp);
	free(temp);
	return (res);
}
