/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:14:29 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/11 16:20:28 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*join_rra(char *str)
{
	char	*res;

	res = ft_strjoin(str, "rra ");
	if (res == NULL)
		return (NULL);
	return (res);
}
