/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:17 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/11 16:19:31 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*join_ss(char *str)
{
	char	*res;

	res = ft_strjoin(str, "ss ");
	if (res == NULL)
		return (NULL);
	return (res);
}
