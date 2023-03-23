/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:02:51 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/21 10:13:26 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

char	*join_f(char *s1, char *s2)
{
	char			*cat_str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	cat_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cat_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		cat_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		cat_str[i + j] = s2[j];
		j++;
	}
	cat_str[i + j] = '\0';
	free(s1);
	return (cat_str);
}
