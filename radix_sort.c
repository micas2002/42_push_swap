/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:34:58 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/26 11:29:28 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int	n_bits;
	int	n_numbers;
	int	i;
	int	x;

	n_numbers = argc - 2;
	n_bits = 0;
	while ((n_numbers >> n_bits) != 0)
		n_bits++;
	i = 0;
	while (i < n_bits && is_sorted(*stack_a) == 0)
	{
		x = 0;
		while (x < argc - 1 && *stack_a)
		{
			if ((((*stack_a)->order >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			x++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
