/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:26:24 by restevez          #+#    #+#             */
/*   Updated: 2025/02/21 07:57:14 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stack *b, int n)
{
	while (b->next)
		b = b->next;
	append_stack(&b, n);
	return ;
}
/* 
void	ft_sb(t_stack *b)
{
	return ;
}

void	ft_rb(t_stack *b)
{
	return ;
}

void	ft_rrb(t_stack *b)
{
	return ;
}
 */