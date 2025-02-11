/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:40:40 by agaroux           #+#    #+#             */
/*   Updated: 2025/02/11 17:03:18 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(struct node **head_a, struct node **head_b)
{
    struct node *tmp;
    
    if (!*head_b)
        return;
    if (!*head_a)
    {
        head_a = *head_b;
        tmp = (*head_b)->next;
        tmp->previous = NULL;
        (*head_b) = tmp;
    }
}