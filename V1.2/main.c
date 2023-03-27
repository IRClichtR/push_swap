/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:42:49 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/27 14:18:06 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_fcts/push_swap.h"
//Debug______________________

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
//end of edbug ___________________//
int			main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	int		set;
	char	*error;

	error = "Error\n";
	if (ac < 2)
		return (0);
	if (check_av(ac, av) == -1)
	{
		ft_putstr_fd(error, 2);
		return (0);
	}
	a = ft_calloc(1, sizeof(t_pile));
	b = ft_calloc(1, sizeof(t_pile));
	if (!a || !b)
		return (0);
	set = set_pile(a, b, ac, av);
printf("I go there\n");

	if (set == -1)
	{
		ft_putstr_fd(error, 2);
		return (free_all(a, b), 0);
	}
// Debug
printf("___BEFORE___\n\n");
print_piles(a, b);
//End of Debug//
	push_swap(a, b);
// Debug
printf("___AFTER___\n\n");
print_piles(a, b);
//End of Debug//
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
