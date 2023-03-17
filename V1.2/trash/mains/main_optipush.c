
//debug__________________________________________
int	size_pile(char **av, int ac, char pile_name)
{
	int	i;
	int	j;

	i = 3;
	while (ft_strncmp(av[i], "_", 1) != 0)
		i++;
	printf("AV = %s\n", av[i]);
	if (pile_name == 'a')
		return (i - 3);
	i += 1;
	j = 0;
	while (i < ac - 1)
	{
		i++;
		j++;
	}
	return (j + 1);
}

int main (int ac, char **av)
{
	if (ac < 4)
		return (0);
	t_pile *a;
	t_pile *b;
	a = ft_calloc(1, sizeof(t_pile));
	b = ft_calloc(1, sizeof(t_pile));
	a->size = size_pile(av, ac, 'a');
	b->size = size_pile(av, ac, 'b');
printf("SIZE_A = %d\n", a->size);
printf("SIZE_B = %d\n", b->size);
	a->pile = ft_calloc(1, sizeof(int *));
	b->pile = ft_calloc(1, sizeof(int *));
	a->pile[0] = ft_calloc(a->size + 1, sizeof(int));
	b->pile[0] = ft_calloc(b->size, sizeof(int));
	int	i = 0;

printf("BEFORE OPERATION\n");
printf("A\n");
printf("_\n");
	while (i < a->size)
	{
		a->pile[0][i] = ft_atoi(av[i + 3]);
		printf("[%d] %d\n", i, a->pile[0][i]);
		i++;
	}
	int j = 0;
	i += 1;
printf("B\n");
printf("_\n");
	while (i < ac - 3)
	{
		b->pile[0][j] = ft_atoi(av[i + 3]);
		printf("[%d] %d\n", j, b->pile[0][j]);
		i++;
		j++;
	}

int idx_a = ft_atoi(av[1]);
int idx_b = ft_atoi(av[2]);

	char *res = opti_push(a, b, idx_a, idx_b);
	printf("RES  = %s\n", res);

printf("AFTER OPERATION\n");
printf("SIZE_A = %d\n", a->size);
printf("SIZE_B = %d\n", b->size);
	i = 0;
printf("A\n");
printf("_\n");
	while (i < a->size)
	{
		printf("[%d] %d\n", i, a->pile[0][i]);
		i++;
	}
	j = 0;
printf("B\n");
printf("_\n");
	while (j < b->size)
	{
		printf("[%d] %d\n", j, b->pile[0][j]);
		j++;
	}
	free(a->pile[0]);
	free(b->pile[0]);
	free(a->pile);
	free(b->pile);
	free(a);
	free(b);
	free(res);
	return (0);
}

