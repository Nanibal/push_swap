/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-29 11:29:23 by nayala            #+#    #+#             */
/*   Updated: 2025-10-29 11:29:23 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	get_min_index(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

int	get_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == index)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

void	rotate_to_top(t_stack **stack, int position, char stack_name)
{
	int	size;
	int	i;

	size = stack_size(*stack);
	if (position <= size / 2)
	{
		i = 0;
		while (i < position)
		{
			if (stack_name == 'a')
				ra(stack, 1);
			else
				rb(stack, 1);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - position)
		{
			if (stack_name == 'a')
				rra(stack, 1);
			else
				rrb(stack, 1);
			i++;
		}
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		sort_big(a, b);
}