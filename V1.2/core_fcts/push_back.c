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
	while (b->pile != 0)
	{
		idx_b = select_idxb(a, b);
		idx_a = find_next_idx(a, idx_b);
printf("SIZE_B = [%d] IDX_A = %d IDX_B = %d\n", b->size, idx_a, idx_b);
		res = join_f(res, do_best_push(a, b, idx_a, idx_b));
		if (res == NULL)
			return (free(res), NULL);
printf("RES = %s\n", res);
		//debug
		print_piles(a, b);
		//endof debug//
	}
	return (res);
}

char	*push_back(t_pile *a, t_pile *b)
{
	char	*res;

	res = loop_push(a, b);
	if (res == NULL)
		return (NULL);
	return (res);
}
int main (int ac, char **av)
{
	if (ac < 1)
		return (0);
	int size = ac - 1;
	t_pile *a;
	t_pile *b;
	a = ft_calloc(1, sizeof(t_pile));
	b = ft_calloc(1, sizeof(t_pile));
	a->size = 0;
	b->size = size;
printf("SIZE_A = %d\n", a->size);
printf("SIZE_B = %d\n", b->size);
	a->pile = ft_calloc(1, sizeof(int *));
	b->pile = ft_calloc(1, sizeof(int *));
	a->pile[0] = ft_calloc(size, sizeof(int));
	b->pile[0] = ft_calloc(size, sizeof(int));
	int	i = 0;

printf("BEFORE OPERATION\n");
printf("     A          B\n");
printf("     _          _\n");

	while (i < size)
	{
		b->pile[0][i] = ft_atoi(av[i + 1]);
		printf("[%d] %d    %d\n", i, a->pile[0][i], b->pile[0][i]);
		i++;
	}

char *res;
res = push_back(a, b);
	printf("RES  = %s\n", res);

printf("AFTER OPERATION\n");
printf("SIZE_A = %d\n", a->size);
printf("SIZE_B = %d\n", b->size);
	i = 0;
printf("     A  B\n");
printf("     _  _\n");
	while (i < size)
	{
		printf("[%d] %d  %d\n", i, a->pile[0][i], b->pile[0][i]);
		i++;
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
