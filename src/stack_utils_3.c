/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:12:43 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/16 15:56:13 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Adds a given num node 'new' to the top of a given stack and links it
	to adjascent nodes. */
void	stack_add_top(t_stack *stack, t_num *new)
{
	if (!new)
		return ;
	if (stack->size > 0)
	{
		new->next = stack->start;
		new->prev = stack->start->prev;
		stack->start->prev->next = new;
		stack->start->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
	}
	stack->start = new;
	stack->size++;
}

/*	Removes the node pointed to by the stack start pointer from the stack. */
void	stack_pop_top(t_stack *stack)
{
	if (stack->size == 0)
		return ;
	if (stack->size == 1)
		stack->start = NULL;
	else
	{
		stack->start->next->prev = stack->start->prev;
		stack->start->prev->next = stack->start->next;
		stack->start = stack->start->next;
	}
	if (stack->size)
		stack->size--;
}

/*	Counts the number of inversions of all the numbers in a given stack. */
int	count_inv(t_stack *stack)
{
	t_num	*a;
	t_num	*b;
	size_t	count;
	size_t	x;
	size_t	y;

	count = 0;
	a = stack->start;
	x = 0;
	while (x < stack->size - 1)
	{
		b = a->next;
		y = x + 1;
		while (y < stack->size)
		{
			if (a->n > b->n)
				count++;
			b = b->next;
			y++;
		}
		a = a->next;
		x++;
	}
	return (count);
}

/*	Will traverse entire stack and set the variable 'pos' of each node to
	the position they should be in (from 1 to number of elements). Effectively
	indexing all the numbers in their sorted state. */
void	set_position_values(t_stack *stack)
{
	int		smallest;
	size_t	pos;
	size_t	rot;

	pos = 0;
	while (++pos < stack->size)
	{
		rot = 0;
		smallest = INT_MAX;
		while (rot++ < stack->size)
		{
			if (stack->start->n < smallest && stack->start->pos == pos)
				smallest = stack->start->n;
			rotate_stack(stack);
		}
		rot = 0;
		while (rot++ < stack->size)
		{
			if (stack->start->n > smallest)
				stack->start->pos++;
			rotate_stack(stack);
		}
	}
}
