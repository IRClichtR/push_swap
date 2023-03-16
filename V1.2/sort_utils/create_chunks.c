/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:59:02 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/08 13:09:47 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

int	create_chunks(int *sorted_tab, int size, int elt)
{
	int	i;

	i = -1;
	while (++i < size / 4)
		if (elt == sorted_tab[i])
			return (1);
	i -= 1; 
	while (++i < size / 2)
		if (elt == sorted_tab[i])
			return (2);
	i -= 1; 
	while (++i < size * 3 / 4)
		if (elt == sorted_tab[i])
			return (3);
	i -= 1; 
	while (++i < size)
		if (elt == sorted_tab[i])
			return (4);
	return (0);
}
