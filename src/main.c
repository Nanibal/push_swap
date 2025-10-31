/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-29 09:36:27 by nayala            #+#    #+#             */
/*   Updated: 2025-10-29 09:36:27 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static void	clean_exit(t_stack **a, t_stack **b, int exit_code)
{
	if (a && *a)
		stack_clear(a);
	if (b && *b)
		stack_clear(b);
	if (exit_code == 1)
		write(2, "Error\n", 6);
	exit(exit_code);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	if (!a || check_duplicates(a))
		clean_exit(&a, &b, 1);
	if (is_sorted(a))
		clean_exit(&a, &b, 0);
	assign_indexes(a);
	sort_stack(&a, &b);
	clean_exit(&a, &b, 0);
	return (0);
}
