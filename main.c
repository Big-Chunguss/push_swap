/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:06:33 by antoine           #+#    #+#             */
/*   Updated: 2025/03/03 15:32:00 by agaroux          ###   ########.fr       */
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

void ft_append(t_list **head, int i)
{
    t_list *node;
    t_list *last_node;
    
    if (!*head)//if the list is empty
        return; 
    node = ft_newnode(i);
    if  (!node)
        return;
    node->next = NULL;
    node->data = i;
    if (!*head)
    {
      *head = node;
      node->previous = NULL;
    } 
    else 
    {
            last_node = ft_lstlast(*head);
            last_node->next = node;
            node->previous = last_node;
    }
}

void ft_displayforward(t_list *a)
{
    t_list *current = a;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void ft_displaybackward(t_list *b)
{
    t_list *current = b;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->previous;
    }
}

int main(int argc, char **argv)
{
    t_list *a = NULL;
    t_list *b = NULL;
    int count;

    if (argc <= 1 || (argc == 2 && !argv[1][0]))
        return (0);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    //printf("%s", argv[1]);
    stack_init(&a, argv + 1, 2 == argc);
    if (!stack_sorted(a))
    {
        if(len_stack(a) == 2)
            swap_a(a);
        else if (len_stack(a) == 3)
            ez_sort(a);
        else
            push_swap(a, b);
    }
    //ez_sort(&a);
    ft_displayforward(a);
    //ft_displaybackward(b);
    return (0);
}
