/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:33:23 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/10 13:33:25 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*find_way(t_pile *src, int elt)
{
	int	idx;

	idx = find_idx(src, elt);
	if (src->size - idx > src->size / 2)
		return ("rot");
	else
		return ("rev");
}
