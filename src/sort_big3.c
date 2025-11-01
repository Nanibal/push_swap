/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 09:21:04 by nayala            #+#    #+#             */
/*   Updated: 2025-10-30 09:21:04 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// sort_big.c - Versión optimizada
#include "../includes/push_swap.h"

static void	push_to_b(t_stack **a, t_stack **b, int chunk_size, int chunk_num)
{
	int	i;
	int	size;
	int	pushed;

	i = 0;
	pushed = 0;
	size = stack_size(*a);
	while (i < size && pushed < chunk_size)
	{
		if ((*a)->index <= chunk_num * chunk_size)
		{
			pb(a, b, 1);
			pushed++;
			if ((*b) && (*b)->next && (*b)->index < chunk_num * chunk_size - (chunk_size / 2))
				rb(b, 1);
		}
		else
			ra(a, 1);
		i++;
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max_index;
	int	max_pos;
	int	size_b;

	while (*b)
	{
		size_b = stack_size(*b);
		max_index = get_max_index(*b);
		max_pos = get_position(*b, max_index);
		
		if (max_pos <= size_b / 2)
		{
			while ((*b)->index != max_index)
				rb(b, 1);
		}
		else
		{
			while ((*b)->index != max_index)
				rrb(b, 1);
		}
		pa(a, b, 1);
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;
	int	chunk_num;
	int	num_chunks;

	size = stack_size(*a);
	if (size <= 100)
		num_chunks = 4;
	else
		num_chunks = 12;
		
	chunk_size = (size + num_chunks - 1) / num_chunks;
	chunk_num = 1;
	
	while (chunk_num <= num_chunks && *a)
	{
		push_to_b(a, b, chunk_size, chunk_num);
		chunk_num++;
	}
	while (*a)
		pb(a, b, 1);
		
	push_back_to_a(a, b);
}