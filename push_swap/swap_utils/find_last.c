/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:38:56 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/08 15:06:32 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

int	find_last_idx(t_pile *src)
{
	int	i;

	i = -1;
	if (src->size <= 1)
		return (0);
	while (++i < src->size)
		;
	return (i - 1);
}