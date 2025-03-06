/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:06:11 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/05 18:17:29 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void r_rotate(t_list **head)
{
	t_list	*last;
	int				len;

	len = len_stack(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	last = ft_lstlast(*head);
	last->previous->next = NULL;
	last->next = *head;
	last->previous = NULL;
	*head = last;
	last->next->previous = last;
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

void r_rotate_2(t_list **head_a, t_list **head_b)
{
    r_rotate(head_a);
    r_rotate(head_b);
    write(1, "rrr\n", 4);
}