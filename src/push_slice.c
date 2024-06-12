/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:17:14 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/26 15:15:50 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Checks if element from stack 'from' at 'index_from' (from[index_from])
	will fit in order in stack 'to' at 'index_to' (to[index_to]).	*/
int	fits_in(t_stack *from, t_stack *to, int index_from, int index_to)
{
	if (pos(from, index_from) > pos(to, index_to))
		return (0);
	if (pos(to, index_to - 1) == from->size + to->size || \
		pos(from, index_from) > pos(to, index_to - 1))
		return (1);
	return (0);
}

/*	Will find the first cheapest item from b that can be pushed to a.
	if |i| > x	:	NOT POSSIBLE
	if |i| == x	: 	+i: a[-i..0]	-i:	a[0..i]
	if |i| < x	: 	+i:	a[i-x] & a[x]	-i:	a[i+x] & a[-x]
*/
int	set_cheapest(t_stack *a, t_stack *b, int *indices, int moves)
{
	t_index	index;

	index.b = (-moves) - 1;
	while (++index.b <= moves)
	{
		if (ft_abs(index.b) == moves)
		{
			index.a = 0;
			while (ft_abs(index.a) <= ft_abs(index.b))
			{
				if (fits_in(b, a, index.b, index.a))
					return (set_indices(indices, index.a, index.b));
				index.a += moves / index.b;
			}
		}
		if (index.b >= 0 && fits_in(b, a, index.b, index.b - moves))
			return (set_indices(indices, index.b - moves, index.b));
		if (index.b >= 0 && fits_in(b, a, index.b, moves))
			return (set_indices(indices, moves, index.b));
		if (index.b < 0 && fits_in(b, a, index.b, index.b + moves))
			return (set_indices(indices, index.b + moves, index.b));
		if (index.b < 0 && fits_in(b, a, index.b, -moves))
			return (set_indices(indices, -moves, index.b));
	}
	return (0);
}

/*	Push element from B to A, ensuring it's the cheapest possible option. */
void	push_cheapest(t_heads *stacks, t_stack *a, t_stack *b)
{
	int	indices[2];
	int	moves;

	indices[0] = 0;
	indices[1] = 0;
	moves = 1;
	if (!fits_in(b, a, 0, 0))
	{
		while (!set_cheapest(a, b, indices, moves))
			moves++;
		run_instructions(stacks, indices);
	}
	push_a(stacks);
}

/*	Will push all elements in the smallest portion (SLICE) of A to B.
	Will rotate elements that are in the lower half of the portion to
	the back of stack B. */
void	push_lower_slice(t_heads *stacks, t_stack *a, t_stack *b)
{
	size_t	max;
	size_t	pivot;

	max = b->size + a->size / SLICE;
	pivot = b->size + max / 2;
	while (b->size < max)
	{
		if (a->size == 3)
			return ;
		while (a->start->pos > max)
			rotate_a(stacks);
		push_b(stacks);
		if (b->start->pos <= pivot)
		{
			if (b->size < max && a->start->pos > max)
				rotate_ab(stacks);
			else
				rotate_b(stacks);
		}
	}
}

/*	1)	Smallest 3rd of stack A is continuously pushed to B
		until only 3 largest elements remain.
	2)	3 elements in A are sorted.
	3)	All elements from B are returned to A, pushing the element
		from B that costs the least to correctly place in A.
	4)	Rotate stack A until the top element in the smallest.	*/
void	push_slice(t_heads *stacks)
{
	while (stacks->a->size > 3)
		push_lower_slice(stacks, stacks->a, stacks->b);
	sort_a(stacks, stacks->a);
	while (stacks->b->size > 0)
		push_cheapest(stacks, stacks->a, stacks->b);
	while (stacks->a->start->pos != 1)
		rev_rotate_a(stacks);
}
