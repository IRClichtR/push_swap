/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:16:42 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/11 16:16:52 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*join_rrr(char *str)
{
	char	*res;

	res = ft_strjoin(str, "rrr ");
	if (res == NULL)
		return (NULL);
	return (res);
}
