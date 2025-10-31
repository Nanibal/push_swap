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
#include "../includes/push_swap.h"

static void	push_to_b(t_stack **a, t_stack **b, int chunk_size, int chunk_num)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		if ((*a)->index <= chunk_num * chunk_size)
		{
			pb(a, b, 1);
			if ((*b)->index < chunk_num * chunk_size - (chunk_size / 2))
				rb(b, 1);
		}
		else
			ra(a, 1);
		i++;
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max_pos;

	while (*b)
	{
		max_pos = get_position(*b, get_max_index(*b));
		rotate_to_top(b, max_pos, 'b');
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
		num_chunks = 5;
	else
		num_chunks = 11;
	chunk_size = size / num_chunks;
	chunk_num = 1;
	while (chunk_num <= num_chunks)
	{
		push_to_b(a, b, chunk_size, chunk_num);
		chunk_num++;
	}
	while (*a)
		pb(a, b, 1);
	push_back_to_a(a, b);
}
