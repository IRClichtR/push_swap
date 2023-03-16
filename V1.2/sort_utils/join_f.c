/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:02:51 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/03 13:37:56 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

char	*join_f(char *s1, char *s2)
{
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	tmp = ft_strjoin(s1, s2);
	free(s1);
//	free(s2);
	return (tmp);
}
