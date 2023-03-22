/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:09:06 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/27 13:39:00 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*memory;

	temp = *stack_a;
	while (temp)
	{
		memory = temp->next;
		free(temp);
		temp = memory;
	}
}

void	sorting(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int	stack_size;

	stack_size = (argc - 1);
	if (is_sorted(*stack_a) == 1)
		return ;
	if (stack_size == 2)
		sa(stack_a);
	else if (stack_size == 3)
		sort_3(stack_a);
	else if (stack_size == 4)
		sort_4(stack_a, stack_b);
	else if (stack_size == 5)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, argc);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (error_check(argc, argv) == 0)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_stack(argc, argv);
	sorting(&stack_a, &stack_b, argc);
	free_stacks(&stack_a);
	return (0);
}
