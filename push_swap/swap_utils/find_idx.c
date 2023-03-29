#include "swap_utils.h"

int	find_idx(t_pile *src, int elt)
{
	int	idx;

	idx = 0;
	while (idx < src->size)
	{
		if (elt == src->pile[0][idx])
			return (idx);
		idx++;
	}
	return (0);
}
