/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:56:23 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/05 18:00:44 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_list **head)
{
    t_list *old_head;
    t_list *last;
    
    if (!*head || !(*head)->next)
        return;
    old_head = *head;
    *head = old_head->next;
    (*head)->previous = NULL;
    last = old_head;
    while (last->next)
        last = last->next;
    last->next = old_head;
    old_head->previous = last;
    old_head->next = NULL;
}

void ra(t_list **head)
{
    rotate(head);
    write(1, "ra\n", 3);
}

void rb(t_list **head)
{
    rotate(head);
    write(1, "rb\n", 3);
}

void rotate_2(t_list **head_a, t_list **head_b)
{
    rotate(head_a);
    rotate(head_b);
    write(1, "rr\n", 3);
}