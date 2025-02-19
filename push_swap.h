/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 07:23:05 by restevez          #+#    #+#             */
/*   Updated: 2025/02/16 23:33:21 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct i_list
{
	int		n;
	i_list	*prev;
	i_list	*next;
	size_t	target;
}	t_stack;

typedef struct push_swap
{
	/* Stack A */
	t_stack	*a_top;
	t_stack	*a_pre_top;
	t_stack	*a_bot;
	t_stack	*a_mid;
	/* Stack B */
	t_stack	*b_top;
	t_stack	*b_pre_top;
	t_stack	*b_bot;
	t_stack	*b_mid;
}	t_push_swap;



#endif