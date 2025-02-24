/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:40:40 by agaroux           #+#    #+#             */
/*   Updated: 2025/02/22 17:48:25 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(t_list **head_a, t_list **head_b)
{
    t_list *tmp;
    
    if (!*head_b)
        return;
    if (!*head_a)
    {
        head_a = head_b;
        tmp = (*head_b)->next;
        tmp->previous = NULL;
        (*head_b) = tmp;
    }
}