/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_slice_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:45:27 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/26 15:15:27 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (n * -1);
}

int	set_indices(int *indices, int index_a, int index_b)
{
	indices[0] = index_a;
	indices[1] = index_b;
	return (1);
}

/*	Executes instructions from indices where:
	indices[0] represents rotations needed for stack A
	indices[1] represents rotations needed for stack B	*/
void	run_instructions(t_heads *stacks, int *indices)
{
	while (indices[0] > 0 && indices[1] > 0)
	{
		indices[0] -= rotate_ab(stacks);
		indices[1]--;
	}
	while (indices[0] < 0 && indices[1] < 0)
	{
		indices[0] += rev_rotate_ab(stacks);
		indices[1]++;
	}
	while (indices[0])
	{
		if (indices[0] > 0)
			indices[0] -= rotate_a(stacks);
		if (indices[0] < 0)
			indices[0] += rev_rotate_a(stacks);
	}
	while (indices[1])
	{
		if (indices[1] > 0)
			indices[1] -= rotate_b(stacks);
		if (indices[1] < 0)
			indices[1] += rev_rotate_b(stacks);
	}
}
