#include "sort_utils.h"

void	pb_mid2(t_pile *a, t_pile *b, int *sorted_tab, int size)
{
	while (check_if_push_comp(a, sorted_tab, 3, size) == 1)
	{
		if (create_chunks(sorted_tab, size, a->pile[0][0]) == 3)
			push(a, b, 'b');
		else
			rotate(a, 'a');
	}
}
