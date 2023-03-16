/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:42:49 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/09 22:20:43 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_pile(t_pile *a, t_pile *b, int ac, char **av)
{
	int	i;

	a->pile = ft_calloc(1, sizeof(int *));
	b->pile = ft_calloc(1, sizeof(int *));
	a->size = ac - 1;
	a->pile[0] = ft_calloc(a->size, sizeof(int));
	b->pile[0] = ft_calloc(a->size, sizeof(int));
	if (!pile_a->pile || !pile_b->pile)
		return ;
	b->size = 0;
	i = 0;
	while (i < size)
	{
		a->pile[0][i] = ft_atoi(av[i + 1]);
		i++;
	}
}

static void	free_all(t_pile *a, t_pile *b, char *res)
{
	free(a->pile[0]);
	free(b->pile[0]);
	free(a->pile);
	free(b->pile);
	free(pile_a);
	free(pile_b);
	if (res != NULL)
	{
		free(res);
		res = NULL;
	}
}

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

void	check_res(char	*res)
{
	char	**check;
	int		i;

	check = ft_split(res, " ");
	while (check[i] != NULL)
	{
		printf("%s\n", check[i]);
		free(check[i]);
		i++;
	}
	printf("-------MOVE_NBR == %d-------\n", i);
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
//end of debug//

int			main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	char	*res;

	a = ft_calloc(1, sizeof(t_pile));
	b = ft_calloc(1, sizeof(t_pile));
	set_pile(a, b, av, ac);
	if (!a || !b || !a->pile || !b->pile || !a->pile[0] || !b->pile[0])
	{
		free_all(a, b, res);
		return (0);
	}
//Debug
check_alloc(a, b, av);
//end of debug//
	if (check_pile(a) == 1)
	{
		res = push_swap(pile_a, pile_b);
		if (!res)
			ft_putstr_fd("Error\n", 2);//verifier sortie erreur standard
	}
//Debug
check_res(res);
check_pushswap(a, b, ac);
//End of DEBUG//
	free_all(pile_a, pile_b, res);
	return (0);
}
