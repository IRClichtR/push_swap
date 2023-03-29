/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_rrb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:15:25 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/11 16:20:51 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*join_rrb(char *str)
{
	char	*res;

	res = ft_strjoin(str, "rrb ");
	if (res == NULL)
		return (NULL);
	return (res);
}
