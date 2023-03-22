/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:10:55 by mibernar          #+#    #+#             */
/*   Updated: 2022/05/27 13:40:28 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

// PROTOTYPES

typedef struct s_stack
{
	int				data;
	int				order;
	struct s_stack	*next;
	struct s_stack	*previous;
}t_stack;

int		error_check(int argc, char **argv);
t_stack	*init_stack(int argc, char **argv);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	lstadd_back(t_stack **stack, t_stack *node);
void	lstadd_front(t_stack **stack_receiver, t_stack *stack_sender);
t_stack	*cpy_stack(t_stack *stack);
void	del_one(t_stack **stack_sender);
t_stack	*lstlast(t_stack *lst);
t_stack	*create_stack(int data, int order);
int		is_sorted(t_stack *stack);
void	sort_3(t_stack **stack);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, int argc);

#endif