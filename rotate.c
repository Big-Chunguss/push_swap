/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:56:23 by agaroux           #+#    #+#             */
/*   Updated: 2025/02/11 14:58:03 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(struct node **head)
{
    struct node *tail;
    
    if ( !*head || !(*head)->next)
        return;
    tail = *head;
    while (tail->next)
           tail = tail->next;
    tail->previous->next = NULL; // Detach the last node from its previous node
    tail->previous = NULL;       // Update the last node's prev pointer
    tail->next = *head;      // Point the last node's next to the current head
    (*head)->previous = tail;    // Update the current head's prev pointer
    *head = tail;            // Update head to point to the new head (last node)
}

void ra(struct node **head)
{
    rotate(head);
    write(1, "ra\n", 3);
}

void rb(struct node **head)
{
    rotate(head);
    write(1, "rb\n", 3);
}

void rr(struct node **head_a, struct node **head_b)
{
    rotate(head_a);
    rotate(head_b);
    write(1, "rr\n", 3);
}