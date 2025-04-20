/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:19:58 by restevez          #+#    #+#             */
/*   Updated: 2025/04/19 22:16:41 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* Functions from utils
they were changed from static to normal functions */
void	move_a_to_b(t_stack_node **a, t_stack_node **b);
void	move_b_to_a(t_stack_node **a, t_stack_node **b);
void	min_on_top(t_stack_node **a);

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

/* Define a function that sorts stack `a` if it has more than 3 nodes */
void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
