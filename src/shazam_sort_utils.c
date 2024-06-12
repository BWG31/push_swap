/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shazam_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:38:43 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/23 15:11:37 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Will return the pos (position) value of the number struct at index i
	in the given stack.
	Index 0 is the head. Index -1 is the tail. */
size_t	pos(t_stack *stack, int i)
{
	t_num	*num;

	num = stack->start;
	while (i)
	{
		if (i > 0)
		{
			num = num->next;
			i--;
		}
		else if (i < 0)
		{
			num = num->prev;
			i++;
		}
	}
	return (num->pos);
}

// Returns true if pos is within the range of min & max.
int	in_range(size_t pos, size_t min, size_t max)
{
	if (pos >= min && pos <= max)
		return (1);
	return (0);
}

/*	Allocates (with malloc) memory for the ranges (buckets) in which
	elements will be sorted in stack b. Values are adjusted depending 
	on the total number of elements for optimisation purposes. */
t_range	*set_range(size_t total)
{
	t_range	*r;

	r = malloc(sizeof(t_range));
	if (!r)
		return (NULL);
	r->ceiling = total - 3;
	r->mid = r->ceiling / 2 + 1;
	if (total < 50)
	{
		r->range = total / 7 + 1;
		r->mid = r->ceiling / 2;
		if (r->ceiling % 2)
			r->mid++;
	}
	else if (total <= 103)
		r->range = r->ceiling / 10 + 2;
	else
		r->range = r->ceiling / 20;
	r->max = r->mid + r->range - 1;
	r->min = r->mid - r->range;
	r->top_count = 0;
	r->bot_count = 0;
	return (r);
}

/*	Will update ranges (buckets) once one side has been filled. */
void	update_range(t_range *r)
{
	if (r->top_count == r->range || r->bot_count == r->range)
	{
		if (r->top_count == r->range)
		{
			r->max += r->range;
			if (r->max > r->ceiling)
				r->max = r->ceiling;
			r->top_count = 0;
		}
		else
		{
			if (r->min > r->range)
				r->min -= r->range;
			else
				r->min = 0;
			r->bot_count = 0;
		}
	}
}
