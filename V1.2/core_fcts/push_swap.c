/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:47:52 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/10 10:21:41 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_swap(t_pile *pile_a, t_pile *pile_b)
{
	char	*res;
	char	*go_away;
	char	*go_back;
	int		size;

	go_back = ft_calloc(1, sizeof(char));
	if (!go_back)
		return (NULL);
	size = pile_a->size;
	go_away = push_to_b(pile_a, pile_b, size);
	if (go_away == NULL)
		return (free(go_back), NULL);
	go_back = push_back(pile_a, pile_b, go_back);
	if (go_back == NULL)
		return (free(go_back), go_away);
	res = join_f(go_away, go_back);
	if (!res)
	{
		free(go_away);
		go_away = NULL;
		return (free(go_back), NULL);
	}
	return (free(go_back), res);
}
