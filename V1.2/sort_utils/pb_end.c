#include "sort_utils.h"

void	pb_end(t_pile *a, t_pile *b, int *sorted_tab, int size)
{
	while (check_if_push_comp(a, sorted_tab, 4, size) == 1)
	{
		if (create_chunks(sorted_tab, size, a->pile[0][0]) == 4)
			push(a, b, 'b');
		else
			rotate(a, 'a');
	}
}
