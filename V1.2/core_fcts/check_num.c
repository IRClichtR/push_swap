/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:37:03 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/24 17:50:19 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_neg_lim(char *arg)
{
	char	*first_digits;

	if(ft_strlen(arg) > 11)
		return (-1);
	if (ft_strlen(arg) < 11)
		return (1);
	arg += 1;
	first_digits = ft_substr(arg, 0, 8);
printf("FIRST DIGITS == %s\n", first_digits);
	if (ft_atoi(first_digits) > 21474836)
		return (free(first_digits), -1);
	if (ft_strncmp(first_digits, "21474836", 8) == 0)
	{
		if (ft_atoi(arg + 8) > 48)
			return (free(first_digits), -1);
	}
	return (1);
}

static int	check_pos_lim(char *arg)
{
	char	*first_digits;

	if (arg[0] == '+')
		if (ft_strlen(arg) < 11)
			return (1);
		else
			arg += 1;
	else if (ft_strlen(arg) < 10)
		return (1);
printf("CHECK LIM DEBUT == %s\n", arg);
	if (ft_strlen(arg) > 10)
		return (-1);
	first_digits = ft_substr(arg, 0, 8);
printf("FIRST DIGITS == %s\n", first_digits);
	if (ft_atoi(first_digits) > 21474836)
		return (free(first_digits), -1);
printf("DERNERS CHIFFRES == %d\n", ft_atoi(arg+8));
	if (ft_strncmp(first_digits, "21474836", 8) == 0)
		if (ft_atoi(arg + 8) > 47)
			return (free(first_digits), -1);
	return (free(first_digits), 1);
}

static int	check_if_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i += 1;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) != 1)
			return (-1);
		i++;
	}
printf("CHECK IF NUMBER == 1\n");
	return (1);
}

static int	skip_space(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == ' ' || arg[i] == '\t'
		|| arg[i] == '\n' || arg[i] == '\v'
		|| arg[i] == '\f' || arg[i] == '\r')
		i++;
	if (i == (int)ft_strlen(arg))
		return (-1);
	if (arg[i] == '-' || arg[i] == '+' || ft_isdigit(arg[i]) == 1)
		return (i);
	return (-1);
}

int	check_num(char *arg)
{
	int	i;

	if (skip_space(arg) == -1)
		return (-1);
	i = skip_space(arg);
	printf("SKIPSPACE == %d \n", i);
	if (check_if_number(&arg[i]) == -1)
		return (-1);
	if (arg[i] == '-')
	{
		if (check_neg_lim(arg) == -1)
			return (-1);
	}
	else
		if (check_pos_lim(arg) == -1)
			return (-1);
	return (1);
}
