/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:59:20 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/09 14:57:11 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*loop_rr(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*res;
	int		smallest;

	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	if (is_bigger(idx_a, idx_b) == 1)
		smallest = idx_b;
	else
		smallest = idx_a;
	while (smallest != 0)
	{
		rotate_2(a, b);
		res = join_f(res, "rr ");
		if (res == NULL)
			break ;
		smallest--;
	}
	return (res);
}
