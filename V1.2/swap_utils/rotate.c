/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:33:03 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/08 15:09:46 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

void	rotate(t_pile *pile)
{
	int	i;
	int	last;

	i = 0;
	last = find_last_idx(pile);
	while (i < last)
	{
		ft_swap(&pile->pile[0][i], &pile->pile[0][i + 1]);
		i++;
	}
}
/*
int main(int ac, char **av)
{
	t_pile *pile;
	pile = ft_calloc(1, sizeof(t_pile));
	pile->pile = ft_calloc(1, sizeof(int *));
	pile->size = ac - 1;
	pile->pile[0] = ft_calloc(pile->size, sizeof(int));

	int	i = 0;
	printf("BEFORE ROTATE\n");
	while (i < pile->size)
	{
		pile->pile[0][i] = ft_atoi(av[i + 1]);
		printf("%d\n", pile->pile[0][i]);
		i++;
	}
	rotate(pile);
	i = 0;
	printf("AFTER ROTATE\n");
	while (i < pile->size)
	{
		printf("%d\n", pile->pile[0][i]);
		i++;
	}
	free(pile->pile[0]);
	free(pile->pile);
	free(pile);
	return (0);
}
*/
