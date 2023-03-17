/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:16:16 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/11 16:16:18 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*join_rr(char *str)
{
	char	*res;

	res = ft_strjoin(str, "rr ");
	if (res == NULL)
		return (NULL);
	return (res);
}
