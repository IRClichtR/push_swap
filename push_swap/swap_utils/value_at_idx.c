/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_at_idx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:31:31 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/09 15:31:34 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

int	value_at_idx(t_pile *src, int idx)
{
	int	value;

	value = src->pile[0][idx];
	return (value);
}