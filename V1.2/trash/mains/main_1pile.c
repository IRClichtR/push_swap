int	main(int ac, char ** av)
{
	if (ac < 3)
		return (0);
	t_pile *a;
	a = ft_calloc(1, sizeof(t_pile));
	a->size = ac - 2;
	a->pile = ft_calloc(1, sizeof(int *));
	a->pile[0] = ft_calloc(a->size, sizeof(int));
	int	i = 0;
		printf("SIZE = %d\n", a->size);
printf("BEFORE OPERATION\n");
	while (i < a->size)
	{
		a->pile[0][i] = ft_atoi(av[i + 2]);
		printf("[%d] %d\n", i, a->pile[0][i]);
		i++;
	}
	i = 0;
	int idx = ft_atoi(av[1]);
	char *res = loop_rra(a, idx);
	printf("RES  = %s\n", res);
		printf("SIZE = %d\n", a->size);
printf("AFTER OPERATION\n");
	while (i < a->size)
	{
		printf("[%d] %d\n", i, a->pile[0][i]);
		i++;
	}
	free(a->pile[0]);
	free(a->pile);
	free(a);
	free(res);
	return (0);
}
