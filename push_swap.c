/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:06:33 by antoine           #+#    #+#             */
/*   Updated: 2025/02/24 15:32:05 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_newnode(int a)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->data = a;
    new_node->previous = NULL;
    new_node->next = NULL;

    return (new_node);
};

void ft_append(t_list **head, t_list **tail, int a)
{
    t_list *node = ft_newnode(a);
    if (!*head) //if the list is empty
        {
            *head = node;
            *tail = node;
        } else {
            (*tail)->next = node;
            node ->previous = *tail;
            *tail = node;
        }
}

void ft_displayforward(t_list *head)
{
    t_list *current = head;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void ft_displaybackward(t_list *tail)
{
    t_list *current = tail;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->previous;
    }
}

int main(int argc, char **argv)
{
    t_list *head = NULL;
    t_list *tail = NULL;
    int count;

    if (argc <= 1 || (argc == 2 && !argv[1][0]))
        return (0);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    //printf("%s", argv[1]);
    stack_init(&head, &tail, argv + 1, 2 == argc);
    ez_sort(&head);
    ft_displayforward(head);
    //ft_displaybackward(tail);
    return (0);
}
