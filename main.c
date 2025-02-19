/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 07:23:09 by restevez          #+#    #+#             */
/*   Updated: 2025/02/18 21:55:14 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	if (!(argc > 1))
		return (1);
	while (argv[++i])
		append_stack(&a, ft_itoa(argv[i]));
	return (0);
}

void	append_stack(t_stack **stack, int n)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{

	}
}