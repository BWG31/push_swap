/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:07:30 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/26 14:49:25 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# define SLICE (3)

typedef struct s_num
{
	int				n;
	size_t			pos;
	struct s_num	*next;
	struct s_num	*prev;
}					t_num;

typedef struct s_stack
{
	t_num	*start;
	size_t	size;
}			t_stack;

typedef struct s_heads
{
	t_stack	*a;
	t_stack	*b;
	size_t	total;
	size_t	inversions;
}			t_heads;

typedef struct s_range
{
	size_t	ceiling;
	size_t	range;
	size_t	max;
	size_t	mid;
	size_t	min;
	size_t	top_count;
	size_t	bot_count;
}			t_range;

typedef struct s_index
{
	int	a;
	int	b;
}		t_index;

// cleaners
void	free_stack(t_stack *stack);
int		free_array(char **array);
void	clean_exit(t_heads *stacks, char **array, int exit_code, char *err_msg);
// instructions_1
int		swap_a(t_heads *stacks);
int		swap_b(t_heads *stacks);
int		swap_ab(t_heads *stacks);
int		push_a(t_heads *stacks);
int		push_b(t_heads *stacks);
// instructions_2
int		rotate_a(t_heads *stacks);
int		rotate_b(t_heads *stacks);
int		rotate_ab(t_heads *stacks);
// instructions_3
int		rev_rotate_a(t_heads *stacks);
int		rev_rotate_b(t_heads *stacks);
int		rev_rotate_ab(t_heads *stacks);
// stack_utils_1
t_heads	*init_stacks(void);
t_stack	*new_stack(t_heads *stacks);
t_num	*new_num(int num);
void	add_new_num(t_heads *stacks, char **array, int num);
void	build_stack(int argc, char **argv, t_heads *stacks);
// stack_utils_2
int		rotate_stack(t_stack *stack);
int		rev_rotate_stack(t_stack *stack);
int		push(t_stack *from, t_stack *to);
int		swap_top_two(t_stack *stack);
// stack_utils_3
void	stack_add_top(t_stack *stack, t_num *new);
void	stack_pop_top(t_stack *stack);
int		count_inv(t_stack *stack);
void	set_position_values(t_stack *stack);
// input_check
int		input_valid(int argc, char **argv);
int		check_duplicates(t_stack *stack);
// shazam_sort
void	shazam_sort(t_heads *stacks);
void	filter_back(t_heads *stacks, t_stack *a, t_stack *b);
// shazam_sort_utils
size_t	pos(t_stack *stack, int i);
int		in_range(size_t pos, size_t min, size_t max);
t_range	*set_range(size_t total);
void	update_range(t_range *b);
// mini_sort
void	mini_sort(t_heads *stacks, t_stack *a, t_stack *b);
void	sort_a(t_heads *stacks, t_stack *a);
void	rev_sort_b(t_heads *stacks, t_stack *b);
// push_slice
void	push_slice(t_heads *stacks);
// push_slice_utils
int		ft_abs(int n);
int		set_indices(int *indices, int index_a, int index_b);
void	run_instructions(t_heads *stacks, int *indices);

#endif