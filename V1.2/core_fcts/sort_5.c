/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:32:57 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/27 17:38:22 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//DEBUG__________________________
void	print_pile(t_pile *a, t_pile *b)
{
	int i;
	int	size;
	i = 0;
	if (a->size > b->size)
		size = a->size;
	else 
		size = b->size;
printf("   A  B\n");
printf("   _  _\n");
	while (i < size)
	{
		printf("[%d]%d  %d\n", i, a->pile[0][i], b->pile[0][i]);
		i++;
	}
printf("   _  _\n");

}
//ENDOFDEBUG___________________________________
static void	put_in_order(t_pile *a)
{
	int	smallest;

	smallest = find_smallest(a);
	if (ft_strncmp(select_move(a, smallest), "rot", 3) == 0)
		loop_ra(a, smallest);
	else
		loop_rra(a, smallest);

}

void		sort_5(t_pile *a, t_pile *b)
{
	int	*o_tab;
	int	next;

	next = 0;
	while (a->size != 3)
		push(a, b, 'b');
	o_tab = save_pile(a);
	if (o_tab == NULL)
		return ;
	if (check_if_sorted(a->pile[0], a->size) == -1)
		sort_3(a, o_tab);
	while (b->size != 0)
	{
		next = find_next_idx(a, b->pile[0][0]);
		printf("IDX_A = %d PIL_B = %d\n", next, b->pile[0][0]);
		print_pile(a, b);
		do_best_push(a, b, next, 0);
	}
	put_in_order(a);
	free(o_tab);
}
