/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:42:49 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 15:55:47 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_fcts/push_swap.h"
/*Debug______________________

void	print_piles(t_pile *a, t_pile *b)
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
//end of edbug ___________________*/
int			main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	int		set;

	if (ac < 2)
		return (0);
	if (check_av(ac, av) == -1)
	{
		ft_putstr_fd("Error 1\n", 2);
		return (0);
	}
	a = ft_calloc(1, sizeof(t_pile));
	b = ft_calloc(1, sizeof(t_pile));
	if (!a || !b)
		return (0);
	set = set_pile(a, b, ac, av);
	if (set == -1)
	{
		ft_putstr_fd("Error 2\n", 2);
		return (free_all(a, b), 0);
	}
	push_swap(a, b);
	free_all(a, b);
	return (0);
}
