/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:10:55 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/11 16:17:41 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"
#include "string.h"

char	*join_sb(char *str)
{
	char	*res;

	res = ft_strjoin(str, "sb ");
	if (res == NULL)
		return (NULL);
	return (res);
}
/*
int main()
{
	char	*str;

	str = strdup("do I function right == ");
	printf("BEFORE = %s\n", str);
	char *res = join_sa(str);
	printf("BEFORE = %s\n", res);
	free(str);
	free(res);
	return (0);
}
*/
