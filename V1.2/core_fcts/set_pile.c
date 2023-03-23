#include "push_swap.h"

static int	check_av1(char	*av1)
{
	int	i;

	i = 0;
	while (av1[i])
	{
		if (ft_isdigit((int)av1[i] == 0 && av1[i] != ' ')
			return (-1);
		i++;
	}
	return (1);
}

static void	set_1av_a(t_pile *a, char* av)
{
	char	**args;
	int		i;

	args = ft_split(av, ' ');
	if (args == NULL)
		return ;
	a->size = 1;
	while (args[a->size] != NULL)
		a->size++;
	a->pile[0] = ft_calloc(args_size, sizeof(int));
	if (a->pile[0] == NULL)
		return ;
	while (args[i] != NULL)
	{
		a-pile[0][i] = ft_atoi(args[i]);
		i++;
	}
}

static void	set_a(t_pile *a, char ** av, int ac)
{
	int	i;

	a->size = ac - 1;
	a->pile[0] = ft_calloc(a->size, sizeof(int));
	if (!a->pile[0])
		return ;
	i = 0;
	while (av[i] != NULL)
	{
		a->pile[0][i] = av[i];
		i++;
	}
}

int	set_pile(t_pile *a, t_pile *b, int ac, char **av)
{
	a->pile = ft_calloc(1, sizeof(int *));
	b->pile = ft_calloc(1, sizeof(int *));
	if (!a->pile || !b->pile)
		return (-1) ;
	if (ac < 3 && av[1] != NULL)
	{
		if (check_av1 == 0)
			return (-1);
		set_1av_a(a, av[2]);
	}
	else
		set_a(a, av + 1, ac);
	b->pile[0] = ft_calloc(a->size, sizeof(int));
	if (!b->pile[0])
		return (-1);
	return (1);
}
