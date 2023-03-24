/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:42:49 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/24 18:21:03 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_fcts/push_swap.h"

void	free_all(t_pile *a, t_pile *b)
{
	if (a->pile[0])
	{
		free(a->pile[0]);
		a->pile[0] = NULL;
	}
	if (b->pile[0])
	{
		free(b->pile[0]);
		b->pile[0] = NULL;
	}
	if (a->pile)
	{
		free(a->pile);
		a->pile = NULL;	
	}
	if (b->pile)
	{
		free(b->pile);
		b->pile = NULL;
	}
	free(a);
	a = NULL;
	free(b);
	b = NULL;
}

int			main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	int		set;

	if (check_av(ac, av) == -1)
		return (0);
	a = ft_calloc(1, sizeof(t_pile));
	b = ft_calloc(1, sizeof(t_pile));
	if (!a || !b)
		return (0);
	set = set_pile(a, b, ac, av);
	if (set == -1)
		return (free_all(a, b), 0);
	push_swap(a, b);
	free_all(a, b);
	return (0);
}
/*












//Debug
void	check_alloc(t_pile *a, t_pile *b, char **av)
{
int i = 0;
	printf("DEBUG ALLOCATION\nSIZE_A == %d SIZE_B == %d\n", a->size, b->size);
	ft_printf("A  B\n");
	ft_printf("_  _\n");
	while (i < a->size)
	{
		ft_printf("%d  %d\n", a->pile[0][i], b->pile[0][i]);
		i++;
	}
	ft_printf("_**_ \n\n");
}

void	check_pushswap(t_pile *a, t_pile *b, int ac)
{
	int j = 0;

	ft_printf("A  B\n_  _\n");
	while (j < ac - 1)
	{
		ft_printf("%d  %d\n", a->pile[0][j], b->pile[0][j]);
		j++;
	}
	ft_printf("_**_ \n\n");
	ft_printf("---- \n DEBUG PUSH_SWAP \n RES = %s\n");
}
//end of debug*/
