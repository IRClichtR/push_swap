/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:31:09 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/10 10:31:23 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_if_null(char *res, char *temp)
{
	free(res);
	res = NULL;
	free(temp);
	temp = NULL;
}

static char	*push_ends(t_pile *a, t_pile *b, int *sorted_tab, int size)
{
	char	*res;
	char	*temp;

	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	temp = pb_beg(a, b, sorted_tab, size);
	if (temp == NULL)
		return (free(res), NULL);
	res = join_f(res, temp);
	if (res == NULL)
		return (free_if_null(res, temp), NULL);
	free(temp);
	temp = pb_end(a, b, sorted_tab, size);
	if (temp == NULL)
		return (free(res), NULL);
	res = join_f(res, temp);
	if (res == NULL)
		return (free_if_null(res, temp), NULL);
	free(temp);
	return (res);
}

static char	*push_mid(t_pile *a, t_pile *b, int *sorted_tab, int size)
{
	char	*res;
	char	*temp;

	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	temp = pb_mid1(a, b, sorted_tab, size);
	if (temp == NULL)
		return (free(res), NULL);
	res = join_f(res, temp);
	if (res == NULL)
		return (free_if_null(res, temp), NULL);
	free(temp);
	temp = pb_mid2(a, b, sorted_tab, size);
	if (temp == NULL)
		return (free(res), NULL);
	res = join_f(res, temp);
	if (res == NULL)
		return (free_if_null(res, temp), NULL);
	free(temp);
	return (res);
}

char		*push_to_b(t_pile *a, t_pile *b, int *sorted_tab, int size)
{
	char	*res;
	char	*temp;

	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	temp = push_ends(a, b, sorted_tab, size);
	if (temp == NULL)
		return (free(res), NULL);
	res = join_f(res, temp);
	if (res == NULL)
		return (free_if_null(res, temp), NULL);
	free(temp);
	temp = push_mid(a, b, sorted_tab, size);
	if (temp == NULL)
		return (free(res), NULL);
	res = join_f(res, temp);
	if (res == NULL)
		return (free_if_null(res, temp), NULL);
	free(temp);
	return (res);
}
