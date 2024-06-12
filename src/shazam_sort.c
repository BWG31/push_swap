/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shazam_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:49:51 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/26 15:05:54 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Will push all elements (except 3 largest) to stack b into ranges sepecified
	in the struct r. Will fill from the middle outwards. */
static void	seesaw_push(t_heads *stacks, t_range *r)
{
	while (stacks->a->size > 3)
	{
		while (!in_range(pos(stacks->a, 0), r->min, r->max) || \
				pos(stacks->a, 0) > r->ceiling)
			rotate_a(stacks);
		push_b(stacks);
		if (in_range(pos(stacks->b, 0), r->mid, r->max))
		{
			r->top_count++;
			update_range(r);
		}
		else
		{
			r->bot_count++;
			update_range(r);
			if (!in_range(pos(stacks->a, 0), r->min, r->max))
				rotate_ab(stacks);
			else
				rotate_b(stacks);
		}
	}
}

/*	Returns all elements from b back to a, placing them in the right position.
	Will leave the last 3 elements to be sorted (in inverse order) seperately
	before returning them. */
void	filter_back(t_heads *stacks, t_stack *a, t_stack *b)
{
	while (b->size != 0)
	{
		if (b->size == 3)
			rev_sort_b(stacks, b);
		else if (b->size > 3 && pos(b, 0) <= 3)
			rotate_b(stacks);
		if (b->size > 3 && \
			!in_range(pos(b, 0), pos(a, -1), pos(a, 0)) && \
			in_range(pos(b, 1), pos(a, -1), pos(a, 0)))
			swap_b(stacks);
		while (pos(b, 0) > pos(a, 0))
			rotate_a(stacks);
		while (pos(b, 0) < pos(a, -1) && \
				pos(a, -1) != stacks->total)
			rev_rotate_a(stacks);
		push_a(stacks);
	}
	while (pos(a, -1) != stacks->total)
		rev_rotate_a(stacks);
}

/*	Sorting algorithm core.
	For 7 or less numbers, mini_sort is called.
	For more than 7:
		1) All but 3 largest numbers in A are pushed to B
			in ranges for an approximate inverse sort.
		2) 3 largest numbers in A are sorted.
		3) All but smallest 3 numbers in B are returned to A in order.
		4) 3 Smallest numbers in B are sorted in inverse order.
		5) Remaining 3 numbers are pushed to A.
*/
void	shazam_sort(t_heads *stacks)
{
	t_range	*r;

	if (!count_inv(stacks->a))
		clean_exit(stacks, NULL, EXIT_SUCCESS, NULL);
	if (stacks->total > 7)
	{
		r = set_range(stacks->total);
		if (!r)
			clean_exit(stacks, NULL, EXIT_FAILURE, "malloc error (set_range)");
		seesaw_push(stacks, r);
		sort_a(stacks, stacks->a);
		filter_back(stacks, stacks->a, stacks->b);
		free(r);
	}
	else
		mini_sort(stacks, stacks->a, stacks->b);
}
