/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:57:55 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/16 17:37:44 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Rotates the entire stack by simply moving the start pointer over by one. */
int	rotate_stack(t_stack *stack)
{
	if (stack->start && stack->size > 1)
		stack->start = stack->start->next;
	return (1);
}

/*	Same as rotate_stack but in the opposite direction. */
int	rev_rotate_stack(t_stack *stack)
{
	if (stack->start && stack->size > 1)
		stack->start = stack->start->prev;
	return (1);
}

/*	Transfers the top node from stack 'from' to stack 'to'. */
int	push(t_stack *from, t_stack *to)
{
	t_num	*tmp;

	if (from->size == 0)
		return (0);
	tmp = from->start;
	stack_pop_top(from);
	stack_add_top(to, tmp);
	return (1);
}

/*	Switches the position of the first two nodes of given stack. */
int	swap_top_two(t_stack *stack)
{
	int		tmp_num;
	size_t	tmp_pos;

	if (stack->size < 2)
		return (0);
	tmp_num = stack->start->n;
	stack->start->n = stack->start->next->n;
	stack->start->next->n = tmp_num;
	tmp_pos = stack->start->pos;
	stack->start->pos = stack->start->next->pos;
	stack->start->next->pos = tmp_pos;
	return (1);
}
