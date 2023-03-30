/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:31:36 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/30 12:43:17 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

void	pb_end(t_pile *a, t_pile *b, int *sorted_tab, int size)
{
	int	idx;

	while (check_if_push_comp(a, sorted_tab, 3, size) == 3)
	{
		idx = select_idxa(a, sorted_tab, 3);
		if (ft_strncmp(select_move(a, idx), "rot", 3) == 0)
			loop_ra(a, idx);
		else
			loop_rra(a, idx);
		push(a, b, 'b');
	}
}
