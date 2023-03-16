/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:29:51 by ftuernal          #+#    #+#             */
/*   Updated: 2023/02/28 12:29:54 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

int	*save_pile(int **pile, int size)
{
	int *o_pile;
	int	i;

	i = 0;
	o_pile = ft_calloc(size, sizeof(int));
	if (!o_pile)
		return (0);
	while (i < size)
	{
		o_pile[i] = pile[0][i];
		i++;
	}
	return (o_pile);
}
