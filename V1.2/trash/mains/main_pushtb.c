
/*
int	main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("OOPS\n");
		return (0);
	}
	printf("SIZE OF MAIN ARGS = %d\n", ac - 1);
	printf("SIZE OF MAIN ARGS / 4 = %d\n", (ac - 1) / 4);
	t_pile	*pile_a;
	t_pile	*pile_b;
	int		*sorted_tab;

	
	pile_a = ft_calloc(1, sizeof(t_pile));
	pile_b = ft_calloc(1, sizeof(t_pile));
	pile_a->size = ac - 1;
	pile_b->size = 0;
	pile_a->pile = ft_calloc(1, sizeof(int *));
	pile_b->pile = ft_calloc(1, sizeof(int *));
	pile_a->pile[0] = ft_calloc(pile_a->size, sizeof(int));
	pile_b->pile[0] = ft_calloc(pile_a->size, sizeof(int));
	
	char *res;
	int	i = 0;
printf("BEFORE OPERATION\nA  B\n_  _\n");
	while (i < pile_a->size)
	{
		pile_a->pile[0][i] = ft_atoi(av[i + 1]);
		printf("%d  %d\n", pile_a->pile[0][i], pile_b->pile[0][i]);
		i++;
	}
	sorted_tab = sort_pile(pile_a->pile, pile_a->size);
	res = push_to_b(pile_a, pile_b, sorted_tab, ac - 1);
	
printf("RES = %s\n", res);
	i = 0;
printf("AFTER OPERATION\nA  B\n_  _\n");
	while (i < ac - 1)
	{
		printf("%d  %d\n", pile_a->pile[0][i], pile_b->pile[0][i]);
		i++;
	}
	free(pile_a->pile[0]);
	free(pile_b->pile[0]);
	free(pile_a->pile);
	free(pile_b->pile);
	free(pile_a);
	free(pile_b);
	free(res);
	free(sorted_tab);
	return (0);
}
*/