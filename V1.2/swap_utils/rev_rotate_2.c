#include "swap_utils.h"

void	rev_rotate_2(t_pile *a, t_pile *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	rev_rotate(a);
	rev_rotate(b);
}
