#include "swap_utils.h"

int	find_next_idx(t_pile *pile, int elt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
//printf("FIND_NEXT LOOP == ");
	while (i < pile->size)
	{
//printf("%d ", j);
		if (pile->pile[0][i] > elt)
		{
			if (pile->pile[0][j] > pile->pile[0][i])
				j = i;
		}
		i++;
	}
//printf("\n");
printf("in FIND NEXT IDX RETURN VALUE == %d\n", j);
	return (j);
}
