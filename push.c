/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:40:40 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/03 15:27:42 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_list **dst, t_list **src)
{
    t_list *node_to_push;
    
    if (!*src)
        return;
    node_to_push = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->previous = NULL;
    node_to_push->previous = NULL;
    if (!*dst)
    {
        *dst = node_to_push;
        node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = *dst;
        node_to_push->next->previous = node_to_push;
        *dst = node_to_push;
    }
}

void push_a(t_list **a, t_list **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}
void push_b(t_list **b, t_list **a)
{
    push(b, a);
    write(1, "pb\n", 3);
}