/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:37:22 by agaroux           #+#    #+#             */
/*   Updated: 2025/02/22 16:50:16 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_list **head)
{
    t_list *new_head;
    t_list *tmp;
    
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

void swap_a(t_list **head)
{
    swap(head);
    write(1, "sa\n", 3);
}
void swap_b(t_list **head)
{
    swap(head);
    write(1, "sb\n", 3);
}

void swap_both(t_list **head_a, t_list **head_b)
{
    swap(head_a);
    swap(head_b);
    write(1, "ss\n", 3);
}