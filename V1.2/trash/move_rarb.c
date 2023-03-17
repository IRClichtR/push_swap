/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rarb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:01:35 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/11 18:51:25 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

static char	*ra_or_rb(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*res;

	if (idx_a == 0)
		res = loop_rb(b, idx_b);
	else
		res = loop_ra(a, idx_a);
	return (res);
}

char		*move_rarb(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*temp;
	char	*temp2;
	int		save_a;
	int		save_b;

	save_a = value_at_idx(a, idx_a);
	save_b = value_at_idx(b, idx_b);
	temp = loop_rr(a, b, idx_a, idx_b);
	if (temp == NULL)
		return (NULL);
	if (idx_a == idx_b)
		return (temp);
	idx_a = save_a;
	idx_b = save_b;
	temp2 = ra_or_rb(a, b, idx_a, idx_b);
	if (temp2 == NULL)
		return (free(temp), NULL);
	return (ft_strjoin(temp, temp2));
}
