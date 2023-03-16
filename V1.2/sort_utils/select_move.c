#include "sort_utils.h"

char	*select_move(t_pile *src, int idx)
{
	char	*move;

	if (idx > src->size / 2)
		move = "rev";
	else
		move = "rot";
	return (move);
}
