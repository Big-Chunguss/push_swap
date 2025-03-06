/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:37:30 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/06 12:14:32 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_list *stack)
{
	if (NULL == stack)
		return (true);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}
 t_list	*ft_max(t_list *stack)
{
	int				highest;
	t_list	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->data > highest)
		{
			highest = stack->data;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_list	*ft_min(t_list *stack)
{
	int				lowest;
	t_list	*lowest_node;

	if (NULL == stack)
		return (NULL);
	lowest = INT_MAX;
	while (stack)
	{
		if (stack->data < lowest)
		{
			lowest = stack->data;
			lowest_node = stack;
		}
		stack = stack->next;
	}
	return (lowest_node);
}

void ez_sort(t_list **head)
{
    t_list *max;

    max = ft_max(*head);
    
    if (*head == max)
        rra(head);
    else if ((*head)->next == max)
        ra(head);
    if ((*head)->data > (*head)->next->data)
        swap_a(head);
}