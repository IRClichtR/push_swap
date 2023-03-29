/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:12:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/11 16:17:05 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*join_ra(char *str)
{
	char	*res;

	res = ft_strjoin(str, "ra ");
	if (res == NULL)
		return (NULL);
	return (res);
}

