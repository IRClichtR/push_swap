/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:31:14 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/17 18:22:32 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILS_H
#define SORT_UTILS_H

#include "../core_fcts/push_swap.h"

int		calc_opti(t_pile *a, t_pile *b, int elt_b);
int		check_if_push_comp(t_pile *a, int *sorted_tab, int chunk, int size);
int		check_if_sorted(int *tab, int size);
int		create_chunks(int *sorted_tab, int size, int elt);
char	*do_best_push(t_pile *a, t_pile *b, int idx_a, int idx_b);
int		find_bigger(int a, int b);
int		find_smaller(int a, int b);
char	*join_f(char *s1, char *s2);
char	*join_f2(char *s1, char *s2);
char	*opti_push(t_pile *a, t_pile *b, int idx_a, int idx_b);
char	*pb_beg(t_pile *a, t_pile *b, int *sorted_tab, int size);
char	*pb_end(t_pile *a, t_pile *b, int *sorted_tab, int size);
char	*pb_mid1(t_pile *a, t_pile *b, int *sorted_tab, int size);
char	*pb_mid2(t_pile *a, t_pile *b, int *sorted_tab, int size);
char    *program_move(t_pile *a, t_pile *b, int idx_a, int idx_b);
int		*save_pile(int **pile, int size);
int		save_size(t_pile *src);
int		select_idxb(t_pile *a, t_pile *b);
char	*select_move(t_pile *src, int idx);
int		*sort_pile(int **pile, int size);
#endif
