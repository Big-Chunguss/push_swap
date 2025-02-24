/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:06:11 by agaroux           #+#    #+#             */
/*   Updated: 2025/02/24 15:07:39 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void r_rotate(t_list **head)
{
    t_list *tail;
    t_list *temp;
    
    if ( !*head || !(*head)->next)
        return;
    tail = *head;
    *head = (*head)->next;
    (*head)->previous = NULL;
    temp = *head;
    while (temp->next)
           temp = temp->next;
    temp->next = tail;
    tail->previous = temp;
    tail->next = NULL;
}

void rra(t_list **head)
{
    r_rotate(head);
    write(1, "rra\n", 4);
}

void rrb(t_list **head)
{
    r_rotate(head);
    write(1, "rrb\n", 4);
}

void rrr(t_list **head_a, t_list **head_b)
{
    r_rotate(head_a);
    r_rotate(head_b);
    write(1, "rrr\n", 4);
}