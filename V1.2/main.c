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

static void	free_all(t_pile *a, t_pile *b)
{
	free(a->pile[0]);
	free(b->pile[0]);
	free(a->pile);
	free(b->pile);
	free(pile_a);
	free(pile_b);
}

static int	check_lim(char *arg)
{
	char	*first_digits;
	int		i;

	if (ft_strlen(arg) > 9 && ft_strlen(arg) < 12)
	{
		first_digits = ft_substr(arg, 0, 8);
		if (!first_digits)
			return (-1);
		if (ft_isdigit(arg[0]) != 1 && (arg[0] != '+' || arg[0] != '-')
		|| ft_atoi(first_digits) > 21474836)
			return (free(first_digits), -1);
		if (ft_strlen(arg) == 10)
		{
			if (
		}
		if (ft_strlen(arg) == 11)
			if (arg[0] != '-')
				return (free(first_digits), -1);
	}
	free(first_digits);
	return (1);
}

static int	check_argument(char *arg)
{
	int	i;

	if (ft_strlen(arg) > 10)
		return (-1);
	i = 0;
	while (arg[++i] != 0)
		if (ft_isdigit(arg[i] == 0)
			return (-1);
	if (ft_strlen(arg) > 9 && ft_isdigt(arg[0]) == 1 || check_lim(arg) == -1))
		return (-1);
	return (1);
}

static int	check_args(int ac, char **av)
{
	int	i;

	if (ac < 2)
		return (-1);
	i = 0;
	if (ac == 2)
		if (check_av1(av[1]) == -1)
			return (-1);
	while (av[i] != NULL)
	{
		if 
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;

	if (check_args(ac, av) == -1)
		return (0);
	a = ft_calloc(1, sizeof(t_pile));
	b = ft_calloc(1, sizeof(t_pile));
	if (!a || !b)
		return (0);
	int	set_pile(a, b, av, ac);
	if (check_pile(a) == 1)
		push_swap(pile_a, pile_b);
	free_all(a, b);
	return (0);
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
