/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:58:16 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/16 16:01:40 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Will free all memory allocated for stack.
void	free_stack(t_stack *stack)
{
	t_num	*ptr;

	if (stack)
	{
		if (stack->start)
		{
			ptr = stack->start;
			while (stack->size--)
			{
				if (stack->size)
				{
					ptr = ptr->next;
					free(ptr->prev);
				}
				else
					free(ptr);
			}
		}
		free(stack);
	}
}

/*	Will free all memory allocated for a given array. */
int	free_array(char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
			free(array[i++]);
		free(array);
	}
	return (0);
}

/*	Will free any memory previously allocated for heads, stacks or arrays before
	exiting program with any corresponding exit code and/or error message. */
void	clean_exit(t_heads *stacks, char **array, int exit_code, char *err_msg)
{
	if (stacks)
	{
		if (stacks->a)
			free_stack(stacks->a);
		if (stacks->b)
			free_stack(stacks->b);
		free(stacks);
	}
	if (array)
		free_array(array);
	if (err_msg)
		ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(exit_code);
}
