#include "sort_utils.h"

static int	check_push_case(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	int	push_case;
	char	*move_a;
	char	*move_b;

	move_a = select_move(a, idx_a);
	move_b = select_move(b, idx_b);
	if (ft_strncmp(move_a, "rot", 3) == 0
	&& ft_strncmp(move_b, "rot", 3) == 0)
		push_case = 1;
	else if (ft_strncmp(move_a, "rev", 3) == 0
	&& ft_strncmp(move_b, "rev", 3) == 0)
		push_case = 2;
	else if (ft_strncmp(move_a, "rot", 3) == 0 
	&& ft_strncmp(move_b, "rev", 3) == 0)
		push_case = 3;
	else if (ft_strncmp(move_a, "rev", 3) == 0 
	&& ft_strncmp(move_b, "rot", 3) == 0)
		push_case = 4;
	else
		push_case = 0;
	return (push_case);
}

char	*loop_rr_or_rrr(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	if (check_push_case(a, b, idx_a, idx_b) == 1)
		return (loop_rr(a, b, idx_a, idx_b));
	else if (check_push_case(a, b, idx_a, idx_b) == 2)
		return (loop_rrr(a, b, idx_a, idx_b));
	return (NULL);
}

char	*loop_r_or_rev(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*res;

	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	if (ft_strncmp(select_move(a, idx_a), "rot", 3) == 0)
		res = join_f (res, loop_ra(a, idx_a));
	else
		res = join_f(res, loop_rra(a, idx_a));
	if (res == NULL)
		return (free(res), NULL);
	if (ft_strncmp(select_move(b, idx_b), "rot", 3) == 0)
		res = join_f (res, loop_rb(b, idx_b));
	else
		res = join_f(res, loop_rrb(b, idx_b));
	if (res == NULL)
		return (free(res), NULL);
	push(b, a);
	res = join_f(res, "pb ");
	if (res == NULL)
		return (free(res), NULL);
	return (res);
}

static char	*only_push(t_pile *a, t_pile *b)
{
	push(b, a);
	return ("pb ");
}

char		*do_best_push(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*res;
	char	*temp;
	int		push_case;
	int		save_a;
	int		save_b;

	save_a = value_at_idx(a, idx_a);
	save_b = value_at_idx(b, idx_b);
	push_case = check_push_case(a, b, idx_a, idx_b);
	temp = ft_calloc(1, sizeof(char));
	if (idx_a == 0 && idx_b == 0 && b->size != 0)
		return (only_push(a, b));
	if (push_case == 1 || push_case == 2)
		temp = join_f(temp, loop_rr_or_rrr(a, b, idx_a, idx_b));
	if (temp == NULL)
		return (NULL);
	idx_a = find_idx(a, save_a);
	idx_b = find_idx(b, save_b);
	res = join_f(temp, loop_r_or_rev(a, b, idx_a, idx_b));
	if (res == NULL)
		return (free(temp), NULL);
	return (res);
}
