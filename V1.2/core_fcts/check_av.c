/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:20:25 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/24 10:29:24 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_av1(char *av1)
{
	if (check_num(av1) == -1)
		return (-1);
	return (1);
}

static int	check_arg_list(char *arg)
{
	if (ft_strlen(arg) > 10 || check_num(arg) == -1)
		return (-1);
	return (1);
}

static int	check_dif(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[j] != NULL)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int			check_args(int ac, char **av)
{
	int	i;

	if (ac < 2)
		return (-1);
	i = 0;
	if (ac == 2)
		if (check_av1(av[1]) == -1)
			return (-1);
	else
		if (check_arg_list(av) == -1)
			return (-1);
	if (check_dif(av) == -1)
		return (-1);
	return (1);
}
