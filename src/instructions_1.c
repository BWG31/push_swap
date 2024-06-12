/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:19:16 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/26 13:32:37 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_heads *stacks)
{
	swap_top_two(stacks->a);
	ft_putendl_fd("sa", STDOUT_FILENO);
	return (1);
}

int	swap_b(t_heads *stacks)
{
	swap_top_two(stacks->b);
	ft_putendl_fd("sb", STDOUT_FILENO);
	return (1);
}

int	swap_ab(t_heads *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
	ft_putendl_fd("ss", STDOUT_FILENO);
	return (1);
}

int	push_a(t_heads *stacks)
{
	push(stacks->b, stacks->a);
	ft_putendl_fd("pa", STDOUT_FILENO);
	return (1);
}

int	push_b(t_heads *stacks)
{
	push(stacks->a, stacks->b);
	ft_putendl_fd("pb", STDOUT_FILENO);
	return (1);
}
