/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:42:23 by antoine           #+#    #+#             */
/*   Updated: 2025/03/05 16:22:03 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void finish_rotation(t_list **head, t_list *top_node, char c)
{
    while (*head != top_node)
    {
        if (c == 'a')
        {
            if (top_node->above_median)
                ra(head);
            else
                rra(head);
        }
        if (c == 'b')
        {
            if (top_node->above_median)
                rb(head);
            else
                rrb(head);
        }
    }
}
t_list *return_cheapest(t_list *node)
{
    if (!node)
        return 0;
    while (node)
    {
        if (node->cheapest)
        {
            return (node);
        }
        node = node->next;
    }
    return 0;
}

void	move_nodes(t_list **a, t_list **b)
{
    t_list *cheapest;

    cheapest = return_cheapest(*b);
    if (cheapest->above_median && cheapest->target_node->above_median)
        rotate_both(a, b, cheapest);
    else if(!(cheapest->above_median) && !(cheapest->target_node->above_median))
        reverse_rotate_both(a, b, cheapest);
    finish_rotation(b, cheapest, 'b');
    finish_rotation(a, cheapest->target_node, 'a');
    push_a(a, b);
}