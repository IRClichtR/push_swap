/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rrarb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:42:44 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/11 17:20:43 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*move_rrarb(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*res;
	char	*rra;
	char	*rb;

	rra = loop_rra(a, idx_a);
	if (rra == NULL)
		return (NULL);	
	rb = loop_rb(b, idx_b);
	if (rb == NULL)
		return (rra);
	res = ft_strjoin(rra, rb);
	free(rra);
	free(rb);
	return (res);
}
