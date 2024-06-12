/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:24:14 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/15 15:48:04 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sorts for 7 elements or less
void	mini_sort(t_heads *stacks, t_stack *a, t_stack *b)
{
	if (stacks->total > 3)
	{
		while (a->size > 3)
		{
			while (a->start->pos > stacks->total - 3)
				rotate_a(stacks);
			push_b(stacks);
		}
	}
	sort_a(stacks, a);
	while (b->size != 0)
	{
		if (b->size == 2 && b->start->pos < b->start->next->pos)
			swap_b(stacks);
		if (b->size == 3)
			rev_sort_b(stacks, b);
		while (b->start->pos > a->start->pos)
			rotate_a(stacks);
		while (b->start->pos < a->start->prev->pos && \
				a->start->prev->pos != stacks->total)
			rev_rotate_a(stacks);
		push_a(stacks);
	}
	while (a->start->prev->pos != stacks->total)
		rev_rotate_a(stacks);
}

// Will sort stack a in 2 moves or less
void	sort_a(t_heads *stacks, t_stack *a)
{
	int		inv;
	t_num	*top;

	inv = count_inv(a);
	while (inv)
	{
		top = a->start;
		if (inv == 1)
			swap_a(stacks);
		else if (inv == 2 && top->pos < top->next->pos)
			rev_rotate_a(stacks);
		else if (inv == 2 && top->pos > top->next->pos)
			rotate_a(stacks);
		else if (inv == 3)
			rotate_a(stacks);
		inv = count_inv(stacks->a);
	}
}

// Will sort stack b in reverse order (largest to smallest) in 2 moves or less
void	rev_sort_b(t_heads *stacks, t_stack *b)
{
	int		inv;
	t_num	*top;

	inv = count_inv(b);
	while (inv != 3)
	{
		top = b->start;
		if (inv == 0)
			rotate_b(stacks);
		else if (inv == 1 && top->pos < top->next->pos)
			rotate_b(stacks);
		else if (inv == 1 && top->pos > top->next->pos)
			rev_rotate_b(stacks);
		else if (inv == 2 && top->pos < top->next->pos)
			swap_b(stacks);
		else if (inv == 2)
			rev_rotate_b(stacks);
		inv = count_inv(stacks->b);
	}
}
