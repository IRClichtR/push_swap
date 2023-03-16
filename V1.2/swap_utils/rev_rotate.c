/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:24:26 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/09 18:21:30 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

void	rev_rotate(t_pile *pile)
{
	int	last;
	int	i;

	if (pile->size == 0)
		return ;
	last = find_last_idx(pile);
	i = last - 1;
	while (last != 0)
	{
		ft_swap(&pile->pile[0][last], &pile->pile[0][i]);
		i--;
		last--;
	}
}
/*
int	main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Oops\n");
		return (0);
	}
	t_pile *pile;
	int	i;

	pile = ft_calloc(1, sizeof(t_pile));
	pile->pile = ft_calloc(1, sizeof(int *));
	pile-> size = ac - 1;
	pile->pile[0] = ft_calloc(pile->size, sizeof(int));
	i = 0;
	printf("Pile before\n");
	while (i < pile->size)
	{
		pile->pile[0][i] = ft_atoi(av[i + 1]);
		printf("%d\n", pile->pile[0][i]);
		i++;
	}
	rev_rotate(pile);
	i = 0;
	printf("Pile after\n");
	while (i < pile->size)
	{
		printf("%d\n", pile->pile[0][i]);
		i++;
	}
	return (0);
}
*/
