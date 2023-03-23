/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:43:42 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/17 17:51:14 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_UTILS_H
# define SWAP_UTILS_H

#include "../core_fcts/push_swap.h"

int		find_idx(t_pile *src, int elt);
int		find_last_idx(t_pile *src);
int		find_next_idx(t_pile *pile, int elt);
int		find_previous_idx(t_pile *pile, int elt);
int		find_smallest(t_pile *pile);
void	ft_swap(int *a, int *b);
int		is_bigger(int a, int b);
char	loop_ra(t_pile *a, int idx);
char	loop_rb(t_pile *b, int idx);
char	loop_rr(t_pile *a, t_pile *b, int idx_a, int idx_b);
char	loop_rra(t_pile *a, int idx);
char	loop_rrb(t_pile *b, int idx);
char	loop_rrr(t_pile *a, t_pile *b, int idx_a, int idx_b);
void	push(t_pile *src, t_pile *dest, char dest_name);
void	rev_rotate(t_pile *pile, char pile_name);
void	rev_rotate_2(t_pile *a, t_pile *b);
void	rotate(t_pile *pile, char pile_name);
void	rotate_2(t_pile *a, t_pile *b);
void	swap_pile(t_pile *pile, char pile_name);
int		value_at_idx(t_pile *src, int idx);
#endif
