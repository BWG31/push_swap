/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:42:18 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/16 15:59:08 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Checks if a number given as a string of characters is a valid integer.
	Will allow for whitespace and one + or - symbol to preceed the number.
	Returns 1 if valid, otherwise returns 0. */
static int	valid_int(char *str)
{
	int		sign;
	long	n;

	sign = 1;
	n = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	if (!ft_isdigit(*str))
		return (0);
	while (*str && ft_isdigit(*str))
	{
		n = n * 10 + (*str - '0');
		if ((sign == 1 && (n > INT_MAX)) || (sign == -1 && (-n < INT_MIN)))
			return (0);
		str++;
	}
	if (*str)
		return (0);
	return (1);
}

/*	Checks if the string given can be split into valid integers with only spaces
	used as seperators. Returns 1 if valid, otherwise returns 0. */
static int	valid_str(char *str)
{
	char	**split;
	int		i;

	split = ft_split(str, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
		if (!valid_int(split[i++]))
			return (free_array(split));
	return (free_array(split) + 1);
}

/* Checks that the input arguments are valid within the scope of the program. */
int	input_valid(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (!valid_str(argv[i]))
				return (0);
		}
		else if (!valid_int(argv[i]))
			return (0);
	}
	return (1);
}

/*	Checks the given stack of numbers for any duplicate numbers.
	Returns 1 if any duplicates found, otherwise returns 0. */
int	check_duplicates(t_stack *stack)
{
	t_num	*a;
	t_num	*b;
	size_t	x;
	size_t	y;

	a = stack->start;
	x = 0;
	while (x < stack->size - 1)
	{
		b = a->next;
		y = x + 1;
		while (y < stack->size)
		{
			if (a->n == b->n)
				return (1);
			b = b->next;
			y++;
		}
		a = a->next;
		x++;
	}
	return (0);
}
