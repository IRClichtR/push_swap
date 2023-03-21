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

char	*loop_r_or_rev(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*res;
	char	*temp;

	if (ft_strncmp(select_move(a, idx_a), "rot", 3) == 0)
		res = loop_ra(a, idx_a);
	else if (ft_strncmp(select_move(a, idx_a), "rev", 3) == 0)
		res = loop_rra(a, idx_a);
	else
		res = "";
	if (!res)
		return (NULL);
	if (ft_strncmp(select_move(b, idx_b), "rot", 3) == 0)
		res = loop_rb(b, idx_b);
	else if (ft_strncmp(select_move(b, idx_b), "rev", 3) == 0)
		res = loop_rrb(b, idx_b);
	if (res == NULL)
		return (free(res), NULL);
	push(b, a);
	temp = res;
	//res = ft_strjoin(temp, "pb ");
	if (res == NULL)
		return (free(res), NULL);
	return (/*free(temp), */res);
}

static char	*only_push(t_pile *a, t_pile *b)
{
	push(b, a);
	return ("pb ");
}

char	*loop_rr_or_rrr(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*res;

	if (check_push_case(a, b, idx_a, idx_b) == 1)
		res = loop_rr(a, b, idx_a, idx_b);
	else if (check_push_case(a, b, idx_a, idx_b) == 2)
		res = loop_rrr(a, b, idx_a, idx_b);
	else
	{
		return ("");
	}
	return (res);
}

static char	*mod_strdup(char *s)
{
	size_t	i;
	char	*copy;

	i = 0;
	copy = malloc(sizeof (char) * ft_strlen(s) + 1);
	if (copy == NULL)
	{
		free(copy);
		return (NULL);
	}
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}	
	copy[i] = '\0';
	free(s);
	return (copy);
}


char		*do_best_push(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*res;
	//char	*loop_rr;
	char	*loop_rrev;
	int		push_case;
	int		save_a;
	int		save_b;

	save_a = value_at_idx(a, idx_a);
	save_b = value_at_idx(b, idx_b);
	push_case = check_push_case(a, b, idx_a, idx_b);
		//return (NULL);
	if (idx_a == 0 && idx_b == 0 && b->size != 0)
		return (only_push(a, b));
printf("PUSH_CASE ++ %d\n", push_case);
	if (push_case == 1 || push_case == 2)
	//	loop_rr = loop_rr_or_rrr(a, b, idx_a, idx_b);
		res = mod_strdup(loop_rr_or_rrr(a, b, idx_a, idx_b));
	else
		res = ft_calloc(1, sizeof(char));
printf("LEN DE RES == %ld\n", ft_strlen(/*loop_rr*/res));
printf("RES AFTTER LOOP_RR == %s\n", res);
	//if (!res)
	//	return (NULL);
	idx_a = find_idx(a, save_a);
	idx_b = find_idx(b, save_b);
	loop_rrev = loop_r_or_rev(a, b, idx_a, idx_b);
printf("LEN DE RES == %ld\n", ft_strlen(loop_rrev));
printf("RES AFTTER LOOP_R_O_REV == %s\n", loop_rrev);
	res = join_f(res, loop_rrev);
printf("LEN DE RES == %ld\n", ft_strlen(res));
printf("RES AFTTER LOOP_R_O_REV == %s\n", res);
	if (res == NULL)
		return (free(res), NULL);
	return (res);
}

