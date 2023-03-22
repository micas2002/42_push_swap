/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:02:29 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/26 14:34:57 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_order(int *temp, int argc)
{
	int	tmp;
	int	*nums_order;
	int	i;
	int	e;

	i = -1;
	nums_order = malloc(sizeof(int) * (argc - 1));
	if (!nums_order)
		return (NULL);
	while (++i < (argc - 1))
	{
		e = -1;
		tmp = 0;
		while (++e < (argc - 1))
		{
			if (e != i && temp[e] < temp[i])
				tmp++;
		}
		nums_order[i] = tmp;
	}
	return (nums_order);
}

t_stack	*create_stack(int data, int order)
{
	t_stack	*head;
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return (NULL);
	head = NULL;
	temp->data = data;
	temp->next = NULL;
	temp->order = order;
	temp->previous = NULL;
	head = temp;
	return (head);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*node;
	t_stack	*temp_stack;
	int		*order;
	int		*temp;
	int		i;

	temp = malloc(sizeof(int) * (argc));
	if (!temp)
		return (NULL);
	i = 0;
	while (argv[++i])
		temp[i - 1] = ft_atoi(argv[i]);
	temp_stack = NULL;
	i = -1;
	order = get_order(temp, argc);
	while (++i < (argc - 1))
	{
		node = create_stack(temp[i], order[i]);
		lstadd_back(&temp_stack, node);
	}
	free(temp);
	free(order);
	return (temp_stack);
}
