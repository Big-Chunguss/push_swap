/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:37:22 by agaroux           #+#    #+#             */
/*   Updated: 2025/02/11 16:35:26 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(struct node **head)
{
    struct node *new_head;
    struct node *tmp;
    
    if (!*head || !(*head)->next)
        return;
    new_head = (*head)->next;
    tmp = new_head->next;
    new_head->previous = NULL;
    new_head->next = *head;
    (*head)->previous = new_head;
    (*head)->next = tmp;
    if (tmp)
        tmp->previous = *head;
    *head = new_head;
}

void swap_a(struct node **head)
{
    swap(head);
    write(1, "sa\n", 3);
}
void swap_b(struct node **head)
{
    swap(head);
    write(1, "sb\n", 3);
}

void swap_both(struct node **head_a, struct node **head_b)
{
    swap(head_a);
    swap(head_b);
    write(1, "ss\n", 3);
}