/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:13:34 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/09 20:34:29 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

static void	put_zero(t_pile *dest)
{
	int	last;
	int	i;

	last = find_last_idx(dest);
	i = last + 1;
	while (i > 0)
	{
		ft_swap(&dest->pile[0][last], &dest->pile[0][i]);
		if (last == 0)
			break ;
		i--;
		last--;
	}
}

void		push(t_pile *src, t_pile *dest)
{
	if (src->size == 0)
		return ;
	put_zero(dest);
	ft_swap(&src->pile[0][0], &dest->pile[0][0]);
	if (src->size > 1)
		rotate(src);
	src->size -= 1;
	dest->size += 1;
}
