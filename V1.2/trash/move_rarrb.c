/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rarrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:38:03 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/09 20:27:58 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*move_rarrb(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*res;
	char	*ra;
	char	*rrb;

	ra = loop_ra(a, idx_a);
	if (ra == NULL)
		return (NULL);	
	rrb = loop_rrb(b, idx_b);
	if (rrb == NULL)
		return (ra);
	res = join_f(ra, rrb);
	return (free(rrb), res);
}
