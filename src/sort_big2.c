/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-31 11:29:44 by nayala            #+#    #+#             */
/*   Updated: 2025-10-31 11:29:44 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static void	push_to_b(t_stack **a, t_stack **b, int size)
{
	int	chunk;
	int	pushed;
	int	i;

	if (size <= 100)
		chunk = size / 3;
	else
		chunk = size / 8;
	pushed = 0;
	while (*a)
	{
		i = 0;
		while (i < size && *a)
		{
			if ((*a)->index <= pushed)
			{
				pb(a, b, 1);
				pushed++;
			}
			else if ((*a)->index <= pushed + chunk)
			{
				pb(a, b, 1);
				if ((*b) && (*b)->next)
					rb(b, 1);
				pushed++;
			}
			else
				ra(a, 1);
			i++;
		}
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max_index;
	int	max_pos;

	while (*b)
	{
		max_index = get_max_index(*b);
		max_pos = get_position(*b, max_index);
		if (max_pos == 0)
			pa(a, b, 1);
		else if (max_pos <= stack_size(*b) / 2)
		{
			while ((*b)->index != max_index)
				rb(b, 1);
			pa(a, b, 1);
		}
		else
		{
			while ((*b)->index != max_index)
				rrb(b, 1);
			pa(a, b, 1);
		}
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	push_to_b(a, b, size);
	push_back_to_a(a, b);
}