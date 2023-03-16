/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:05:39 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/08 21:13:00 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char		*loop_rrr(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*res;
	int		biggest;
	int		size;

	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	if (is_bigger(idx_a, idx_b) == 1)
	{
		biggest = idx_a;
		size = a->size;
	}
	else
	{
		biggest = idx_b;
		size = b->size;
	}
	while (biggest != size)
	{
		rev_rotate_2(a, b);
		res = join_f(res, "rrr ");
		if (res == NULL)
			break ;
		biggest++;
	}
	return (res);
}
