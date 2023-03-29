#include "swap_utils.h"

int	find_biggest(t_pile *pile)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = pile->pile[0][0];
	while (i < pile->size)
	{
		if (pile->pile[0][i] > biggest)
			biggest = pile->pile[0][i];
		i++;
	}
	return (biggest);
} 
