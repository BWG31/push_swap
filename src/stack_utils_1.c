/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:48:29 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/16 15:57:29 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Initializes stacks a and b, as well as the head pointing to both stacks. */
t_heads	*init_stacks(void)
{
	t_heads	*stacks;

	stacks = malloc(sizeof(t_heads));
	if (!stacks)
		clean_exit(NULL, NULL, EXIT_FAILURE, "malloc error (init_stacks)");
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->total = 0;
	stacks->inversions = 0;
	stacks->a = new_stack(stacks);
	stacks->b = new_stack(stacks);
	return (stacks);
}

/*	Allocates memory for and initializes a new stack. */
t_stack	*new_stack(t_heads *stacks)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		clean_exit(stacks, NULL, EXIT_FAILURE, "malloc error (new_stack)");
	stack->size = 0;
	stack->start = NULL;
	return (stack);
}

/*	Allocates memory for and initializes a new num node. */
t_num	*new_num(int num)
{
	t_num	*new;

	new = malloc(sizeof(t_num));
	if (!new)
		return (NULL);
	new->n = num;
	new->pos = 1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

// Allocates memory for a new number to be added to linked list.
void	add_new_num(t_heads *stacks, char **array, int num)
{
	t_num	*new;

	new = new_num(num);
	if (!new)
		clean_exit(stacks, array, EXIT_FAILURE, "malloc error (new_num)");
	stack_add_top(stacks->a, new);
	rotate_stack(stacks->a);
	stacks->total++;
}

/*	Takes a previously validated input and will convert it to a circular
	doubly-linked list of numbers in stack a.
*/
void	build_stack(int argc, char **argv, t_heads *stacks)
{
	int		i;
	int		n;
	char	**split;

	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			split = ft_split(argv[i], ' ');
			if (!split)
				clean_exit(stacks, NULL, 1, "malloc error (ft_split)");
			n = 0;
			while (split[n])
				add_new_num(stacks, split, ft_atoi(split[n++]));
			free_array(split);
		}
		else
			add_new_num(stacks, NULL, ft_atoi(argv[i]));
	}
	if (check_duplicates(stacks->a))
		clean_exit(stacks, NULL, EXIT_FAILURE, "Error");
	set_position_values(stacks->a);
	stacks->inversions = count_inv(stacks->a);
}
