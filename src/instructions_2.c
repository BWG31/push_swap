/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:19:18 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/26 13:33:12 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_heads *stacks)
{
	rotate_stack(stacks->a);
	ft_putendl_fd("ra", STDOUT_FILENO);
	return (1);
}

int	rotate_b(t_heads *stacks)
{
	rotate_stack(stacks->b);
	ft_putendl_fd("rb", STDOUT_FILENO);
	return (1);
}

int	rotate_ab(t_heads *stacks)
{
	rotate_stack(stacks->a);
	rotate_stack(stacks->b);
	ft_putendl_fd("rr", STDOUT_FILENO);
	return (1);
}
