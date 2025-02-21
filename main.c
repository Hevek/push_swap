/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 07:23:09 by restevez          #+#    #+#             */
/*   Updated: 2025/02/21 08:02:13 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	a = NULL;
	if (!(argc > 1))
		return (1);
	while (++i < argc)
		append_stack(&a, ft_atoi((const char *) argv[i]));
	ft_pb(b, a->n);
	while (b)
	{
		printf("%p: %d\n", &b, b->n);
		b = b->next;
	}
	return (0);
}

void	append_stack(t_stack **stack, int n)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = *stack;
	if (tmp == NULL)
	{
		(*stack) = (t_stack *) ft_calloc(sizeof(t_stack), 1);
		(*stack)->n = n;
		(*stack)->next = NULL;
		(*stack)->target = 0;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	new = (t_stack *) ft_calloc(sizeof(t_stack), 1);
	new->n = n;
	new->next = NULL;
	new->target = 0;
	new->prev = tmp;
	tmp->next = new;
}
