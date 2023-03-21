#include "push_swap.h"

//debug function tobe suppressed
void print_piles(t_pile *a, t_pile *b)
{
int i = 0;
int	size;

if (a->size > b->size)
	size = a->size;
else
	size = b->size;
printf("     A  B\n");
printf("     _  _\n");
	while (i < size)
	{
		printf("[%d] %d  %d\n", i, a->pile[0][i], b->pile[0][i]);
		i++;
	}

printf("     _ _______________________________________ _\n");

}
//endof debug//

char	*loop_push(t_pile *a, t_pile *b)
{
	char	*res;
	int		idx_a;
	int		idx_b;

	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
//printf(" idx_b = %d next_idx == %d\n", select_idxb(a, b), find_next_idx(a, b->pile[0][idx_b]));
	while (b->size != 0)
	{
		idx_b = select_idxb(a, b);
		idx_a = find_next_idx(a, b->pile[0][idx_b]);
		res = join_f(res, do_best_push(a, b, idx_a, idx_b));
		if (res == NULL)
			break ;
//printf("RES = %s\n", res);
		//debug
		print_piles(a, b);
		//endof debug//
	}
	return (res);
}

char	*push_back(t_pile *a, t_pile *b)
{
	char	*res;
	int		smallest;

	res = loop_push(a, b);
	if (res == NULL)
		return (NULL);
	smallest = find_smallest(a);
	if (ft_strncmp(select_move(a, smallest), "rot", 3) == 0)
		res = join_f2(res, loop_ra(a, smallest));
	else
		res = join_f2(res, loop_rra(a, smallest));
	if (res == NULL)
		return (free(res), NULL);
	return (res);
}

//debug__________________________________________
int	size_pile(char **av, int ac, char pile_name)
{
	int	i;
	int	j;

	i = 1;
	while (ft_strncmp(av[i], "_", 1) != 0)
		i++;
	printf("AV = %s\n", av[i]);
	if (pile_name == 'a')
		return (i - 1);
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
	if (ac < 2)
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
	a->pile[0] = ft_calloc(b->size + a->size, sizeof(int));
	b->pile[0] = ft_calloc(b->size + a-> size, sizeof(int));
	int	i = 0;

printf("BEFORE OPERATION\n");
printf("A\n");
printf("_\n");

	while (i < a->size)
	{
		a->pile[0][i] = ft_atoi(av[i + 1]);
		printf("[%d] %d\n", i, a->pile[0][i]);
		i++;
	}
	int j = 0;
	i += 1;
printf("B\n");
printf("_\n");
	while (i < ac - 1)
	{
		b->pile[0][j] = ft_atoi(av[i + 1]);
		printf("[%d] %d\n", j, b->pile[0][j]);
		i++;
		j++;
	}

	char *res = push_back(a, b);
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
	if (ft_strncmp(res, "", 2) != 0)
		free(res);
	res = NULL;
	return (0);
}
