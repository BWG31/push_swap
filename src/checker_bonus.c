/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:53:28 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/18 10:29:50 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_instruction(char *line, t_heads *stacks)
{
	if (!ft_strcmp(line, "sa\n"))
		return (swap_top_two(stacks->a));
	else if (!ft_strcmp(line, "sb\n"))
		return (swap_top_two(stacks->b));
	else if (!ft_strcmp(line, "ss\n"))
		return (swap_top_two(stacks->a) + swap_top_two(stacks->b));
	else if (!ft_strcmp(line, "pa\n"))
		return (push(stacks->b, stacks->a));
	else if (!ft_strcmp(line, "pb\n"))
		return (push(stacks->a, stacks->b));
	else if (!ft_strcmp(line, "ra\n"))
		return (rotate_stack(stacks->a));
	else if (!ft_strcmp(line, "rb\n"))
		return (rotate_stack(stacks->b));
	else if (!ft_strcmp(line, "rr\n"))
		return (rotate_stack(stacks->a) + rotate_stack(stacks->b));
	else if (!ft_strcmp(line, "rra\n"))
		return (rev_rotate_stack(stacks->a));
	else if (!ft_strcmp(line, "rrb\n"))
		return (rev_rotate_stack(stacks->b));
	else if (!ft_strcmp(line, "rrr\n"))
		return (rev_rotate_stack(stacks->a) + rev_rotate_stack(stacks->b));
	else
		return (0);
}

static int	execute_instructions(t_heads *stacks)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!run_instruction(line, stacks))
		{
			free(line);
			clean_exit(stacks, NULL, EXIT_FAILURE, "Error");
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (count_inv(stacks->a) || stacks->b->size)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_heads	*stacks;

	if (argc == 1)
		return (0);
	if (!input_valid(argc, argv))
		clean_exit(NULL, NULL, EXIT_FAILURE, "Error");
	stacks = init_stacks();
	build_stack(argc, argv, stacks);
	if (execute_instructions(stacks))
		ft_putendl_fd("KO", STDOUT_FILENO);
	else
		ft_putendl_fd("OK", STDOUT_FILENO);
	clean_exit(stacks, NULL, EXIT_SUCCESS, NULL);
	return (0);
}
