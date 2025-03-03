/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:30:50 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/03 15:34:16 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// length of stack
int len_stack(t_list *node)
{
    int i;
    
    if (!node)
        return (0);
    i = 0;
    while (node)
        {
            node = node->next;
            i++;
        }
    return (i);
}
//find position in node and save it in final_index
void set_current_position(t_list *node)
{
    int i;
    int median;
    
    i = 0;
    if (!node)
        return;
    median = len_stack(node) / 2;
    
    while(node)
    {
        node->current_position = i;
        if (node->current_position > median)
            node->above_median = true;
        else
        node->above_median = false;
        node = node->next;
        i++;
    }
    node->final_index = i;
}

//initialization node
void	init_nodes(t_list *a, t_list *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}