/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:25:57 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/26 14:26:32 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_heads	*stacks;

	if (argc == 1)
		return (0);
	if (!input_valid(argc, argv))
		clean_exit(NULL, NULL, EXIT_FAILURE, "Error");
	stacks = init_stacks();
	build_stack(argc, argv, stacks);
	if (stacks->total < 250)
		shazam_sort(stacks);
	else
		push_slice(stacks);
	clean_exit(stacks, NULL, EXIT_SUCCESS, NULL);
}
