/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:27:24 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/19 16:11:19 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*cpy_stack(t_stack *stack)
{
	t_stack	*head;
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return (NULL);
	head = NULL;
	while (stack->next)
	{
		temp->data = stack->data;
		temp = temp->next;
		stack = stack->next;
	}
	head = temp;
	return (head);
}

void	lstadd_front(t_stack **stack_receiver, t_stack *stack_sender)
{
	stack_sender->next = (*stack_receiver);
	*stack_receiver = stack_sender;
}

void	lstadd_back(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (*stack)
	{
		last = lstlast(*stack);
		last->next = node;
		node->previous = last;
	}
	else
		*stack = node;
}

t_stack	*lstlast(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	del_one(t_stack **stack_sender)
{
	t_stack	*temp;

	temp = *stack_sender;
	if (temp)
		*stack_sender = temp->next;
}
