#include "swap_utils.h"

void	swap_pile(t_pile *pile, char pile_name)
{
	if (pile->size < 2)
		return ;
	ft_swap(&pile->pile[0][0], &pile->pile[0][1]);
	if (pile_name == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}
