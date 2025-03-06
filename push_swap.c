/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:30:50 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/06 10:48:15 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// length of stack

void	rotate_both(t_list **a,
    t_list **b,
    t_list *cheapest_node)
{
while (*a != cheapest_node->target_node
&& *b != cheapest_node)
rotate_2(a, b);
set_current_position(*a);
set_current_position(*b);
}

void	reverse_rotate_both(t_list **a,
            t_list **b,
            t_list *cheapest_node)
{
while (*a != cheapest_node->target_node
&& *b != cheapest_node)
r_rotate_2(a, b);
set_current_position(*a);
set_current_position(*b);
}
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
        if (i > median)
            node->above_median = true;
        else
            node->above_median = false;
        node = node->next;
        i++;
    }
}

void set_target_node(t_list *a, t_list *b)
{
    t_list *start;
    t_list *target;
    long match_index;

    while (b)
    {
        match_index = LONG_MAX;
        start = a;
        while(start)
        {
            if (start->data > b->data && start->data < match_index)
            {
                match_index = start->data;
                target = start;
            }
            start = start->next;
        }
        if (LONG_MAX == match_index)
        b->target_node = ft_min(a);
        else
        b->target_node = target;
        b = b->next;
    }
}
//calculate price to push
void set_price(t_list *a, t_list *b)
{
    int len_a;
    int len_b;

    len_a = len_stack(a);
    len_b = len_stack(b);
    while (b)
        {
            
            b->push_price = b->current_position;
            if (b->above_median)
                b->push_price = len_b - (b->current_position);
            if (b->target_node->above_median)
                b->push_price += len_a - (b->target_node->current_position);
            else
                b->push_price += b->target_node->current_position;
            b = b->next;
        }
}

void set_cheapest(t_list *b)
{
    t_list *to_push;
    long cheapest;
    
    cheapest = LONG_MAX;
    while (b)
    {
        if (b->push_price < cheapest)
            {
                cheapest = b->push_price;
                to_push = b;
            }
        b = b->next;
    }
    to_push->cheapest = true;
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

void	push_swap(t_list **a, t_list **b)
{
    t_list *small;
    int len_a;

    len_a = len_stack(*a);
    while (len_a-- > 3)
        push_b(b, a);
    ez_sort(a);
    while (*b)
    {   
        init_nodes(*a, *b);
        move_nodes(a, b);
    }
    set_current_position(*a);
    small = ft_min(*a);
    if (small->above_median)
        while (*a != small)
            rra(a);
    else
        while (*a != small)
            ra(a);
}