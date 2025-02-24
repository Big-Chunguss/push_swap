/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:37:30 by agaroux           #+#    #+#             */
/*   Updated: 2025/02/24 15:53:31 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ez_sort(t_list **head)
{
    t_list *max;

    max = ft_max(*head);
    
    if (*head == max)
        rra(head);
    else if ((*head)->next == max)
        ra(head);
    if ((*head)->data > (*head)->next->data)
        swap_a(head);
}