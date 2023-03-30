/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:42:49 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/30 12:54:53 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_piles(t_pile *a, t_pile *b)
{
	int	i = 0;
	int size;

	if (a->size > b->size)
		size = a->size;
	else
		size = b->size;

printf("A  B\n");
	while (i < size)
	{

		printf("%d  %d\n", a->pile[0][i], b->pile[0][i]);
		i++;	
	}
printf("_  _\n");
}

int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	int		set;

	if (check_av(ac, av) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	a = ft_calloc(1, sizeof(t_pile));
	b = ft_calloc(1, sizeof(t_pile));
	if (!a || !b)
		return (0);
	set = set_pile(a, b, ac, av);
	if (set == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (free_all(a, b), 0);
	}

printf("BEFORE\n");
print_piles(a, b);
	push_swap(a, b);
printf("AFTER\n");
print_piles(a, b);
	free_all(a, b);
	return (0);
}
