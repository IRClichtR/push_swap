//random main ne fonctionne que pour des valeurs en dessous de 50 environ

#include <time.h>
int	partition(int *pile, int low, int high)
{
	int	pivot_value;
	int	i;
	int	j;

	i = low;
	j = low;
	pivot_value = pile[high];
	while (j < high)
	{
		if (pile[j] <= pivot_value)
		{
			ft_swap(&pile[i], &pile[j]);
			i++;
		}
		j++;
	}
	ft_swap(&pile[i], &pile[j]);
	return (i);
}

static void	q_sort(int *pile, int beg, int end)
{
	int	pivot_index;

	if (beg < end)
	{
		pivot_index = partition(pile, beg, end);
		q_sort(pile, beg, pivot_index - 1);
		q_sort(pile, pivot_index + 1, end);
	}
}

int	*random_nbr(int lower, int upper, int count)
{
	int	i;
	int	*num;
	int j;

	num = ft_calloc(count, sizeof(int));
	i = 0;
	srand(time(NULL));
    for (i = 0; i < count; i++)
    {
        num[i] = (rand() % (upper - lower + 1)) + lower;
        for (j = 0; j < i; j++)
        {
            if (num[j] == num[i])
            {
                i--;
                continue;
            }
        }
    }
	return (num);
}
int	main(int ac, char **av)
{
	int *tab;
	int i = 0;
	int size = ft_atoi(av[3]);
	tab = random_nbr(atoi(av[1]), atoi(av[2]), size);
printf("SIZE == %d\n", size);

	int	*sorted_tab = ft_calloc(size, sizeof(int));

int	k = 0;
	while (k < size)
	{
		sorted_tab[k] = tab[k];
		k++;
	}

	q_sort(sorted_tab, 0, size -1);
	while (i < size)
	{
		printf("[%d] %d            SORTED = %d\n", i, tab[i], sorted_tab[i]);
		i++;
	}
	int j = 0;
	while (j < size)
	{
		printf("[%d] CHUNK == %d\n", j, create_chunks(sorted_tab, size, tab[j]));
		j++;
	}
	free(sorted_tab);
	free(tab);
	return (0);
}
