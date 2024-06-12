/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:28:42 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/26 13:33:39 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate_a(t_heads *stacks)
{
	rev_rotate_stack(stacks->a);
	ft_putendl_fd("rra", STDOUT_FILENO);
	return (1);
}

int	rev_rotate_b(t_heads *stacks)
{
	rev_rotate_stack(stacks->b);
	ft_putendl_fd("rrb", STDOUT_FILENO);
	return (1);
}

int	rev_rotate_ab(t_heads *stacks)
{
	rev_rotate_stack(stacks->a);
	rev_rotate_stack(stacks->b);
	ft_putendl_fd("rrr", STDOUT_FILENO);
	return (1);
}
