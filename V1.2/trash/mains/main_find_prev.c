/*
int	main(int ac, char **av)
{
	if (ac < 3)
		return (0);
	t_pile	*pile;
	pile = ft_calloc(1, sizeof(t_pile));
	pile->pile = ft_calloc(1, sizeof(int *));
	pile->pile[0] = ft_calloc(ac - 2, sizeof(int));
	int i = 0;
	pile->size = ac - 2;
	printf("TAB\n");
	while (i < ac - 2)
	{
		pile->pile[0][i] = atoi(av[i + 2]);
		printf("[%d] %d\n", i, pile->pile[0][i]);
		i++;
	}
	int elt = atoi(av[1]);
printf("ELT = %d\n", elt);
	int res = find_previous_idx(pile, elt);
	printf("RES = %d\n", res); 
	free(pile->pile[0]);
	free(pile->pile);
	free(pile);
	return (0);
}
*/