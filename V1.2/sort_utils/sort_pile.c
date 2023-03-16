#include "sort_utils.h"

int	partition(int **pile, int low, int high)
{
	int	pivot_value;
	int	i;
	int	j;

	i = low;
	j = low;
	pivot_value = pile[0][high];//search_med(pile, low, high);
	while (j < high)
	{
		if (pile[0][j] <= pivot_value)
		{
			ft_swap(&pile[0][i], &pile[0][j]);
			i++;
		}
		j++;
	}
	ft_swap(&pile[0][i], &pile[0][j]);
	return (i);
}

static void	q_sort(int *pile, int beg, int end)
{
	int	pivot_index;

	if (beg < end)
	{
		pivot_index = partition(&pile, beg, end);
		q_sort(pile, beg, pivot_index - 1);
		q_sort(pile, pivot_index + 1, end);
	}
}

int	*sort_pile(int **pile, int size)
{
	int	beg;
	int	end;
	int	i;
	int	*o_pile;

	o_pile = ft_calloc(size, sizeof(int));
	if (!o_pile)
		return (0);
	i = 0;
	while (i < size)
	{
		o_pile[i] = pile[0][i];
		i++;
	}
	beg = 0;
	end = size - 1;
	q_sort(o_pile, beg, end);
	return (o_pile);
}

/*
int	main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("rien dans av !!");
		return (0);
	}
	int	**tab = ft_calloc(1, sizeof(int *));
	tab[0] = ft_calloc(ac - 1, sizeof(int));
	int	*sorted_tab = ft_calloc(ac - 1, sizeof(int));
	int i = 0;
	while (i < ac - 1)
	{
		tab[0][i] = ft_atoi(av[i + 1]);
		printf("tab[0][%d] = %d\n", i, tab[0][i]);
		i++;
	}
	i = 0;
	sorted_tab = sort_pile(tab, 6);
	while (i < 6)
	{
		printf("sorted_tab[i] = %d\n", sorted_tab[i]);
		i++;
	}
	free(tab);
	free(sorted_tab);
	return (0);
}
*/
/*
static int	med_idx(int **pile, int size)
{
	int	med;
	int	beg;
	int	end;
	int	i;

	beg = 0;
	end = size - 1;
	i = size / 2;
	med = search_med(pile, beg, end);
	while (beg < end)
	{
		if (med == pile[0][i])
			return (i);
		else if (med > i)
			end = med - 1;
		else
			beg = med + 1;
	}
	return (med);
}

static int	search_med(int **pile, int beg, int end)
{
	int	k;
	int	i;
	int	j;

	k = pile[0][beg];
	i = beg;
	j = end;
	while (i < j)
	{
		while (pile[0][i] <= k && i < end)
			i++;
		while (pile[0][j] > k)
			j--;
		if (i < j)
			ft_swap(&pile[0][i], &pile[0][j]);
	}
printf("valeur de la mediane = %d\n", pile[0][j]);
	return (pile[0][j]);
}
*/

