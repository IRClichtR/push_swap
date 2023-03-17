/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:13:12 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/11 16:20:00 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

char	*join_rb(char *str)
{
	char	*res;

	res = ft_strjoin(str, "rb ");
	if (res == NULL)
		return (NULL);
	return (res);
}