/*
static char	*final_push(t_pile *a, t_pile *b, int save_a, int save_b)
{
	int		idx_a;
	int		idx_b;
	char	*res;

	idx_a = find_idx(a, save_a);
	idx_b = find_idx(b, save_b);
	res = loop_r_or_rev(a, b, idx_a, idx_b);
	if (res == NULL)
		return (NULL);
	return (res);
}

char		*do_best_push(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	char	*res;
	char	*loop_rr;
	char	*loop_rrev;
	int		save_a;
	int		save_b;

	save_a = value_at_idx(a, idx_a);
	save_b = value_at_idx(b, idx_b);
	if (idx_a == 0 && idx_b == 0 && b->size != 0)
		return (only_push(a, b));
	if (check_push_case(a, b, idx_a, idx_b) == 1 
	|| check_push_case(a, b, idx_a, idx_b) == 2)
		loop_rr = loop_rr_or_rrr(a, b, idx_a, idx_b);
	if (loop_rr == NULL)
		return (NULL);
	if (ft_strncmp(loop_rr, "", 1) == 0)
	{
		loop_rr = ft_calloc(1, sizeof(char));
		if (loop_rr == NULL)
			return (NULL);
	}
	loop_rrev = final_push(a, b, save_a, save_b);
	if (loop_rrev == NULL)
		return (free(loop_rr), NULL);
	res = ft_strjoin(loop_rr, loop_rrev);
	if (res == NULL)
	{
		free(loop_rr);
		free(loop_rrev);
		return (NULL);
	}
	free(loop_rr);
	free(loop_rrev);
	return (res);
}
*/


int	size_pile(char **av, int ac, char pile_name)
{
	int	i;
	int	j;

	i = 1;
	while (ft_strncmp(av[i], "_", 1) != 0)
		i++;
	printf("AV = %s\n", av[i]);
	if (pile_name == 'a')
		return (i - 1);
	i += 1;
	j = 0;
	while (i < ac - 1)
	{
		i++;
		j++;
	}
	return (j + 1);
}


int main (int ac, char **av)
{
	if (ac < 2)
		return (0);
	t_pile *a;
	t_pile *b;
	a = ft_calloc(1, sizeof(t_pile));
	b = ft_calloc(1, sizeof(t_pile));
	a->size = size_pile(av, ac, 'a');
	b->size = size_pile(av, ac, 'b');
printf("SIZE_A = %d\n", a->size);
printf("SIZE_B = %d\n", b->size);
	a->pile = ft_calloc(1, sizeof(int *));
	b->pile = ft_calloc(1, sizeof(int *));
	a->pile[0] = ft_calloc(b->size + a->size, sizeof(int));
	b->pile[0] = ft_calloc(b->size + a-> size, sizeof(int));
	int	i = 0;

printf("BEFORE OPERATION\n");
printf("A\n");
printf("_\n");

	while (i < a->size)
	{
		a->pile[0][i] = ft_atoi(av[i + 1]);
		printf("[%d] %d\n", i, a->pile[0][i]);
		i++;
	}
	int j = 0;
	i += 1;
printf("B\n");
printf("_\n");
	while (i < ac - 1)
	{
		b->pile[0][j] = ft_atoi(av[i + 1]);
		printf("[%d] %d\n", j, b->pile[0][j]);
		i++;
		j++;
	}

	char *res1 = do_best_push(a, b, 0, 5);
	printf("RES  = %s\n", res1);
/*	char *res2 = do_best_push(a, b, 4, 1);
	printf("RES  = %s\n", res2);
	char *res3 = do_best_push(a, b, 2, 3);
	printf("RES  = %s\n", res3);
*/
printf("AFTER OPERATION\n");
printf("SIZE_A = %d\n", a->size);
printf("SIZE_B = %d\n", b->size);
	i = 0;
printf("A\n");
printf("_\n");
	while (i < a->size)
	{
		printf("[%d] %d\n", i, a->pile[0][i]);
		i++;
	}
	j = 0;
printf("B\n");
printf("_\n");
	while (j < b->size)
	{
		printf("[%d] %d\n", j, b->pile[0][j]);
		j++;
	}

	free(a->pile[0]);
	free(b->pile[0]);
	free(a->pile);
	free(b->pile);
	free(a);
	free(b);
	if (ft_strncmp(res1, "", 2) != 0)
		free(res1);
	res1 = NULL;
	/*if (ft_strncmp(res2, "", 2) != 0)
		free(res2);
	res2 = NULL;
	if (ft_strncmp(res3, "", 2) != 0)
		free(res3);
	res3 = NULL;
*/
	return (0);
}
