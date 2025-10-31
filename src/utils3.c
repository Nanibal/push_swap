/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-31 11:02:53 by nayala            #+#    #+#             */
/*   Updated: 2025-10-31 11:02:53 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static void	rotate_forward(t_stack **stack, int moves, char stack_name)
{
	int	i;

	i = 0;
	while (i < moves)
	{
		if (stack_name == 'a')
			ra(stack, 1);
		else
			rb(stack, 1);
		i++;
	}
}

static void	rotate_backward(t_stack **stack, int moves, char stack_name)
{
	int	i;

	i = 0;
	while (i < moves)
	{
		if (stack_name == 'a')
			rra(stack, 1);
		else
			rrb(stack, 1);
		i++;
	}
}

void	rotate_to_top(t_stack **stack, int position, char stack_name)
{
	int	size;

	size = stack_size(*stack);
	if (position <= size / 2)
	{
		rotate_forward(stack, position, stack_name);
	}
	else
	{
		rotate_backward(stack, size - position, stack_name);
	}
}
