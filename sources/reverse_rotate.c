/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:08:27 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/24 14:13:05 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stackbefore_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*mem;

	mem = stackbefore_last(*stack);
	tmp = lstlast(*stack);
	mem->next = NULL;
	tmp->next = (*stack);
	(*stack) = tmp;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	printf("%s\n", "rra");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	printf("%s\n", "rrb");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	printf("%s\n", "rrr");
}
