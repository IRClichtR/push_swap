/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:37:03 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/05 14:00:56 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_neg_lim(char *arg)
{
	char	*first_digits;

	while (*(arg + 1) == 48)
		arg++;
	if (ft_strlen(arg) > 11)
		return (-1);
	if (ft_strlen(arg) < 11)
		return (1);
	arg += 1;
	first_digits = ft_substr(arg, 0, 8);
	if (ft_atoi(first_digits) > 21474836)
		return (free(first_digits), -1);
	if (ft_strncmp(first_digits, "21474836", 8) == 0)
	{
		if (ft_atoi(arg + 8) > 48)
			return (free(first_digits), -1);
	}
	free(first_digits);
	return (1);
}

static int	check_pos_lim(char *arg)
{
	char	*first_digits;

	if (arg[0] == '+')
	{
		if (ft_strlen(arg) < 11)
			return (1);
		else
			arg += 1;
	}
	else if (ft_strlen(arg) < 10)
		return (1);
	while (*arg == 48)
		arg++;
	if (ft_strlen(arg) > 10)
		return (-1);
	first_digits = ft_substr(arg, 0, 8);
	if (ft_atoi(first_digits) > 21474836)
		return (free(first_digits), -1);
	if (ft_strncmp(first_digits, "21474836", 8) == 0)
		if (ft_atoi(arg + 8) > 47)
			return (free(first_digits), -1);
	return (free(first_digits), 1);
}

static int	check_if_number(char *arg)
{
	int	i;

	i = 0;
	if (ft_strncmp(arg, "-", 2) == 0 || ft_strncmp(arg, "+", 2) == 0)
		return (-1);
	if (arg[i] == '-' || arg[i] == '+')
		i += 1;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) != 1)
			return (-1);
		i++;
	}
	return (1);
}

int	check_num(char *arg)
{
	int		i;
	char	**arg_chain;

	arg_chain = ft_split(arg, ' ');
	if (arg_chain == NULL)
		return (-1);
	i = 0;
	while (arg_chain[i] != NULL)
	{
		if (check_if_number(arg_chain[i]) == -1)
			return (free_argv(arg_chain), -1);
		if (arg_chain[i][0] == '-')
		{
			if (check_neg_lim(arg_chain[i]) == -1)
				return (free_argv(arg_chain), -1);
		}
		else
			if (check_pos_lim(arg_chain[i]) == -1)
				return (free_argv(arg_chain), -1);
		i++;
	}
	free_argv(arg_chain);
	return (1);
}
