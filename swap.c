/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:37:22 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/05 16:36:28 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head)
{
	int	len;

	len = len_stack(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->previous->previous = *head;
	(*head)->previous->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->previous = (*head)->previous;
	(*head)->next = (*head)->previous;
	(*head)->previous = NULL;
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