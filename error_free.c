/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:13:33 by agaroux           #+#    #+#             */
/*   Updated: 2025/02/24 14:01:15 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_matrix(char **argv)
{
    int i;

    i = -1;
    if (!argv || *argv)
        return;
    while (argv[i])
            free(argv[i++]);
    free(argv -1);
}

void free_stack(t_list **stack)
{
    t_list *tmp;
    t_list *current;

    if (!stack)
        return;
    current = *stack;
    while (current)
        {
            tmp = current->next;
            free(current);
            current = tmp;
        }
    *stack = NULL;
}

void error_free(t_list **stack, char **argv, bool flag_argc_2)
{
    free_stack(stack);
    if (flag_argc_2)
        free_matrix(argv);
    write(2, "Error\n", 6);
}